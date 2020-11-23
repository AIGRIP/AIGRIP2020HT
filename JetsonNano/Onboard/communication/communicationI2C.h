#ifndef communicationI2C_h
#define communicationI2C_h

// Setup of I2C on the Jetson Nano.
void setupI2C();

// Write a message on I2C to the Nucleo.
int writeI2C(char *messageToSend,int lengthOfMessage );

// Receive a messafe from Nucleo to Nano.
int readI2C(messageStructFromNucleo *messageFromNucleo);

// To handle incomming I2C messages.


#endif /* communicationI2C_h */