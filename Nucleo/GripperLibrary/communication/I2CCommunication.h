/*
 * I2CCommunication.h
 *
 *  Created on: Nov 17, 2020
 *      Author: AutoBike01
 */

#ifndef SRC_I2CCOMMUNICATION_H_
#define SRC_I2CCOMMUNICATION_H_



#include <stdio.h>
#include <stdint.h>

#include "stm32h7xx_hal.h"
#include "cmsis_os.h"


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


// Handle all I2C communication between Nucleo and other boards.
void I2CCommunicationHandle(I2C_HandleTypeDef *hi2cHandle,UART_HandleTypeDef *uartDebugHandle );

// Handle received I2C messages.
void I2CCommandHandle(I2C_HandleTypeDef *hi2cHandle,UART_HandleTypeDef *uartDebugHandle );

// Handle I2C Transmition.
uint32_t I2CTransmitHandle(I2C_HandleTypeDef *hi2cHandle,UART_HandleTypeDef *uartDebugHandle );


#endif /* SRC_I2CCOMMUNICATION_H_ */
