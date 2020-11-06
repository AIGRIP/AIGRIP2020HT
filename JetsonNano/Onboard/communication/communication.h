#ifndef communication_h
#define communication_h


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

void setupI2C();

void writeI2C(messageStructFromNano *messageFromNano);

void readI2C(messageStructFromNucleo *messageFromNucleo);

void communicationHandler();




#endif /* communication_h */
