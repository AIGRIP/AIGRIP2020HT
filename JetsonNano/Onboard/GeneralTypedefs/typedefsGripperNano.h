
#ifndef typedefsGripperNano_h
#define typedefsGripperNano_h

// This file should contain all general definitions that are
// needed for more than one of the project libraries.


/* --- The numbers of sensors and motors --- */
#define NUMBER_OF_MOTORS 8
#define NUMBER_OF_PROXIMITY_SENSORS 7
#define NUMBER_OF_MOUSE_SESNORS 6
/* ----------------------------------------- */

/* ----------- Control Parameters ---------- */

// Number of recommended motorvalues that can
// be buffered. Need at least one.
#define PRE_SHAPE_BUFFER 2
// The number of messages that is allowed in the 
// buffer for control data.
#define CONTROL_DATA_BUFFER_SIZE 2
/* ----------------------------------------- */


/* ----------- Info of mailslots ---------- */

// General mailslot to indicate an event to the command handler.
#define messageMainQueueName "/message_main_nano"
#define messageMainQueueSize sizeof(int)

// Send the recommended motor position from control thread.
#define messageQueueMotorName "/message_motors"

// Sends the measured distance to the object for pre-shape.
#define messageQueueControlDataName "/message_controlData"

// Sends the measured distance to the object for pre-shape.
#define messageQueueNucleoName "/nucleo_log"
/* ----------------------------------------- */

    /*
    * Defines each command on the Jetson Nano.
    * Handles all the communication, between other devices.
    *
    *   1.  Send motor commands to Nucleo.
    *   2.
    *   3.
    *   4.  Received data from Nucleo.
    *   5.  Send gripper status to bluetooth device.
    *   6.  Received start command from bluetooth.
    *   7.  Received stop command from bluetooth.
    *   8.  User is disconnected from bluetooth.
    *   9.  Inform user that gripper is in pre-shape mode.
    *   10. Inform user that gripper is in approach mode.
    *   11. Send slipNot command to Nucleo and inform the user that gripper is in slipnot mode.
    */

/* --------- Defines state machine -------- */

#define SEND_MOTOR_COMMAND                  1
#define RECEIVED_DATA_FROM_NUCLEO           2
#define RECEIVED_START_COMMAND_BLUETOOTH    3
#define RECEIVED_STOP_COMMAND_BLUETOOTH     4
#define USER_DISCONNECTED_BLUETOOTH         5
#define SEND_PRESHAPE_BLUETOOTH             6
#define SEND_APPROACH_BLUETOOTH             7
#define SEND_SLIPNOT_BLUETOOTH              8

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
* 6. Slipnot        length 0
*/

struct structMessageStructHeaderFromNano {

	unsigned char frameType;
	unsigned char frameLength;

}typedef messageStructHeaderFromNano;

// Send motor commands to Nucleo.
struct structMessageToNucleoMotor{

    unsigned short motorAngle[NUMBER_OF_MOTORS];

}typedef messageMotorStruct;


// Mouse sensor information.
struct structMouseSensorMessage {

	short XMagnitud;
	short YMagnitud;

}typedef mouseSensorMessage;

struct structProximitySensorMessage {
    unsigned short proximitySensor[NUMBER_OF_PROXIMITY_SENSORS];
}typedef proximitySensorMessage;

// Package from Nucleo to nano, contain all sensor information to store and use as input for functions on the Nano.
struct structMessageStructFromNucelo {

    unsigned char statusOfNucelo;
    messageMotorStruct motorStatus;

    proximitySensorMessage proximitySensors;
    mouseSensorMessage mouseSensor[NUMBER_OF_MOUSE_SESNORS];

}typedef messageStructFromNucleo;

/* -------------------------------------------------------------------- */


// To receive necisary data in control thread.
struct controlDatastruct {

    proximitySensorMessage distanceData;

    messageMotorStruct motorData;

}typedef controlData;


#endif
