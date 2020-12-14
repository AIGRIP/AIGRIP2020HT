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

#include "control.h"
#include "communication.h"
#include "communicationI2C.h"

extern "C" {
    #include "communicationBLT.h"
}



// Local function.
int CreateMessageQueues(mqd_t *messageQueueMain, mqd_t *messageQueueMotors, mqd_t *messageQueueDistance, mqd_t *messageQueueNucleo );


// Main function for communication.
void communicationHandler()
{

    // Initate message queues.
    int mainMessageBuffer;
    messageMotorStruct motorMessage;
    mqd_t messageQueueMain,messageQueueMotors,messageQueueDistance,messageQueueNucleo;

    // Create all message queues.
    CreateMessageQueues(&messageQueueMain, &messageQueueMotors, &messageQueueDistance, &messageQueueNucleo );

    // Set up bluetooth
    setupBluetooth();

    // Set up I2C
    setupI2C();

    // The communication handle can manage the following threads on the gripper.

    // Startup bluetooth receive thread.
    pthread_attr_t attrBluetooth;
    pthread_t threadIDBluetooth;

    pthread_attr_init(&attrBluetooth);
    pthread_create(&threadIDBluetooth, &attrBluetooth, receiveBluetoothMessages, (void*) NULL);

    // Startup I2C receive thread.
    pthread_attr_t attrI2C;
    pthread_t threadIDI2C;

    pthread_attr_init(&attrI2C);
    pthread_create(&threadIDI2C, &attrI2C, I2CReceiveHandler, (void*) NULL);


    // Startup control thread on Nano.
    pthread_attr_t attrControl;
    pthread_t threadIDControl;

    pthread_attr_init(&attrControl);
    pthread_create(&threadIDControl, &attrControl, controlThread, (void*) NULL);

    // Communication setup done.

    char I2CBufferToSend[1024];

    messageStructHeaderFromNano I2CHeaderToNucleo;

    unsigned char stateOfGripper = 0xFF;
    messageStructFromNucleo messageFromNucleo;

    controlData dataToControlThread;

    //messageQueueMain = mq_open(messageMainQueueName, O_RDWR);

    /*
    * Here is the command handle, it handles all the internal device.
    * Those commands below are the 
    *
    */

    while(1)
    {

        // Receive command from message main queue.
        mq_receive(messageQueueMain, (char *) &mainMessageBuffer, messageMainQueueSize,NULL);

	printf("\n\nCommunication handle received state %d \n",mainMessageBuffer);
        fflush(stdout);
        switch( mainMessageBuffer )
        {
            case SEND_MOTOR_COMMAND:
            {
                printf("Sending motor command from command handle.\n");

                // Send motor data to Nucleo.
                mq_receive(messageQueueMotors, (char *) &motorMessage, sizeof(messageMotorStruct),NULL);

                // Send command to Nucleo.
                I2CHeaderToNucleo.frameType = 5;
                I2CHeaderToNucleo.frameLength = sizeof(messageMotorStruct);
                writeI2C((unsigned char*) &I2CHeaderToNucleo, sizeof(messageStructHeaderFromNano) );
                // Send motorvalues to Nucleo.
                writeI2C((unsigned char*) &motorMessage, sizeof(messageMotorStruct) );
            }
            break;

            // Received data package from Nucleo.
            case RECEIVED_DATA_FROM_NUCLEO:
            {
                printf("Received data from Nucleo in command handle.\n");
                // Handle received message from Nucleo.
                mq_receive(messageQueueNucleo, (char *) &messageFromNucleo, sizeof(messageStructFromNucleo), NULL);

                // Copy the data for the control task.
                memcpy(&dataToControlThread.motorData.motorAngle[0],&messageFromNucleo.motorStatus.motorAngle[0],sizeof(messageMotorStruct) );
                memcpy(&dataToControlThread.distanceData.proximitySensor[0],&messageFromNucleo.proximitySensors.proximitySensor[0],sizeof(messageMotorStruct) );

                // Send proximity data to control node.
                if( mq_send(messageQueueDistance, (char*) &dataToControlThread, sizeof(controlData),1) != 0 )
                {
                    printf("Failed to send data info to control thread.\n");
                }

                // Check if the gripper has received a new state.
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

            case RECEIVED_START_COMMAND_BLUETOOTH:
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

            case RECEIVED_STOP_COMMAND_BLUETOOTH:
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


            case USER_DISCONNECTED_BLUETOOTH:
            {
                // If user is disconnected stop gripper and reset bluetooth.
                // Send command to Nucleo.

                printf("\nPhone is disconnected.\n");
                fflush(stdout);


                I2CHeaderToNucleo.frameType = 2;
                I2CHeaderToNucleo.frameLength = 0;
                writeI2C((unsigned char*) &I2CHeaderToNucleo, sizeof(messageStructHeaderFromNano) );

                printf("Stop command sent.\n");
                fflush(stdout);


                // Shut down receive thread for bluetooth.
                pthread_cancel(threadIDBluetooth);

                printf("Cancled receive thread..\n");
                fflush(stdout);

                // Reset bluetooth
                closeBluetooth();

                printf("Closed bluetooth.\n");
                fflush(stdout);

                printf("\nWaiting for new connection ...\n");
                fflush(stdout);
                setupBluetooth();

                // Restart bluetooth receive thread.
                pthread_attr_init(&attrBluetooth);
                pthread_create(&threadIDBluetooth, &attrBluetooth, receiveBluetoothMessages, (void*) NULL);

                printf("Created receive thread..\n\n");
                fflush(stdout);

            }
            break;

            case SEND_PRESHAPE_BLUETOOTH:
            {
                memset(I2CBufferToSend, 0, sizeof(I2CBufferToSend));
                strcat(I2CBufferToSend,"Gripper is in pre-shape state.\n");
                sendBluetoothMessage( I2CBufferToSend );
            }
            break;

            case SEND_APPROACH_BLUETOOTH:
            {
                memset(I2CBufferToSend, 0, sizeof(I2CBufferToSend));
                strcat(I2CBufferToSend,"Gripper is in approach state.\n");
                sendBluetoothMessage( I2CBufferToSend );
            }
            break;

            case SEND_SLIPNOT_BLUETOOTH:
            {
                memset(I2CBufferToSend, 0, sizeof(I2CBufferToSend));
                strcat(I2CBufferToSend,"Gripper is in slipnot state.\n");
                sendBluetoothMessage( I2CBufferToSend );
            }
            break;

            default:{

            }
            break;
       }



//	    usleep(10000);

    }

}





int CreateMessageQueues(mqd_t *messageQueueMain, mqd_t *messageQueueMotors, mqd_t *messageQueueControlData, mqd_t *messageQueueNucleo )
{
    // Creates a mailslot with the specified name. Return 0 on success and 1 on failure.

    // Set size and number of messages properties.
	struct mq_attr mainAttr;
    struct mq_attr motorAttr;
    struct mq_attr controlAttr;
    struct mq_attr nucleoAttr;

	mainAttr.mq_maxmsg = 10;
	mainAttr.mq_msgsize = messageMainQueueSize;

    motorAttr.mq_maxmsg = 10;
	motorAttr.mq_msgsize = sizeof(messageMotorStruct);

    controlAttr.mq_maxmsg = 10;
	controlAttr.mq_msgsize = sizeof(controlData);

    nucleoAttr.mq_maxmsg = 10;
	nucleoAttr.mq_msgsize = sizeof(messageStructFromNucleo);

    // Open main message queue.
	*messageQueueMain = mq_open(messageMainQueueName, O_CREAT , 0666, &mainAttr);

    // Open motor message queue.
	*messageQueueMotors = mq_open(messageQueueMotorName, O_CREAT , 0666, &motorAttr);

    // Open distance message queue.
	*messageQueueControlData = mq_open(messageQueueControlDataName, O_CREAT , 0666, &controlAttr);

    // Open distance message queue.
	*messageQueueNucleo = mq_open(messageQueueNucleoName, O_CREAT , 0666, &nucleoAttr);

	if( (*messageQueueMain == (mqd_t)-1) || (*messageQueueMotors == (mqd_t)-1) || (*messageQueueControlData == (mqd_t)-1) || (*messageQueueNucleo == (mqd_t)-1) )
        {
		printf("Fail to create message queues. \n");
		return 1;
	}
	return 0;
}



