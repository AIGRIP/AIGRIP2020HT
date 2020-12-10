/*
 * motorControl.h
 *
 *  Created on: Nov 18, 2020
 *      Author: Lagom med Slip
 */

#ifndef SRC_MOTORCONTROL_H_
#define SRC_MOTORCONTROL_H_

#include "stm32h7xx_hal.h"
#include "cmsis_os.h"
//#include "stm32h7xx_hal_rcc.h"

#include "AX_12A_API.h"

// Struct for storing all motor values
struct gripperStruct
{
	uint8_t gripperState;
	// ---- THUMB ----
	motorConfiguration thumbM1;
	motorConfiguration thumbM2;

	// ---- FINGER 1 ----
	motorConfiguration finger1Motor0;
	motorConfiguration finger1Motor1;
	motorConfiguration finger1Motor2;

	// ---- FINGER 2 ----
	motorConfiguration finger2Motor0;
	motorConfiguration finger2Motor1;
	motorConfiguration finger2Motor2;

}typedef gripperStruct;


// Pair of motors for UART communication
struct motorPair
{
	UART_HandleTypeDef *huart;
	uint8_t changedPosMotor1;
	uint8_t changedPosMotor2;
	motorConfiguration *motor1;
	motorConfiguration *motor2;
} typedef motorPair;

struct motorPositions
{
	uint16_t controlCommand;
	uint16_t *posThumbMotor1;
	uint16_t *posThumbMotor2;
	uint16_t *posFinger1Motor0;
	uint16_t *posFinger1Motor1;
	uint16_t *posFinger1Motor2;
	uint16_t *posFinger2Motor0;
	uint16_t *posFinger2Motor1;
	uint16_t *posFinger2Motor2;
}typedef motorPositions;

struct motorValues
{
	uint16_t thumbMotor1;
	uint16_t thumbMotor2;

	uint16_t finger1Motor1;
	uint16_t finger1Motor2;

	uint16_t finger2Motor1;
	uint16_t finger2Motor2;
}typedef motorValues;


#define GRIPPER_START 	1
#define GRIPPER_STOP 	2
#define GRIPPER_PAUSE 	3
#define GRIPPER_RELEASE	4
#define GRIPPER_DEFAULT 5
#define GRIPPER_SLIPNOT 6


uint16_t MotorConvertPosToShort (uint16_t pos);
void GripperStartupConfiguration (UART_HandleTypeDef *uart_Thumb, UART_HandleTypeDef *uart_DynamicGrasp, UART_HandleTypeDef *uart_Finger1, UART_HandleTypeDef *uart_Finger2, gripperStruct *finger);
void MotorControlThread (UART_HandleTypeDef *uart_Thumb, UART_HandleTypeDef *uart_DynamicGrasp, UART_HandleTypeDef *uart_Finger1, UART_HandleTypeDef *uart_Finger2, osMessageQueueId_t nanoMsgQueue, osMessageQueueId_t opticalSensorQueue, UART_HandleTypeDef *debugUART);
void MotorReadMsgQueueFromNano (osMessageQueueId_t nanoMsgQueue, motorPositions *positions, motorPair *thumb, motorPair *finger1, motorPair *finger2, motorPair *dynamicGrasp, gripperStruct *motors);



#endif /* SRC_MOTORCONTROL_H_ */
