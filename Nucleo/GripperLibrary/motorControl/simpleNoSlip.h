/*
 * simpleNoSlip.h
 *
 *  Created on: Nov 27, 2020
 *      Author: Lagom med Slip
 */

#ifndef SRC_SIMPLENOSLIP_H_
#define SRC_SIMPLENOSLIP_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "motorControl.h"


void IfSlipIncreaseForce(motorPair thumb, motorPair finger1, motorPair finger2, osMessageQueueId_t opticalSensorQueue, UART_HandleTypeDef *debugUART);

#endif /* SRC_SIMPLENOSLIP_H_ */
