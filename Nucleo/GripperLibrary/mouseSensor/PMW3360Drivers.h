/*
 * PMW3360Drivers.h
 *
 *  Created on: Nov 17, 2020
 *      Author: AutoBike01
 */

#ifndef SRC_PMW3360DRIVERS_H_
#define SRC_PMW3360DRIVERS_H_


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "stm32h7xx_hal.h"


// Struct to store sensor values
struct sensValue{

	bool mouseMotion;

    int16_t mouse_D_X;
    int16_t mouse_D_Y;

}typedef sensValue;



// Read memory registers from SPI on channel E
void SPI_E_ReadReg(uint8_t *REG_ADDR, uint8_t *readByte, SPI_HandleTypeDef *hspiHandle );

// Write memory registers from SPI on channel E
void SPI_E_WriteReg(uint8_t *REG_ADDR, uint8_t *sendByte, SPI_HandleTypeDef *hspiHandle );

// Setup for the mouse sensor.
void startUpMouse(SPI_HandleTypeDef *hspiHandle);

// Read mouse sensor
void readMouseSensor(sensValue *sensorPacket, SPI_HandleTypeDef *hspiHandle);


#endif /* SRC_PMW3360DRIVERS_H_ */
