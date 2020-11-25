#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>

#include <sys/stat.h>
#include <sys/select.h>

#include <sys/time.h>

#include <mqueue.h>
#include <pthread.h>

#include <cstring>

#include "communication.h"
#include "communicationI2C.h"

extern "C" {
    #include "communicationBLT.h"
}



// Private (local function).
int CreateMessageQueues(mqd_t *messageQueueMain, mqd_t *messageQueueMotors, mqd_t *messageQueueDistance, mqd_t *messageQueueNucleo );


// Main function for communication.
void communicationHandler()
{

    // Initate message queue
    int mainMessageBuffer;
    mqd_t messageQueueMain,messageQueueMotors,messageQueueDistance,messageQueueNucleo;

    // Create all message queue.
    CreateMessageQueues(&messageQueueMain, &messageQueueMotors, &messageQueueDistance, &messageQueueNucleo );


    // Set up I2C
    setupI2C();

    // Set up bluetooth
    setupBluetooth();


    // Startup bluetooth receive thread.
    pthread_attr_t attrBluetooth;
    pthread_t threadIDBluetooth;

    int receiveCommander = 0;

    pthread_attr_init(&attrBluetooth);
    pthread_create(&threadIDBluetooth, &attrBluetooth, receiveBluetoothMessages, (void*) &receiveCommander);

    // Startup I2C receive thread.
    pthread_attr_t attrI2C;
    pthread_t threadIDI2C;

    pthread_attr_init(&attrI2C);
    pthread_create(&threadIDI2C, &attrI2C, I2CReceiveHandler, (void*) NULL);


    // Communication setup done.

    char I2CBufferToSend[1024];

    messageStructHeaderFromNano I2CHeaderToNucleo;

    unsigned char stateOfGripper = 0xFF;
    messageStructFromNucleo messageFromNucleo;

    //messageQueueMain = mq_open(messageMainQueueName, O_RDWR);

    /*
    * Defines each command on the Jetson Nano.
    * Handles all the communication, between other devices.
    *
    *   1. Send motor commands to Nucleo.
    *   2. Send start command to Nucleo.
    *   3. Send stop command to Nucleo.
    *   4. Received data from Nucleo.
    *   5. Send gripper status to bluetooth device.
    *   6. Received start command from bluetooth.
    *   7. Received stop command from bluetooth.
    *   8. User is disconnected from bluetooth.
    */

    while(1)
    {


        mq_receive(messageQueueMain, (char *) &mainMessageBuffer, messageMainQueueSize,NULL);

        printf("Communication handle received a state.\n");
        fflush(stdout);
        switch( mainMessageBuffer )
        {
            case 1:
            {

            }
            break;

            case 4:
            {
                mq_receive(messageQueueNucleo, (char *) &messageFromNucleo, sizeof(messageStructFromNucleo), NULL);

                /*
                * Send proximity data to pre-shape.
                if( mq_send(messageQueueDistance, (char*) &mainMessageBuffer, NUMBER_OF_PROXIMITY_SENSORS*sizeof(unsigned char),1) != 0 )
                {
                    printf("Failed to send distance info to pre-shape.\n");
                }
                */

                if(stateOfGripper != messageFromNucleo.statusOfNucelo)
                {
                    // Change current state of gripper.
                    stateOfGripper = messageFromNucleo.statusOfNucelo;
                    // Send the new state to bluetooth.
                    memset(I2CBufferToSend, 0, sizeof(I2CBufferToSend));
                    sprintf(I2CBufferToSend,"The griper is in state: %d \n",stateOfGripper);
                    sendBluetoothMessage( I2CBufferToSend );
                }
            }
            break;

            case 6:
            {
                // Start the Gripper

                // Make a callback to indicate that the command was received.
                memset(I2CBufferToSend, 0, sizeof(I2CBufferToSend));
                strcat(I2CBufferToSend,"Start command confirmed\n");
                sendBluetoothMessage( I2CBufferToSend );

                // Send command to Nucleo.
                I2CHeaderToNucleo.frameType = 1;
                I2CHeaderToNucleo.frameLength = 0;
                writeI2C((unsigned char*) &I2CHeaderToNucleo, sizeof(messageStructHeaderFromNano) );
            }
            break;

            case 7:
            {
                // Stop the Gripper

                // Make a callback to indicate that the command was received.
                memset(I2CBufferToSend, 0, sizeof(I2CBufferToSend));
                strcat(I2CBufferToSend,"Stop command confirmed\n");
                sendBluetoothMessage( I2CBufferToSend );

                // Send command to Nucleo.
                I2CHeaderToNucleo.frameType = 2;
                I2CHeaderToNucleo.frameLength = 0;
                writeI2C((unsigned char*) &I2CHeaderToNucleo, sizeof(messageStructHeaderFromNano) );
            }
            break;


            case 8:
            {
                // If user is disconnected stop gripper and reset bluetooth.
                // Send command to Nucleo.
                I2CHeaderToNucleo.frameType = 2;
                I2CHeaderToNucleo.frameLength = 0;
                writeI2C((unsigned char*) &I2CHeaderToNucleo, sizeof(messageStructHeaderFromNano) );

                /* ToDo: reset bluetooth correctly!  */
                receiveCommander = 1;
                pthread_join(threadIDBluetooth);
                pthread_cancel(threadIDBluetooth);

                // Reset bluetooth
                closeBluetooth();
                setupBluetooth();

                // Restart bluetooth receive thread.
                receiveCommander = 0;
                pthread_attr_init(&attrBluetooth);
                pthread_create(&threadIDBluetooth, &attrBluetooth, receiveBluetoothMessages, (void*) &receiveCommander);

            }
            break;

            default:{

            }
            break;
       }



	usleep(10000);

    }

}





int CreateMessageQueues(mqd_t *messageQueueMain, mqd_t *messageQueueMotors, mqd_t *messageQueueDistance, mqd_t *messageQueueNucleo )
{
    // Creates a mailslot with the specified name. Return 0 on success and 1 on failure.

    // Set size and number of messages properties.
	struct mq_attr mainAttr;
    struct mq_attr motorAttr;
    struct mq_attr distanceAttr;
    struct mq_attr nucleoAttr;

	mainAttr.mq_maxmsg = 10;
	mainAttr.mq_msgsize = messageMainQueueSize;

    motorAttr.mq_maxmsg = 10;
	motorAttr.mq_msgsize = sizeof(messageI2CToNucleoMotor);

    distanceAttr.mq_maxmsg = 10;
	distanceAttr.mq_msgsize = NUMBER_OF_PROXIMITY_SENSORS*sizeof(unsigned char); /* Change to the correct size of the proximity sensor. */

    nucleoAttr.mq_maxmsg = 10;
	nucleoAttr.mq_msgsize = sizeof(messageStructFromNucleo);

    // Open main message queue.
	*messageQueueMain = mq_open(messageMainQueueName, O_CREAT , 0666, &mainAttr);

    // Open motor message queue.
	*messageQueueMotors = mq_open(messageQueueMotorName, O_CREAT , 0666, &motorAttr);

    // Open distance message queue.
	*messageQueueDistance = mq_open(messageQueueDistanceName, O_CREAT , 0666, &distanceAttr);

    // Open distance message queue.
	*messageQueueNucleo = mq_open(messageQueueNucleoName, O_CREAT , 0666, &nucleoAttr);

	if( (*messageQueueMain == (mqd_t)-1) || (*messageQueueMotors == (mqd_t)-1) || (*messageQueueDistance == (mqd_t)-1) || (*messageQueueNucleo == (mqd_t)-1) )
        {
		printf("Fail to create message queues. \n");
		return 1;
	}
	return 0;
}



