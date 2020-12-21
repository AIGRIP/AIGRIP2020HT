/*
 * AX_12A_API.c
 *
 *  Created on: 12 Nov 2020
 *      Author: Lagom med Slip
 */

#include "AX_12A_API.h"
#include "math.h"
#include "cmsis_os.h"





// Rewrite id of motor
int MotorSetId(UART_HandleTypeDef *huart, uint8_t *id, uint8_t *newId)
{
	int status;
	uint8_t frame[8] = {0xFF, 0xFF, *id, 4, MOTOR_WRITE, ADDR_ID, *newId, 0};
	frame[7] = MotorInstrChecksum(frame, 1);
	status = HAL_UART_Transmit(huart, frame, sizeof(frame), 50);

	return status;
}

// Configure angle limits for the motor, value range: 0 - 1023
int MotorSetAngleLimit(UART_HandleTypeDef *huart, uint8_t *id, uint16_t *cwLimit, uint16_t *ccwLimit)
{
	int status;
	uint8_t frame[11] = {0xFF, 0xFF, *id, 7, MOTOR_WRITE, ADDR_CW_ANGLE_LIMIT, (uint8_t)(*cwLimit & 0xFF), (uint8_t)(*cwLimit >> 8), (uint8_t)(*ccwLimit & 0xFF), (uint8_t)(*ccwLimit >> 8), 0};
	frame[10] = MotorInstrChecksum(frame, 4);

	status = HAL_UART_Transmit(huart, frame, sizeof(frame), 50);

	return status;
}

// Configure maximum torque for the motor, value range: 0 - 1023
int MotorSetMaxTorque(UART_HandleTypeDef *huart, uint8_t *id, uint16_t *maxTorque)
{
	int status;
	uint8_t frame[9] = {0xFF, 0xFF, *id, 5, MOTOR_WRITE, ADDR_MAX_TORQUE, (uint8_t)(*maxTorque & 0xFF), (uint8_t)(*maxTorque >> 8), 0};
	frame[8] = MotorInstrChecksum(frame, 2);

	status = HAL_UART_Transmit(huart, frame, sizeof(frame), 50);

	return status;
}

// Toggle torque for the motor, value range: 0 = OFF, 1 = ON
int MotorSetTorqueEnable(UART_HandleTypeDef *huart, uint8_t *id, uint8_t *enableMotor)
{
	int status, ON = 1, OFF = 0;
	uint8_t frame[8] = {0xFF, 0xFF, *id, 4, MOTOR_WRITE, ADDR_TORQUE_ENABLE, 0, 0};
	if (*enableMotor == 1)
	{
		frame[6] = ON;
	}
	else if (*enableMotor == 0)
	{
		frame[6] = OFF;
	}
	else
	{
		return 5;
	}
	frame[7] = MotorInstrChecksum(frame, 1);
	status = HAL_UART_Transmit(huart, frame, sizeof(frame), 50);
	return status;
}

// Configure compliance margin for each direction of the motor, value range: 0 - 1023
int MotorSetComplianceMargin(UART_HandleTypeDef *huart, uint8_t *id, uint8_t *cwComplianceMargin, uint8_t *ccwComplianceMargin)
{
	int status;
	uint8_t frame[9] = {0xFF, 0xFF, *id, 5, MOTOR_WRITE, ADDR_CW_COMPLIANCE_MARGIN, *cwComplianceMargin, *ccwComplianceMargin, 0};
	frame[8] = MotorInstrChecksum(frame, 2);
	status = HAL_UART_Transmit(huart, frame, sizeof(frame), 50);
	return status;
}

// Configure compliance slope for each direction of the motor, value range: 0 - 1023
int MotorSetComplianceSlope(UART_HandleTypeDef *huart, uint8_t *id, uint8_t *cwComplianceSlope, uint8_t *ccwComplianceSlope)	// 0x00 - 0xFF
{
	int status;
	uint8_t frame[9] = {0xFF, 0xFF, *id, 5, MOTOR_WRITE, ADDR_CW_COMPLIANCE_SLOPE, *cwComplianceSlope, *ccwComplianceSlope, 0};
	frame[8] = MotorInstrChecksum(frame, 2);
	status = HAL_UART_Transmit(huart, frame, sizeof(frame), 50);
	return status;
}

// Configure goal position for the motor, value range: 0 - 1023 (0 - 300 degrees)
int MotorSetGoalPosition(UART_HandleTypeDef *huart, uint8_t *id, uint16_t *goalPosition)	// 0x00 - 0x3FF
{
	int status;
	uint8_t frame[9] = {0xFF, 0xFF, *id, 5, MOTOR_WRITE, ADDR_GOAL_POSITION, (uint8_t)(*goalPosition & 0xFF), (uint8_t)(*goalPosition >> 8), 0};
	frame[8] = MotorInstrChecksum(frame, 2);
	status = HAL_UART_Transmit(huart, frame, sizeof(frame), 50);
	return status;
}

// Configure the speed of the motor, value range: 0 - 1023
int MotorSetMovingSpeed(UART_HandleTypeDef *huart, uint8_t *id, uint16_t *movingSpeed)	// 0x00 - 0x3FF
{
	int status;
	uint8_t frame[9] = {0xFF, 0xFF, *id, 5, MOTOR_WRITE, ADDR_MOVING_SPEED, (uint8_t)(*movingSpeed & 0xFF), (uint8_t)(*movingSpeed >> 8), 0};
	frame[8] = MotorInstrChecksum(frame, 2);
	status = HAL_UART_Transmit(huart, frame, sizeof(frame), 50);
	return status;
}

// Configure the torque limit of the motor, value range: 0 - 1023 (Cannot go higher than max torque)
int MotorSetTorqueLimit(UART_HandleTypeDef *huart, uint8_t *id, uint16_t *torqueLimit) 	// 0x00 - 0x3FF
{
	int status;
	uint8_t frame[9] = {0xFF, 0xFF, *id, 5, MOTOR_WRITE, ADDR_TORQUE_LIMIT, (uint8_t)(*torqueLimit & 0xFF), (uint8_t)(*torqueLimit >> 8), 0};
	frame[8] = MotorInstrChecksum(frame, 2);
	status = HAL_UART_Transmit(huart, frame, sizeof(frame), 50);
	return status;
}

// Lock EEPROM area: 0 = modifiable, 1 = locked ---- IF LOCK IS SET TO 1, POWER MUST BE SWITCHED OFF AND BACK ON TO CHANGE IT BACK TO 0 -----
int MotorSetLock(UART_HandleTypeDef *huart, uint8_t *id, uint8_t *lockROM) 	// Lock EEPROM area: 0 = modifiable, 1 = locked ---- IF LOCK IS SET TO 1, POWER MUST BE SWITCHED OFF AND BACK ON TO CHANGE IT BACK TO 0 -----
{
	int status;
	uint8_t frame[8] = {0xFF, 0xFF, *id, 4, MOTOR_WRITE, ADDR_LOCK, *lockROM, 0};
	frame[7] = MotorInstrChecksum(frame, 1);
	status = HAL_UART_Transmit(huart, frame, sizeof(frame), 50);
	return status;
}

// Configure minimum current to drive the motor, value range: 32 - 1023 ---- DEFAULT = 32 ----
int MotorSetPunch(UART_HandleTypeDef *huart, uint8_t *id, uint16_t *minCurrentThreshold) 	// 0x20 - 0x3FF Minimum current to drive the motor
{
	int status;
	uint8_t frame[9] = {0xFF, 0xFF, *id, 5, MOTOR_WRITE, ADDR_PUNCH, (uint8_t)(*minCurrentThreshold & 0xFF), (uint8_t)(*minCurrentThreshold >> 8), 0};
	frame[8] = MotorInstrChecksum(frame, 2);
	status = HAL_UART_Transmit(huart, frame, sizeof(frame), 50);
	return status;
}

// Set motor baudrate
int MotorSetBaudRate(UART_HandleTypeDef *huart, uint8_t *id, uint8_t *baudRate)
{
	int status;
	uint8_t frame[9] = {0xFF, 0xFF, *id, 5, MOTOR_WRITE, ADDR_BAUD_RATE, (uint8_t)(*baudRate), 0};
	frame[8] = MotorInstrChecksum(frame, 1);
	status = HAL_UART_Transmit(huart, frame, sizeof(frame), 50);
	return status;
}

// Calculate checksum for instruction packages, bytesToSend is interpreted as parameters after the register address, ~( ID + Length + Instruction + Parameter1 + … Parameter N )
int MotorInstrChecksum(uint8_t *frame, uint8_t bytesToSend)
{
	int checksum = 0;

	if (bytesToSend == 0)
	{
		checksum = ~(frame[2] + frame[3] + frame[4]) & 0xFF;
	}
	else if (bytesToSend == 1)
	{
		checksum = ~(frame[2] + frame[3] + frame[4] + frame[5] + frame[6]) & 0xFF;
	}
	else if (bytesToSend == 2)
	{
		checksum = ~(frame[2] + frame[3] + frame[4] + frame[5] + frame[6] + frame[7]) & 0xFF;
	}
	else if (bytesToSend == 4)
	{
		checksum = ~(frame[2] + frame[3] + frame[4] + frame[5] + frame[6] + frame[7] + frame[8] + frame[9]) & 0xFF;
	}
	else
	{
		return -1;
	}

	return checksum;
}


// Calculate checksum for status packages ---- VALIDATE ------ Checksum = ~(ID + Length + Error + Parameter1 + ... + Parameter N)
uint8_t MotorReturnChecksum(uint8_t *argument, int length)
{
	int checksum = 0;
	for (int i=2; i < sizeof(argument) -1; i++)		// Start at 3rd byte to skip communication initialization (2 * 0xFF)
	{
		checksum += argument[i];
	}
	return ~(checksum) & 0xFF;
}

// Convert angle given as a unsigned short into steps for the motor
uint16_t MotorConvertAngle (uint16_t newAngle)
{
	if (newAngle > 65535)//54765)
	{
		return 0;
	}
	return ((uint16_t) round((float)newAngle * 1023.0 / 65535.0));
}

// Convert angle given in degrees into unsigned short
uint16_t MotorGenerateAngle (float angle)
{
	if (angle > 360)
	{
		return (uint16_t)round((fmod(angle, 360.0) * 65535.0 / 300.0));
	}
	else
	{
		return ((uint16_t) (angle * 65535.0 / 300.0));
	}
}

uint16_t MotorConvertShortToDegree (uint16_t ushort)
{
	return ((uint16_t) (300.0 * ushort / 65535.0));
}

// Initialize and configure startup values for the motor
int MotorInitConfig (UART_HandleTypeDef *huart,uint8_t *id, motorConfiguration *motor)
{
//	osKernelLock();
	// Write to ROM area to reset initial configuration
	if (ROM_WRITE || FAILURE)
	{
		if (MotorSetAngleLimit(huart, id, &motor->cwAngleLimit, &motor->ccwAngleLimit))
		{
			return 1;
		}
		//osDelay(DELAY_TRANSMIT);
		HAL_Delay(10);
		if (MotorSetMaxTorque(huart, id, &motor->maxTorque))
		{
			return 2;
		}
		//osDelay(DELAY_TRANSMIT);
		HAL_Delay(10);
	}

	//osDelay(DELAY_TRANSMIT);
	if (MotorSetMovingSpeed(huart, id, &motor->startSpeed))
	{
		return 7;
	}
	//osDelay(DELAY_TRANSMIT);
	HAL_Delay(10);
	if (MotorSetTorqueLimit(huart, id, &motor->startTorqueLimitRAM))
	{
		return 8;
	}
	HAL_Delay(10);
	// Write to RAM area to configure start-up values
	if (MotorSetTorqueEnable(huart, id, &motor->torqueEnable))
	{
		return 3;
	}
	HAL_Delay(10);
	//osDelay(DELAY_TRANSMIT);
	if (MotorSetComplianceMargin(huart, id, &motor->cwComplianceMargin, &motor->ccwComplianceMargin))
	{
		return 4;
	}
	HAL_Delay(10);
	//osDelay(DELAY_TRANSMIT);
	if (MotorSetComplianceSlope(huart, id, &motor->startCwComplianceSlope, &motor->startCcwComplianceSlope))
	{
		return 5;
	}
	HAL_Delay(10);
	//osDelay(DELAY_TRANSMIT);
	if (MotorSetGoalPosition(huart, id, &motor->startPosition))
	{
		return 6;
	}
//	osKernelUnlock();

	return 0;
}

// Send a ping request to motor, returns '1' if the motor responds and '0' otherwise
int MotorPing (UART_HandleTypeDef *huart, uint8_t *id)
{
	uint8_t buf[6] = {0};
	MotorRead(huart, buf, *id, MOTOR_PING, 0);
	if (buf[2] == *id)
	{
		return 1;
	}
	return 0;
}

// Reads bytesToRead bytes at register address addr from motor, and stores it in buf
int MotorRead (UART_HandleTypeDef *huart, uint8_t *buf, uint8_t id, uint8_t addr, uint8_t bytesToRead)
{
	int status = 0, length = 4;
	uint8_t frame[8] = {MOTOR_HEADER, MOTOR_HEADER, id, length, MOTOR_READ, addr, bytesToRead, MotorInstrChecksum(frame, 1)};
	//__HAL_UART_FLUSH_DRREGISTER(huart);
	//  huart->RxXferCount = 0U;
	//  __HAL_UART_SEND_REQ(huart, UART_RXDATA_FLUSH_REQUEST);
	osKernelLock();
	HAL_UART_AbortReceive(huart); // Clear the RX FIFO buffer and counter (neccessary since Rx and Tx are connected, to flush Tx packages from Rx)

	HAL_HalfDuplex_EnableTransmitter(huart); // Disable Rx so that transmitted package is not stored in Rx
	HAL_UART_Transmit(huart, frame, sizeof(frame), 100);


	HAL_HalfDuplex_EnableReceiver(huart); // Enable Rx so that the motor status package can be received
	status = HAL_UART_Receive(huart, buf, 8 + bytesToRead, 400);

	// Restore UART to Tx-Rx mode
	__HAL_LOCK(huart);
	huart->gState = HAL_UART_STATE_BUSY;

	/* Enable the USART's transmit interface by setting the TE bit in the USART CR1 register */
	SET_BIT(huart->Instance->CR1, UART_MODE_TX_RX);

	huart->gState = HAL_UART_STATE_READY;

	__HAL_UNLOCK(huart);

	osKernelUnlock();
	return status;
}

// Send a torque off instruction to motor
int MotorSendStop(UART_HandleTypeDef *huart, uint8_t *id)
{
	int status = 0;
	uint8_t torqueDisable = 0;
	status = MotorSetTorqueEnable(huart, id, &torqueDisable);
	return status;
}
