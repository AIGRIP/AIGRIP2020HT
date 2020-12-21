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
#include <string.h>

#include "stm32h7xx_hal.h"
#include "cmsis_os.h"

#include "typedefsGripperNucleo.h"


// Handle all I2C communication between Nucleo and other boards.
void I2CCommunicationHandle(I2C_HandleTypeDef *hi2cHandle,osSemaphoreId_t semaforMotorCommand, osMessageQueueId_t messageQueueControlHandle);

// Handle received I2C messages.
void I2CCommandHandle(I2C_HandleTypeDef *hi2cHandle,osSemaphoreId_t semaforMotorCommand, osMessageQueueId_t messageQueueControlHandle );

// Handle I2C Transmition.
uint32_t I2CTransmitHandle(I2C_HandleTypeDef *hi2cHandle );


#endif /* SRC_I2CCOMMUNICATION_H_ */
