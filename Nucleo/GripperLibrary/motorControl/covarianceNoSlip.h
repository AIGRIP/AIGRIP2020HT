/*
 * covarianceNoSlip.h
 *
 *  Created on: Dec 4, 2020
 *      Author: Lagom med Slip
 */

#ifndef SRC_COVARIANCENOSLIP_H_
#define SRC_COVARIANCENOSLIP_H_

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "motorControl.h"
#include "math.h"
#include "PMW3360Drivers.h"


/****************************************************************
 * THE SENSOR NUMBERS NEED TO BE VALIDATED FOR CORRECT FINGERS
 ****************************************************************/
void covarianceBasedSlipPrevention (motorPair *thumb, motorPair *finger1, motorPair *finger2, osMessageQueueId_t opticalSensorQueue, UART_HandleTypeDef *debugUART);


#endif /* SRC_COVARIANCENOSLIP_H_ */
