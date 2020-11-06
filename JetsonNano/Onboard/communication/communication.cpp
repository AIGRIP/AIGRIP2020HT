
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

#include "communication.h"


// filepointer for I2C
int i2cfd;

void setupI2C()
{
    if( (i2cfd = open( FILENAME_I2C, O_RDWR ) ) < 0){
        perror("Failed to open I2C file.\n");
        exit(1);
    }else{
	printf("Open I2C file successfully");
    }
}

void writeI2C(messageStructFromNano *messageFromNano)
{

    if( ioctl( i2cfd,I2C_SLAVE,NUCLEO_ADDRESS )<0){
        perror("Could not send i2c command.\n");
    }else{
        write( i2cfd,messageFromNano, sizeof(messageStructFromNano) );
    }

}


void readI2C(messageStructFromNucleo *messageFromNucleo)
{

    if( ioctl( i2cfd,I2C_SLAVE,NUCLEO_ADDRESS )<0){
        perror("Could not receive i2c message.\n");
        read( i2cfd,messageFromNucleo,sizeof(messageStructFromNucleo) );

    }else{
        read( i2cfd,messageFromNucleo,sizeof(messageStructFromNucleo) );
    }

}



void communicationHandler()
{

    messageStructFromNano messageFromNano;
    messageStructFromNucleo messageFromNucleo;

    setupI2C();

    // Infinit communication
    while(1)
    {

        //writeI2C( &messageFromNano);

        //usleep(1000000);

        readI2C( &messageFromNucleo);

        printf("%d %d %d %d \n",messageFromNucleo.motorStatus[0],messageFromNucleo.motorStatus[1],messageFromNucleo.motorStatus[2],messageFromNucleo.motorStatus[3] );

        usleep(1000000);
    }

}




