
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

#include "communication.h"


// filepointer for I2C
int i2cfd;

void setupI2C()
{
    if( (i2cfd = open( FILENAME_I2C, O_RDWR  ) ) < 0){
        perror("Failed to open I2C file.\n");
        exit(1);
    }else{
	printf("Open I2C file successfully");
    }
}

void writeI2C(unsigned char *messageToSend,int lengthOfMessage )
{

    if( ioctl( i2cfd,I2C_SLAVE,NUCLEO_ADDRESS )<0){
        perror("Could not send i2c command.\n");
    }else{
        write( i2cfd, messageToSend, lengthOfMessage );
    }

}


void readI2C(messageStructFromNucleo *messageFromNucleo)
{

    if( ioctl( i2cfd,I2C_SLAVE,NUCLEO_ADDRESS )<0){
        perror("Could not receive i2c message.\n");

    }else{
        read( i2cfd,messageFromNucleo,sizeof(messageStructFromNucleo) );
    }

}



void communicationHandler()
{

    messageStructHeaderFromNano infoFrameFromNano;

    messageStructFromNucleo messageFromNucleo;

    infoFrameFromNano.frameType = 1;
    infoFrameFromNano.frameLength = 2;

    setupI2C();
    usleep(100000);

    // Infinit communication
    while(1)
    {

        writeI2C((unsigned char *) &infoFrameFromNano, sizeof(messageStructHeaderFromNano) );


        //printf("Sent message.");

        readI2C( &messageFromNucleo);

        printf("%d %d %d %d \n",messageFromNucleo.motorStatus[0],messageFromNucleo.motorStatus[1],messageFromNucleo.motorStatus[2],messageFromNucleo.motorStatus[3] );

        usleep(100000);
    }

}




