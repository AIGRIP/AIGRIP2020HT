#ifndef communication_h
#define communication_h


// Is the second I2C port on Jetson Nano
#define FILENAME_I2C "/dev/i2c-1"
// Adress to nucleo board
#define NUCLEO_ADDRESS 0x05

// The numbers of sensors

/* -------- Move to a general header -------- */
#define NUMBER_OF_MOTORS 8
#define NUMBER_OF_PROXIMITY_SENSORS 7
#define NUMBER_OF_MOUSE_SESNORS 4

/* ------------------------------------------ */



// Communication frames between Jetson Nano and Nucleo Board.

// Send header infromation, type of frame and length.
struct structMessageStructHeaderFromNano {

	unsigned char frameType;
	unsigned char frameLength;

}typedef messageStructHeaderFromNano;

/*
* 1. Start          length 0
* 2. Stop           length 0
* 3. Release        length 0
* 4. Pause          length 0
* 5. Motor Command  length "sizeof(messageStructNucleoCommand)"
*/

// Send motor commands to Nucleo.
struct structMessageStructNucleoCommand{

    short motorAngle[NUMBER_OF_MOTORS];

}typedef messageStructNucleoCommand;


// Mouse sensor information.
struct structMouseSensorMessage {

	short XMagnitud;
	short YMagnitud;

}typedef mouseSensorMessage;

// Package from Nucleo to nano, contain all sensor information to store and use as input for functions on the Nano.
struct structMessageStructFromNucelo {

    unsigned char statusOfNucelo;
    short motorStatus[NUMBER_OF_MOTORS];

    unsigned char proximitySensor[NUMBER_OF_PROXIMITY_SENSORS];
    mouseSensorMessage mouseSensor[NUMBER_OF_MOUSE_SESNORS];

}typedef messageStructFromNucleo;


// Function that contol all I2C communication between the boards.
void communicationHandler();




#endif /* communication_h */
