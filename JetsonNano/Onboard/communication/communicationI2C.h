#ifndef communicationI2C_h
#define communicationI2C_h

#include "typedefsGripperNano.h"

// Is the second I2C port on Jetson Nano
#define FILENAME_I2C "/dev/i2c-1"

// Adress to nucleo board
#define NUCLEO_ADDRESS 0x05


// Setup of I2C on the Jetson Nano.
void setupI2C();

// Write a message on I2C to the Nucleo.
int writeI2C(unsigned char *messageToSend,int lengthOfMessage );

// Receive a messafe from Nucleo to Nano.
int readI2C(messageStructFromNucleo *messageFromNucleo);

// To handle incomming I2C messages.
void *I2CReceiveHandler(void *arg);

#endif /* communicationI2C_h */
