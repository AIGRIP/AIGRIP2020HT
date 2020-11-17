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

#include "communication.h"


// filepointer for I2C
int i2cfd;

void setupI2C()
{
    fd_set set;
    struct timeval timeout;
    int rv;

    if( (i2cfd = open( FILENAME_I2C, O_RDWR  ) ) < 0){
        perror("Failed to open I2C file.\n");
        exit(1);
    }else{
	printf("Open I2C file successfully.\n");
	fflush(stdout);
    }

    FD_ZERO(&set); /* clear the set */
    FD_SET(i2cfd, &set); /* add our file descriptor to the set */

    timeout.tv_sec = 0;
    timeout.tv_usec = 100000;

    rv = select(i2cfd + 1, &set, NULL, NULL, &timeout);

    if(rv == -1)
    {
	perror("Failed to set timeout.\n");
	exit(1);
    }

}

int writeI2C(unsigned char *messageToSend,int lengthOfMessage )
{

    if( ioctl( i2cfd,I2C_SLAVE,NUCLEO_ADDRESS )<0){
        perror("Could not send i2c command.\n");
	exit(1);
        return -1;
    }else{
        return write( i2cfd, messageToSend, lengthOfMessage );
    }

}


int readI2C(messageStructFromNucleo *messageFromNucleo)
{

    if( ioctl( i2cfd,I2C_SLAVE,NUCLEO_ADDRESS )<0){
        perror("Could not receive i2c message.\n");
        exit(1);
	return -1;

    }else{
        return read( i2cfd,messageFromNucleo,sizeof(messageStructFromNucleo) );
    }
}



void communicationHandler()
{
    // The amount of bytes read/write in I2C.
    int readSize, writeSize;

    // Save last time for communication and get current time.
    struct timeval lastTimeCheckI2CMessage,currentTimeHandle;

    // Check received message every 25 milli-second
    const long checkTimming = 25000;

    // Fill a time value.
    gettimeofday(&lastTimeCheckI2CMessage, NULL);

    unsigned long long currentTime;
    unsigned long long lastTime;

    lastTime = lastTimeCheckI2CMessage.tv_sec*1000000 + lastTimeCheckI2CMessage.tv_usec;


    // Initiate communication structure.
    messageStructHeaderFromNano infoFrameFromNano;
    messageStructFromNucleo messageFromNucleo;

    // Set debug values.
    infoFrameFromNano.frameType = 1;
    infoFrameFromNano.frameLength = 0;

    // Set up I2C
    setupI2C();

    // Temporary variable to debug.
    unsigned long counter = 0;


    // Infinit communication
    while(1)
    {

        // Check if it is time to read data from Nucleo. Check if there is commands to send.
        // ToDo make a trigger to send messages.
	gettimeofday(&currentTimeHandle, NULL);
	currentTime = currentTimeHandle.tv_sec*1000000 + currentTimeHandle.tv_usec;

        if((counter%40) == 0 )
        {

	    infoFrameFromNano.frameType = 1;//(counter%3)+1;

            writeSize = writeI2C((unsigned char *) &infoFrameFromNano, sizeof(messageStructHeaderFromNano) );

	    printf("Wrote I2C message: %d\n",writeSize);
	    fflush(stdout);

        }
        else if( (lastTime + checkTimming) <= currentTime )
        {

            // Check if I2C data is available, if so read the data.
            readSize = readI2C( &messageFromNucleo);

	    lastTime = lastTimeCheckI2CMessage.tv_sec*1000000 + lastTimeCheckI2CMessage.tv_usec;

            // If there was data received, get the new time (and print the data).
	    if(readSize >= 42)
            {
		printf("ReadSize %d\n",readSize);
                printf("%d %d %d %d \n",messageFromNucleo.motorStatus[0],messageFromNucleo.motorStatus[1],messageFromNucleo.motorStatus[2],messageFromNucleo.motorStatus[3] );
		printf("Read %llu in between.\n",(currentTime - lastTime));
                fflush(stdout);
		gettimeofday(&lastTimeCheckI2CMessage, NULL);

            }

        }
	counter++;
	fflush(stdout);
        // Sleep 10 ms.
        usleep(10000);
    }

}




