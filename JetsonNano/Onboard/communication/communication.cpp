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

#include "communication.h"

extern "C" {
    #include "communicationBLT.h"
}



// Private (local function).
int CreateMessageQueues(mqd_t *messageQueueMain, mqd_t *messageQueueMotors, mqd_t *messageQueueDistance, mqdt_t *messageQueueNucleo );


// Main function for communication.
void communicationHandler()
{

    // Initate message queue
    int mainMessageBuffer;
    mqd_t messageQueueMain,messageQueueMotors,messageQueueDistance,messageQueueNucleo;

    // Create all message queue.
    CreateMessageQueues(&messageQueueMain, &messageQueueMotors, &messageQueueDistance, &messageQueueNucleo );


    // Set up I2C
//    setupI2C();

    // Set up bluetooth
    setupBluetooth();


    // Startup bluetooth receive thread.
    pthread_attr_t attrBluetooth;
    pthread_t threadIDBluetooth;
    threadCommander = 0;

    pthread_attr_init(&attrBluetooth);
    pthread_create(&threadIDBluetooth, &attrBluetooth,(void*) &receiveBluetoothMessages, (void*)&threadCommander);
/*
    // Startup I2C receive thread.
    pthread_attr_t attrI2C;
    pthread_t threadIDI2C;
    threadCommander = 0;

    pthread_attr_init(&attrI2C);
    pthread_create(&threadIDI2C, &attrI2C,(void*) &I2CReceiveHandler, (void*)&threadCommander);
*/

    // Communication setup done.

    // TempSave
    char I2CBufferToSend[1024];

    messageStructHeaderFromNano I2CHeaderToNucleo;

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
    */

    while(1)
    {

        if( mq_receive(messageQueueMain, (char *) &mainMessageBuffer, messageMainQueueSize,NULL)==0 ){
            
            switch(taskToDo)
            {
                case 1:
                {

                }
                break;

                case 4:
                {

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
                    // writeI2C( &I2CHeaderToNucleo, sizeof(messageStructHeaderFromNano) );
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
                    // writeI2C( &I2CHeaderToNucleo, sizeof(messageStructHeaderFromNano) );
                }
                break;

                default:{

                }
                break;
            }

        }

    }



    infoFrameFromNano.frameType = 1;//(counter%3)+1;

    writeI2C((unsigned char *) &infoFrameFromNano, sizeof(messageStructHeaderFromNano) );

    printf("Wrote I2C message: %d\n",writeSize);
    fflush(stdout);

}



    // Creates message queues.
    // Create main message queue.
    int mainMessageBuffer;
    mqd_t messageQueueMain,messageQueueMotors;
 
    //messageQueueMain = mq_open(messageMainQueueNano, O_RDWR);
    
    if( messageQueueMain == (mqd_t) -1){
		printf("Failed to open main message queue.\n");
	}

    // Create motor message queue.
    //messageQueueMotors = mq_open(messageQueueMotorEvent, O_RDWR);

    if( messageQueueMotors == (mqd_t) -1){
		printf("Failed to open main message queue.\n");
	}





int CreateMessageQueues(mqd_t *messageQueueMain, mqd_t *messageQueueMotors, mqd_t *messageQueueDistance, mqdt_t *messageQueueNucleo )
{
    // Creates a mailslot with the specified name. Return 0 on success and 1 on failure.

    // Set size and number of messages properties.
	struct mq_attr mainAttr;
    struct mq_attr  motorAttr;

	mainAttr.mq_maxmsg = 10;
	mainAttr.mq_msgsize = messageMainQueueSize;

    motorAttr.mq_maxmsg = 10;
	motorAttr.mq_msgsize = sizeof(messageI2CToNucleoMotor);

    distanceAttr.mq_maxmsg = 10;
	distanceAttr.mq_msgsize = NUMBER_OF_PROXIMITY_SENSORS*sizeof(unsigned char); /* Change to the correct size of the proximity sensor. */

    distanceAttr.mq_maxmsg = 10;
	distanceAttr.mq_msgsize = sizeof(messageStructFromNucleo);

    // Open main message queue.
	*messageQueueMain = mq_open(messageMainQueueName, O_CREAT , 0666, &mainAttr);

    // Open motor message queue.
	*messageQueueMotors = mq_open(messageQueueMotorName, O_CREAT , 0666, &motorAttr);

    // Open distance message queue.
	*messageQueueDistance = mq_open(messageQueueDistanceName, O_CREAT , 0666, &distanceAttr);

    // Open distance message queue.
	*messageQueueNucleo = mq_open(messageQueueNucleoName, O_CREAT , 0666, &distanceAttr);

	if( (*messageQueueMain == (mqd_t)-1) || (*messageQueueMotors == (mqd_t)-1) || (*messageQueueDistance == (mqd_t)-1) || (*messageQueueNucleo == (mqd_t)-1) )
    {
		printf("Fail to create message queues. \n");
		return 1;
	}
	return 0;
}



