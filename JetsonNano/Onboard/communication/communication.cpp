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
#include "communicationBLT.h"


void communicationHandler()
{
    // Initiate communication structure.
    messageStructHeaderFromNano infoFrameFromNano;
    messageStructFromNucleo messageFromNucleo;

    // Set debug values.
    infoFrameFromNano.frameType = 1;
    infoFrameFromNano.frameLength = 0;

    // Set up I2C
    setupI2C();

    // Set up bluetooth
    setupBluetooth();


    // Startup bluetooth receive thread.
    pthread_attr_t attrBluetooth;
    pthread_t threadIDBluetooth;
    threadCommander = 0;

    pthread_attr_init(&attrBluetooth);
    pthread_create(&threadIDBluetooth, &attrBluetooth,(void*) &receiveBluetoothMessages, (void*)&threadCommander);

    // Startup I2C receive thread.
    pthread_attr_t attrI2C;
    pthread_t threadIDI2C;
    threadCommander = 0;

    pthread_attr_init(&attrI2C);
    pthread_create(&threadIDI2C, &attrI2C,(void*) &I2CReceiveHandler, (void*)&threadCommander);

    mqd_t messageQueue;

    // Creates a message queue.
    char messageMainQueue[] = "/my_mq";
    messageQueue = mq_open(messageMainQueue, O_RDWR);
    
    if( *messageQueue == (mqd_t) -1){
		printf("Failed to open message queue.\n");
	}


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

        if( mq_receive(messageQueue, pBuffer, sizeof(pBuffer),NULL)==0 ){
            
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
                    writeI2C( &I2CHeaderToNucleo, sizeof(messageStructHeaderFromNano) );
                }
                break;

                case 6:
                {
                    // Start the Gripper

                    // Make a callback to indicate that the command was received.
                    memset(I2CBufferToSend, 0, sizeof(I2CBufferToSend));
                    strcat(I2CBufferToSend,"Stop command confirmed\n");
                    sendBluetoothMessage( I2CBufferToSend );

                    // Send command to Nucleo.
                    I2CHeaderToNucleo.frameType = 2;
                    I2CHeaderToNucleo.frameLength = 0;
                    writeI2C( &I2CHeaderToNucleo, sizeof(messageStructHeaderFromNano) );
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





