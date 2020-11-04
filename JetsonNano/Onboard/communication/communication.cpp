

#include <linux/i2c-dev.h>

// Is the second I2C port on Jetson Nano
#define filename_i2c "/dev/i2c-2"




void setupI2C()
{
    if( (i2cfd = open( filename_i2c, O_RDWR ) ) < 0){
        perror("Failed to open I2C file.\n");
        exit(1);
	}
}