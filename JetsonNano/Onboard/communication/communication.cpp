
#include <errno.h>
#include <stdio.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>

#include "communication.h"

// Is the second I2C port on Jetson Nano
#define FILENAME_I2C "/dev/i2c-2"
// Adress to nucleo board
#define NUCLEO_ADDRESS "0x5"

// The numbers of sensors
#define NUMBER_OF_MOTORS 8
#define NUMBER_OF_PROXIMITY_SENSORS 7
#define NUMBER_OF_MOUSE_SESNORS 4

typedef struct {

	bool stopGripper = 1;
	short motor[NUMBER_OF_MOTORS];

} messageStructFromNano;

typedef struct {

	bool statusGripper = 1;
	short motorStatus[NUMBER_OF_MOTORS];

    unsigned char proximitySensor[NUMBER_OF_PROXIMITY_SENSORS];
    unsigned char mouseSensor[NUMBER_OF_MOUSE_SESNORS];

} messageStructFromNucleo;

// filepointer for I2C
int i2cfd;

void setupI2C()
{
    if( (i2cfd = open( FILENAME_I2C, O_RDWR ) ) < 0){
        perror("Failed to open I2C file.\n");
        exit(1);
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
        perror("Could not send i2c command.\n");
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




