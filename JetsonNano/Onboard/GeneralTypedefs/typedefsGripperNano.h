
#ifndef typedefsGripperNano_h
#define typedefsGripperNano_h

// This file should contain all general definitions that are 
// needed for more than one of the project libraries.


/* --- The numbers of sensors and motors --- */
#define NUMBER_OF_MOTORS 8
#define NUMBER_OF_PROXIMITY_SENSORS 7
#define NUMBER_OF_MOUSE_SESNORS 6
/* ----------------------------------------- */


/* ----------- Info to mailslots ---------- */

// General mailslot to indicate an event to 
#define messageMainQueueName "/message_main_nano"
#define messageMainQueueSize sizeof(int)

// Send the recommended motor position from pre-shape. 
#define messageQueueMotorName "/message_motors"

// Sends the measured distance to the object for pre-shape.
#define messageQueueDistanceName "/message_distance"

// Sends the measured distance to the object for pre-shape.
#define messageQueueNucleoName "/nucleo_log"
/* ----------------------------------------- */



/* --- Communication frames I2C between Jetson Nano and Nucleo Board --- */

/* 
* Send header infromation, type of frame and length.
*
* What each type indicate and the length it should have.
* 1. Start          length 0
* 2. Stop           length 0
* 3. Release        length 0
* 4. Pause          length 0
* 5. Motor Command  length "sizeof(messageI2CToNucleoMotor)"
* 6. Default state  length 0
*/

struct structMessageStructHeaderFromNano {

	unsigned char frameType;
	unsigned char frameLength;

}typedef messageStructHeaderFromNano;

// Send motor commands to Nucleo.
struct structMessageToNucleoMotor{

    short motorAngle[NUMBER_OF_MOTORS];

}typedef messageI2CToNucleoMotor;


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

/* -------------------------------------------------------------------- */



#endif