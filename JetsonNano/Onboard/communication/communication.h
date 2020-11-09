#ifndef communication_h
#define communication_h


// Is the second I2C port on Jetson Nano
#define FILENAME_I2C "/dev/i2c-1"
// Adress to nucleo board
#define NUCLEO_ADDRESS 0x05

// The numbers of sensors
#define NUMBER_OF_MOTORS 8
#define NUMBER_OF_PROXIMITY_SENSORS 7
#define NUMBER_OF_MOUSE_SESNORS 4



struct structMessageStructHeaderFromNano {

	unsigned char frameType;
	unsigned char frameLength;

}typedef messageStructHeaderFromNano;


struct structMouseSensorMessage {

	short XMagnitud;
	short YMagnitud;

}typedef mouseSensorMessage;

struct structMessageStructFromNucelo {

    unsigned char statusOfNucelo;
    short motorStatus[NUMBER_OF_MOTORS];

    unsigned char proximitySensor[NUMBER_OF_PROXIMITY_SENSORS];
    mouseSensorMessage mouseSensor[NUMBER_OF_MOUSE_SESNORS];

}typedef messageStructFromNucleo;

// Setup of I2C on the Jetson Nano.
void setupI2C();

// Write a message on I2C to the Nucleo.
void writeI2C(char *messageToSend,int lengthOfMessage );

// Receive a messafe from Nucleo to Nano.
void readI2C(messageStructFromNucleo *messageFromNucleo);

// Function that contol all I2C communication between the boards.
void communicationHandler();




#endif /* communication_h */
