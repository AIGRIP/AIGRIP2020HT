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

#include "communicationI2C.h"


// The functionS is adapted to work in "communication.cpp".

// filepointer for I2C
int i2cfd;

void setupI2C()
{
    // Define variables for I2C setup and timeout.
    fd_set set;
    struct timeval timeout;
    int rv;

    // Open I2C connection.
    if( (i2cfd = open( FILENAME_I2C, O_RDWR  ) ) < 0){
        perror("Failed to open I2C file.\n");
        exit(1);
    }else{
        printf("Open I2C file successfully.\n");
        fflush(stdout);
    }
/*
    // To set time out while receiving I2C massages.
    FD_ZERO(&set); // clear the set 
    FD_SET(i2cfd, &set); // add the file descriptor to the set 

    // Set timeout for I2C.
    timeout.tv_sec = 0;
    timeout.tv_usec = 100000;
    rv = select(i2cfd + 1, &set, NULL, NULL, &timeout);
*/
    // Control timeout setting.
    if(rv == -1)
    {
        perror("Failed to set timeout.\n");
        exit(1);
    }

}

int writeI2C(unsigned char *messageToSend,int lengthOfMessage )
{
    /*
    * Writes an I2C message.
    * Return 0 on success, 1 on send failure.
    */

    int bytesSent;

    // Connect sender to Nucleos address.
    if( ioctl( i2cfd,I2C_SLAVE,NUCLEO_ADDRESS )<0){
        perror("Could not send i2c command.\n");
        return 2;
    }else{
        // Write data to Nucleo.
        bytesSent = write( i2cfd, messageToSend, lengthOfMessage );

        if(bytesSent > 0){
            return 0;
        }else{
            return 1;
        }

    }

}


int readI2C(messageStructFromNucleo *messageFromNucleo)
{
    // Read I2C messages, reads only "messageStructFromNucleo" messages.

    // Connect sender to Nucleos address.
    if( ioctl( i2cfd,I2C_SLAVE,NUCLEO_ADDRESS )<0){
        perror("Could not receive i2c message.\n");
        return 2;
    }else{
        // Try to read I2C message.
        return read( i2cfd,messageFromNucleo,sizeof(messageStructFromNucleo) );
    }
}




void *I2CReceiveHandler(void *arg)
{
    /*
    * This function handles all the received I2C messages.
    * Is recommended to use a thread for this function. 
    */
    // Message to receive from Nucleo.
    messageStructFromNucleo messageFromNucleo;

    // Get how many bytes that was received.
    int readSize;


    // Connect to main message queue.
    int mainMessageBuffer = RECEIVED_DATA_FROM_NUCLEO;
    mqd_t messageQueueMain;
    messageQueueMain = mq_open(messageMainQueueName, O_RDWR);

    // Connect to nucleo data message queue.
    mqd_t messageQueueNucleo;
    messageQueueNucleo = mq_open(messageQueueNucleoName, O_RDWR);


    // Infinit receive loop
    while(1)
    {


            // Check if I2C data is available, if so read the data.
            readSize = readI2C( &messageFromNucleo );

            // If there was data received send it to the command handle.
	    if(readSize > 0)
            {
                // Check if a false I2C message was received.
                if( messageFromNucleo.statusOfNucelo != 0xFF )
                {
                    // Share info from Nucleo.
                    if( mq_send(messageQueueNucleo, (char*) &messageFromNucleo, sizeof(messageStructFromNucleo),1) !=0 )
                    {
                        printf("Failed to send MQ. \n");
                    }else{

                        // Inform the communication handler that data from nucleo has been received.
                        if( mq_send(messageQueueMain, (char*) &mainMessageBuffer, messageMainQueueSize,1) !=0 )
                        {
                            printf("Failed to send MQ. \n");
                        }

                    }
                }
	    }

    }
}
