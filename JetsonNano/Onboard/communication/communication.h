#ifndef communication_h
#define communication_h


#include "typedefsGripperNano.h"

// Is the second I2C port on Jetson Nano
#define FILENAME_I2C "/dev/i2c-1"
// Adress to nucleo board
#define NUCLEO_ADDRESS 0x05


// Function that contol all I2C communication between the boards.
void communicationHandler();




#endif /* communication_h */
