/*
 * MotorControl.c
 *
 *  Created on: 18 Nov 2020
 *      Author: Lagom med Slip
 */

#include "AX_12A_API.h"
//#include "cmsis_os.h"
#include "MotorControl.h"
#include "string.h"
#include "simpleNoSlip.h"

/*
struct motorData
{
    // Motor
    uint8_t sendStatus;
    uint8_t receiveStatus;
    uint8_t sendPack[PACKAGE_LENGTH];
    uint8_t recPack[PACKAGE_LENGTH];
}typedef motorData;
*/

#define DEFAULT_SPEED 0
#define DEFAULT_TORQUE 512

uint16_t MotorConvertPosToShort (uint16_t pos)
{
	return ((uint16_t) round((float) pos * (65535 / 1023)));
}


void GripperStartupConfiguration (UART_HandleTypeDef *uart_Thumb, UART_HandleTypeDef *uart_DynamicGrasp, UART_HandleTypeDef *uart_Finger1, UART_HandleTypeDef *uart_Finger2, gripperStruct *motors)
{

	/* -------------------
	 * ------ THUMB ------
	   ------------------- */

	// ----- Motor 1 -----
	// Static Motor values
	motors->thumbM1.id = 7;
	motors->thumbM1.cwAngleLimit = MotorConvertAngle(MotorGenerateAngle(150 + 34));
	motors->thumbM1.ccwAngleLimit = MotorConvertAngle(MotorGenerateAngle(270));
	motors->thumbM1.maxTorque = DEFAULT_TORQUE;
	motors->thumbM1.punch = 32;
	// Initial Values
	motors->thumbM1.startCwComplianceMargin = 0;
	motors->thumbM1.startCcwComplianceMargin = 0;
	motors->thumbM1.startCwComplianceSlope = 32;
	motors->thumbM1.startCcwComplianceSlope = 32;
	motors->thumbM1.startPosition = motors->thumbM1.ccwAngleLimit;//MotorConvertAngle(MotorGenerateAngle(240));
	motors->thumbM1.startSpeed = DEFAULT_SPEED;
	motors->thumbM1.startTorqueLimitRAM = DEFAULT_TORQUE;
	// Runtime values
	motors->thumbM1.torqueEnable = 1;
	motors->thumbM1.cwComplianceMargin = 0;
	motors->thumbM1.ccwComplianceMargin = 0;
	motors->thumbM1.cwComplianceSlope = 32;
	motors->thumbM1.ccwComplianceSlope = 32;
	motors->thumbM1.goalPosition = motors->thumbM1.startPosition;
	motors->thumbM1.movingSpeed = motors->thumbM1.startSpeed;
	motors->thumbM1.torqueLimitRAM = motors->thumbM1.startTorqueLimitRAM;
	motors->thumbM1.lockEEPROM = 0;

	MotorInitConfig(uart_Thumb, &motors->thumbM1.id, &motors->thumbM1);


	// ----- Motor 2 -----
	// Static Motor values
	motors->thumbM2.id = 8;
	motors->thumbM2.cwAngleLimit = MotorConvertAngle(MotorGenerateAngle(110));
	motors->thumbM2.ccwAngleLimit = MotorConvertAngle(MotorGenerateAngle(160));
	motors->thumbM2.maxTorque = DEFAULT_TORQUE;
	motors->thumbM2.punch = 32;
	// Initial Values
	motors->thumbM2.startCwComplianceMargin = 0;
	motors->thumbM2.startCcwComplianceMargin = 0;
	motors->thumbM2.startCwComplianceSlope = 32;
	motors->thumbM2.startCcwComplianceSlope = 32;
	motors->thumbM2.startPosition = motors->thumbM2.ccwAngleLimit;//512 - MotorConvertAngle(MotorGenerateAngle((float)12U));
	motors->thumbM2.startSpeed = DEFAULT_SPEED;
	motors->thumbM2.startTorqueLimitRAM = DEFAULT_TORQUE;
	// Runtime values
	motors->thumbM2.torqueEnable = 1;
	motors->thumbM2.cwComplianceMargin = 0;
	motors->thumbM2.ccwComplianceMargin = 0;
	motors->thumbM2.cwComplianceSlope = 32;
	motors->thumbM2.ccwComplianceSlope = 32;
	motors->thumbM2.goalPosition = motors->thumbM2.startPosition;
	motors->thumbM2.movingSpeed = motors->thumbM2.startSpeed;
	motors->thumbM2.torqueLimitRAM = motors->thumbM2.startTorqueLimitRAM;
	motors->thumbM2.lockEEPROM = 0;

	MotorInitConfig(uart_Thumb, &motors->thumbM2.id, &motors->thumbM2);




	/* -------------------
	 * ----- FINGER 2 ----
	   ------------------- */

	// ----- Motor 0 -----
	// Static Motor values
	motors->finger2Motor0.id = 1;
	motors->finger2Motor0.cwAngleLimit = MotorConvertAngle(MotorGenerateAngle(60));//512;
	motors->finger2Motor0.ccwAngleLimit = MotorConvertAngle(MotorGenerateAngle(150));//800;
	motors->finger2Motor0.maxTorque = DEFAULT_TORQUE;
	motors->finger2Motor0.punch = 32;
	// Initial Values
	motors->finger2Motor0.startCwComplianceMargin = 0;
	motors->finger2Motor0.startCcwComplianceMargin = 0;
	motors->finger2Motor0.startCwComplianceSlope = 32;//32;
	motors->finger2Motor0.startCcwComplianceSlope = 32;//32;
	motors->finger2Motor0.startPosition = motors->finger2Motor0.ccwAngleLimit;
	motors->finger2Motor0.startSpeed = DEFAULT_SPEED;
	motors->finger2Motor0.startTorqueLimitRAM = DEFAULT_TORQUE;
	// Runtime values
	motors->finger2Motor0.torqueEnable = 1;
	motors->finger2Motor0.cwComplianceMargin = 0;
	motors->finger2Motor0.ccwComplianceMargin = 0;
	motors->finger2Motor0.cwComplianceSlope = 32;
	motors->finger2Motor0.ccwComplianceSlope = 32;
	motors->finger2Motor0.goalPosition = motors->finger2Motor0.startPosition;
	motors->finger2Motor0.movingSpeed = motors->finger2Motor0.startSpeed;
	motors->finger2Motor0.torqueLimitRAM = motors->finger2Motor0.startTorqueLimitRAM;
	motors->finger2Motor0.lockEEPROM = 0;

	MotorInitConfig(uart_DynamicGrasp, &motors->finger2Motor0.id, &motors->finger2Motor0);


	// ----- Motor 1 -----
	// Static Motor values
	motors->finger2Motor1.id = 3;
	motors->finger2Motor1.cwAngleLimit = MotorConvertAngle(MotorGenerateAngle(150 + 34));
	motors->finger2Motor1.ccwAngleLimit = MotorConvertAngle(MotorGenerateAngle(270));
	motors->finger2Motor1.maxTorque = DEFAULT_TORQUE;
	motors->finger2Motor1.punch = 32;
	// Initial Values
	motors->finger2Motor1.startCwComplianceMargin = 0;
	motors->finger2Motor1.startCcwComplianceMargin = 0;
	motors->finger2Motor1.startCwComplianceSlope = 32;
	motors->finger2Motor1.startCcwComplianceSlope = 32;
	motors->finger2Motor1.startPosition = motors->finger2Motor1.ccwAngleLimit;//MotorConvertAngle(MotorGenerateAngle(240));
	motors->finger2Motor1.startSpeed = DEFAULT_SPEED;
	motors->finger2Motor1.startTorqueLimitRAM = DEFAULT_TORQUE;
	// Runtime values
	motors->finger2Motor1.torqueEnable = 1;
	motors->finger2Motor1.cwComplianceMargin = 0;
	motors->finger2Motor1.ccwComplianceMargin = 0;
	motors->finger2Motor1.cwComplianceSlope = 32;
	motors->finger2Motor1.ccwComplianceSlope = 32;
	motors->finger2Motor1.goalPosition = motors->finger2Motor1.startPosition;
	motors->finger2Motor1.movingSpeed = motors->finger2Motor1.startSpeed;
	motors->finger2Motor1.torqueLimitRAM = motors->finger2Motor1.startTorqueLimitRAM;
	motors->finger2Motor1.lockEEPROM = 0;

	MotorInitConfig(uart_Finger2, &motors->finger2Motor1.id, &motors->finger2Motor1);


	// ----- Motor 2 -----
	// Static Motor values
	motors->finger2Motor2.id = 4;
	motors->finger2Motor2.cwAngleLimit = MotorConvertAngle(MotorGenerateAngle(110));
	motors->finger2Motor2.ccwAngleLimit = MotorConvertAngle(MotorGenerateAngle(160));
	motors->finger2Motor2.maxTorque = DEFAULT_TORQUE;
	motors->finger2Motor2.punch = 32;
	// Initial Values
	motors->finger2Motor2.startCwComplianceMargin = 0;
	motors->finger2Motor2.startCcwComplianceMargin = 0;
	motors->finger2Motor2.startCwComplianceSlope = 32;
	motors->finger2Motor2.startCcwComplianceSlope = 32;
	motors->finger2Motor2.startPosition = motors->finger2Motor2.ccwAngleLimit;//512 - MotorConvertAngle(MotorGenerateAngle((float)12U));
	motors->finger2Motor2.startSpeed = DEFAULT_SPEED;
	motors->finger2Motor2.startTorqueLimitRAM = DEFAULT_TORQUE;
	// Runtime values
	motors->finger2Motor2.torqueEnable = 1;
	motors->finger2Motor2.cwComplianceMargin = 0;
	motors->finger2Motor2.ccwComplianceMargin = 0;
	motors->finger2Motor2.cwComplianceSlope = 32;
	motors->finger2Motor2.ccwComplianceSlope = 32;
	motors->finger2Motor2.goalPosition = motors->finger2Motor2.startPosition;
	motors->finger2Motor2.movingSpeed = motors->finger2Motor2.startSpeed;
	motors->finger2Motor2.torqueLimitRAM = motors->finger2Motor2.startTorqueLimitRAM;
	motors->finger2Motor2.lockEEPROM = 0;

	MotorInitConfig(uart_Finger2, &motors->finger2Motor2.id, &motors->finger2Motor2);



	/* -------------------
	 * ----- FINGER 1 ----
	   ------------------- */

	// ----- Motor 0 -----
	// Static Motor values
	motors->finger1Motor0.id = 2;
	motors->finger1Motor0.cwAngleLimit = MotorConvertAngle(MotorGenerateAngle(150));//200;
	motors->finger1Motor0.ccwAngleLimit = MotorConvertAngle(MotorGenerateAngle(240));//512;
	motors->finger1Motor0.maxTorque = DEFAULT_TORQUE;
	motors->finger1Motor0.punch = 32;
	// Initial Values
	motors->finger1Motor0.startCwComplianceMargin = 0;
	motors->finger1Motor0.startCcwComplianceMargin = 0;
	motors->finger1Motor0.startCwComplianceSlope = 32;
	motors->finger1Motor0.startCcwComplianceSlope = 32;
	motors->finger1Motor0.startPosition = motors->finger1Motor0.cwAngleLimit;
	motors->finger1Motor0.startSpeed = DEFAULT_SPEED;
	motors->finger1Motor0.startTorqueLimitRAM = DEFAULT_TORQUE;
	// Runtime values
	motors->finger1Motor0.torqueEnable = 1;
	motors->finger1Motor0.cwComplianceMargin = 0;
	motors->finger1Motor0.ccwComplianceMargin = 0;
	motors->finger1Motor0.cwComplianceSlope = 32;
	motors->finger1Motor0.ccwComplianceSlope = 32;
	motors->finger1Motor0.goalPosition = motors->finger1Motor0.startPosition;
	motors->finger1Motor0.movingSpeed = motors->finger1Motor0.startSpeed;
	motors->finger1Motor0.torqueLimitRAM = motors->finger1Motor0.startTorqueLimitRAM;
	motors->finger1Motor0.lockEEPROM = 0;

	MotorInitConfig(uart_DynamicGrasp, &motors->finger1Motor0.id, &motors->finger1Motor0);



	// ----- Motor 1 -----
	// Static Motor values
	motors->finger1Motor1.id = 5;
	motors->finger1Motor1.cwAngleLimit = MotorConvertAngle(MotorGenerateAngle(150 + 34));
	motors->finger1Motor1.ccwAngleLimit = MotorConvertAngle(MotorGenerateAngle(270));
	motors->finger1Motor1.maxTorque = DEFAULT_TORQUE;
	motors->finger1Motor1.punch = 32;
	// Initial Values
	motors->finger1Motor1.startCwComplianceMargin = 0;
	motors->finger1Motor1.startCcwComplianceMargin = 0;
	motors->finger1Motor1.startCwComplianceSlope = 32;
	motors->finger1Motor1.startCcwComplianceSlope = 32;
	motors->finger1Motor1.startPosition = motors->finger1Motor1.ccwAngleLimit;//MotorConvertAngle(MotorGenerateAngle(240));
	motors->finger1Motor1.startSpeed = DEFAULT_SPEED;
	motors->finger1Motor1.startTorqueLimitRAM = DEFAULT_TORQUE;
	// Runtime values
	motors->finger1Motor1.torqueEnable = 1;
	motors->finger1Motor1.cwComplianceMargin = 0;
	motors->finger1Motor1.ccwComplianceMargin = 0;
	motors->finger1Motor1.cwComplianceSlope = 32;
	motors->finger1Motor1.ccwComplianceSlope = 32;
	motors->finger1Motor1.goalPosition = motors->finger1Motor1.startPosition;
	motors->finger1Motor1.movingSpeed = motors->finger1Motor1.startSpeed;
	motors->finger1Motor1.torqueLimitRAM = motors->finger1Motor1.startTorqueLimitRAM;
	motors->finger1Motor1.lockEEPROM = 0;

	MotorInitConfig(uart_Finger1, &motors->finger1Motor1.id, &motors->finger1Motor1);


	// ----- Motor 2 -----
	// Static Motor values
	motors->finger1Motor2.id = 6;
	motors->finger1Motor2.cwAngleLimit = MotorConvertAngle(MotorGenerateAngle(110));
	motors->finger1Motor2.ccwAngleLimit = MotorConvertAngle(MotorGenerateAngle(160));
	motors->finger1Motor2.maxTorque = DEFAULT_TORQUE;
	motors->finger1Motor2.punch = 32;
	// Initial Values
	motors->finger1Motor2.startCwComplianceMargin = 0;
	motors->finger1Motor2.startCcwComplianceMargin = 0;
	motors->finger1Motor2.startCwComplianceSlope = 32;
	motors->finger1Motor2.startCcwComplianceSlope = 32;
	motors->finger1Motor2.startPosition = motors->finger1Motor2.ccwAngleLimit;//512 - MotorConvertAngle(MotorGenerateAngle((float)12U));
	motors->finger1Motor2.startSpeed = DEFAULT_SPEED;
	motors->finger1Motor2.startTorqueLimitRAM = DEFAULT_TORQUE;
	// Runtime values
	motors->finger1Motor2.torqueEnable = 1;
	motors->finger1Motor2.cwComplianceMargin = 0;
	motors->finger1Motor2.ccwComplianceMargin = 0;
	motors->finger1Motor2.cwComplianceSlope = 32;
	motors->finger1Motor2.ccwComplianceSlope = 32;
	motors->finger1Motor2.goalPosition = motors->finger1Motor2.startPosition;
	motors->finger1Motor2.movingSpeed = motors->finger1Motor2.startSpeed;
	motors->finger1Motor2.torqueLimitRAM = motors->finger1Motor2.startTorqueLimitRAM;
	motors->finger1Motor2.lockEEPROM = 0;

	MotorInitConfig(uart_Finger1, &motors->finger1Motor2.id, &motors->finger1Motor2);

}


void MotorReadMsgQueueFromNano (osMessageQueueId_t nanoMsgQueue, motorPositions *positions, motorPair *thumb, motorPair *finger1, motorPair *finger2, motorPair *dynamicGrasp, gripperStruct *motors, osSemaphoreId_t semaforMotorCommand)
{
	uint16_t tempPos = 0, controlCommand = 0;

	if (osMessageQueueGetCount(nanoMsgQueue) > 0)
	{
		osMessageQueueGet(nanoMsgQueue, &controlCommand, NULL, 0U);
		switch (controlCommand)
		{
			// controlCommand : 1 indicates start command
			case 1:
				motors->gripperState = GRIPPER_SLIPNOT;
				break;
			// controlCommand : 2 indicates stop command
			case 2:
				motors->gripperState = GRIPPER_STOP;
				break;
			// controlCommand : 3 indicates release command
			case 3:
				motors->gripperState = GRIPPER_RELEASE;
				break;
			// controlCommand : 4 indicates pause command
			case 4:
				motors->gripperState = GRIPPER_PAUSE;
				break;
			// controlCommand : 5 indicates default state
			case 5:
			{
				// Wait for semaphore in order to not preempt communication task from sending motor commands.
				if (osSemaphoreAcquire( semaforMotorCommand, 200) == osOK)
				{
					// If the gripper is in start mode update new goal positions, otherwise ignore them
					if (motors->gripperState == GRIPPER_START)
					{
						osMessageQueueGet(nanoMsgQueue, &tempPos, NULL, 0U);
						if (tempPos != *positions->posThumbMotor1)
						{
							*positions->posThumbMotor1 = MotorConvertAngle(tempPos);
							thumb->changedPosMotor1 = 1;
						}
						osMessageQueueGet(nanoMsgQueue, &tempPos, NULL, 0U);
						if (tempPos != *positions->posThumbMotor2)
						{
							*positions->posThumbMotor2 = MotorConvertAngle(tempPos);
							thumb->changedPosMotor2 = 1;
						}
						osMessageQueueGet(nanoMsgQueue, &tempPos, NULL, 0U);
						if (tempPos != *positions->posFinger1Motor0)
						{
							*positions->posFinger1Motor0 = MotorConvertAngle(tempPos);
							dynamicGrasp->changedPosMotor1 = 1;
						}
						osMessageQueueGet(nanoMsgQueue, &tempPos, NULL, 0U);
						if (tempPos != *positions->posFinger1Motor1)
						{
							*positions->posFinger1Motor1 = MotorConvertAngle(tempPos);
							finger1->changedPosMotor1 = 1;
						}
						osMessageQueueGet(nanoMsgQueue, &tempPos, NULL, 0U);
						if (tempPos != *positions->posFinger1Motor2)
						{
							*positions->posFinger1Motor2 = MotorConvertAngle(tempPos);
							finger1->changedPosMotor2 = 1;
						}
						osMessageQueueGet(nanoMsgQueue, &tempPos, NULL, 0U);
						if (tempPos != *positions->posFinger2Motor0)
						{
							*positions->posFinger2Motor0 = MotorConvertAngle(tempPos);
							dynamicGrasp->changedPosMotor2 = 1;
						}
						osMessageQueueGet(nanoMsgQueue, &tempPos, NULL, 0U);
						if (tempPos != *positions->posFinger2Motor1)
						{
							*positions->posFinger2Motor1 = MotorConvertAngle(tempPos);
							finger2->changedPosMotor1 = 1;
						}
						osMessageQueueGet(nanoMsgQueue, &tempPos, NULL, 0U);
						if (tempPos != *positions->posFinger2Motor2)
						{
							*positions->posFinger2Motor2 = MotorConvertAngle(tempPos);
							finger2->changedPosMotor2 = 1;
						}
					}
					// Clear unused motor positions from the queue
					else
					{
						for (int i=0; i < NUMBER_OF_MOTORS; i++)
						{
							osMessageQueueGet(nanoMsgQueue, &tempPos, NULL, 0U);
						}
					}
					// Release semaphore.
					if (osSemaphoreRelease(semaforMotorCommand) != osOK)
					{
						while (1) {}
					}
				}
			}
			break;
			// controlCommand : 6 indicates start of slipnot
			case 6:
				motors->gripperState = GRIPPER_SLIPNOT;
				break;
			// Catch of unexpected values
			default:
				while (1) {}
				{
					int numberOfMessageToRemove = osMessageQueueGetCount(nanoMsgQueue);

					for(int i = 0; i < numberOfMessageToRemove;i++)
					{
						osMessageQueueGet(nanoMsgQueue, &tempPos, NULL, 0U);
					}
				}

				break;
		}


	}

}


void MotorControlThread(UART_HandleTypeDef *uart_Thumb, UART_HandleTypeDef *uart_DynamicGrasp, UART_HandleTypeDef *uart_Finger1, UART_HandleTypeDef *uart_Finger2, osMessageQueueId_t nanoMsgQueue, osMessageQueueId_t opticalSensorQueue, osSemaphoreId_t semaforMotorCommand)
{

	//uint8_t buf[18] = {0}, sendStatus = -1, receiveStatus = -1;
	//int statusM1,statusM2;
	//motorData plotValues;
	gripperStruct gripper;

	// ---------
	//int switchPos = 0;
	// ---------

	// Set Tri-state buffer to Tx lines
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, SET);

	osDelay(5);
	GripperStartupConfiguration(uart_Thumb, uart_DynamicGrasp, uart_Finger1, uart_Finger2, &gripper);



	// make positions linked to gripper struct goalPositions
	motorPositions positions = {GRIPPER_PAUSE,&gripper.thumbM1.goalPosition, &gripper.thumbM2.goalPosition, &gripper.finger1Motor0.goalPosition, &gripper.finger1Motor1.goalPosition, &gripper.finger1Motor2.goalPosition, &gripper.finger2Motor0.goalPosition, &gripper.finger2Motor1.goalPosition, &gripper.finger2Motor2.goalPosition};
	motorPair thumb = {uart_Thumb, 0, 0, &gripper.thumbM1, &gripper.thumbM2};
	motorPair finger1 = {uart_Finger1, 0, 0, &gripper.finger1Motor1, &gripper.finger1Motor2};
	motorPair finger2 = {uart_Finger2, 0, 0, &gripper.finger2Motor1, &gripper.finger2Motor2};
	motorPair dynamicGrasp = {uart_DynamicGrasp, 0, 0, &gripper.finger1Motor0, &gripper.finger2Motor0};

	int switchPos = 0;
	uint64_t currTick1, currTick2, executionTicks = 0;

//	uint16_t pos1M0 = 800, pos1M1 = 963, pos1M2 = 589;
//	uint16_t pos1M0 = 512, pos1M1 = 760, pos1M2 = 400;
//	uint16_t pos2M0 = 412, pos2M1 = 963, pos2M2 = 589;
	uint16_t pos1M0 = 512, pos1M1 = gripper.finger1Motor1.cwAngleLimit, pos1M2 = gripper.finger1Motor2.cwAngleLimit;
	uint16_t pos2M0 = 412, pos2M1 = gripper.finger1Motor1.ccwAngleLimit, pos2M2 = gripper.finger1Motor2.ccwAngleLimit;

	//uint16_t tempPos = 350;
	//motorsStruct motors[3] = {0};
	//uint16_t offsetM2 = MotorConvertAngle(MotorGenerateAngle((float)12U));

/*
	osKernelLock();
	MotorSetGoalPosition(dynamicGrasp.huart, &dynamicGrasp.motor2->id, &tempPos);
	osKernelUnlock();
*/
	//int wander = 0;


	// Infinite loop
	for(;;)
	{
		currTick1 = osKernelGetTickCount();

		MotorReadMsgQueueFromNano(nanoMsgQueue, &positions, &thumb, &finger1, &finger2, &dynamicGrasp, &gripper, semaforMotorCommand);


		switch (gripper.gripperState) {
			// SECTION FOR SLIPNOT
			case GRIPPER_SLIPNOT:
				IfSlipIncreaseForce(&thumb, &finger1, &finger2, opticalSensorQueue);
				break;
			// SECTION FOR STOP
			case GRIPPER_STOP:
				// FOR TESTING, STOP COMMAND RETURNS MOTORS TO STARTUP POSITIONS AND CONFIGURATION
				GripperStartupConfiguration(thumb.huart, dynamicGrasp.huart, finger1.huart, finger2.huart, &gripper);
/*
				// INVESTIGATE REQUIRED DELAY FOR SUCCESSFUL DATA TRANSFER, AVOID OVERFLOW
				osKernelLock();
				MotorSendStop(thumb.huart, &thumb.motor1->id);
				HAL_Delay(5);
				MotorSendStop(thumb.huart, &thumb.motor2->id);
				HAL_Delay(5);
				MotorSendStop(dynamicGrasp.huart, &dynamicGrasp.motor1->id);
				HAL_Delay(5);
				MotorSendStop(dynamicGrasp.huart, &dynamicGrasp.motor2->id);
				HAL_Delay(5);
				MotorSendStop(finger1.huart, &finger1.motor1->id);
				HAL_Delay(5);
				MotorSendStop(finger1.huart, &finger1.motor2->id);
				HAL_Delay(5);
				MotorSendStop(finger2.huart, &finger2.motor1->id);
				HAL_Delay(5);
				MotorSendStop(finger2.huart, &finger2.motor2->id);
				osKernelUnlock();
*/
				break;
			// SECTION FOR DEFAULT
			case GRIPPER_DEFAULT:
				GripperStartupConfiguration(thumb.huart, dynamicGrasp.huart, finger1.huart, finger2.huart, &gripper);
				break;
			default:
				break;
		}

		// ----------------------
		// UPDATE MOTOR POSITIONS
		// ----------------------

		if (thumb.changedPosMotor1)
		{
			osKernelLock();
			MotorSetGoalPosition(thumb.huart, &thumb.motor1->id, positions.posThumbMotor1);
			osKernelUnlock();
			thumb.changedPosMotor1 = 0;
			osDelay(2);
		}

		if (thumb.changedPosMotor2)
		{
			osKernelLock();
			MotorSetGoalPosition(thumb.huart, &thumb.motor2->id, positions.posThumbMotor2);
			osKernelUnlock();
			thumb.changedPosMotor2 = 0;
			osDelay(2);
		}

		if (finger1.changedPosMotor1)
		{
			osKernelLock();
			MotorSetGoalPosition(finger1.huart, &finger1.motor1->id, positions.posFinger1Motor1);
			osKernelUnlock();
			finger1.changedPosMotor1 = 0;
			osDelay(2);
		}

		if (finger1.changedPosMotor2)
		{
			osKernelLock();
			MotorSetGoalPosition(finger1.huart, &finger1.motor2->id, positions.posFinger1Motor2);
			osKernelUnlock();
			finger1.changedPosMotor2 = 0;
			osDelay(2);
		}

		if (finger2.changedPosMotor1)
		{
			osKernelLock();
			MotorSetGoalPosition(finger2.huart, &finger2.motor1->id, positions.posFinger2Motor1);
			osKernelUnlock();
			finger2.changedPosMotor1 = 0;
			osDelay(2);
		}

		if (finger2.changedPosMotor2)
		{
			osKernelLock();
			MotorSetGoalPosition(finger2.huart, &finger2.motor2->id, positions.posFinger2Motor2);
			osKernelUnlock();
			finger2.changedPosMotor2 = 0;
			osDelay(2);
		}

		if (dynamicGrasp.changedPosMotor1)
		{
			osKernelLock();
			MotorSetGoalPosition(dynamicGrasp.huart, &dynamicGrasp.motor1->id, positions.posFinger1Motor0);
			osKernelUnlock();
			dynamicGrasp.changedPosMotor1 = 0;
			osDelay(2);
		}

		if (dynamicGrasp.changedPosMotor2)
		{
			osKernelLock();
			MotorSetGoalPosition(dynamicGrasp.huart, &dynamicGrasp.motor2->id, positions.posFinger2Motor0);
			osKernelUnlock();
			dynamicGrasp.changedPosMotor2 = 0;
			osDelay(2);
		}

		currTick2 = osKernelGetTickCount();
		executionTicks = currTick2 - currTick1;


		osDelay(100);
		//osDelay(1000);


		/*
		 *  DEMO CODE, SWITCHING BETWEEN TWO POSITIONS
		 *


		if (switchPos == 0)
		{

			thumb.changedPosMotor1 = 1;
			thumb.changedPosMotor2 = 1;
			finger1.changedPosMotor1 = 1;
			finger1.changedPosMotor2 = 1;
			finger2.changedPosMotor1 = 1;
			finger2.changedPosMotor2 = 1;
			dynamicGrasp.changedPosMotor1 = 1;
			dynamicGrasp.changedPosMotor2 = 1;

//			*positions.posThumbMotor1 = pos1M1;
//			*positions.posThumbMotor2 = pos1M2;
////			*positions.posFinger1Motor0 = pos1M0;
////			*positions.posFinger2Motor0 = 512 + (512 - pos1M0);
//			*positions.posFinger1Motor1 = pos1M1;
//			*positions.posFinger1Motor2 = pos1M2;
//			*positions.posFinger2Motor1 = pos1M1;
//			*positions.posFinger2Motor2 = pos1M2;

			*positions.posThumbMotor1 = MotorConvertAngle(43594);
			*positions.posThumbMotor2 = MotorConvertAngle(28958);
			*positions.posFinger1Motor0 = MotorConvertAngle(33244);
			*positions.posFinger1Motor1 = MotorConvertAngle(55217);
			*positions.posFinger1Motor2 = MotorConvertAngle(31922);
			*positions.posFinger2Motor0 = MotorConvertAngle(31578);
			*positions.posFinger2Motor1 = MotorConvertAngle(51675);
			*positions.posFinger2Motor2 = MotorConvertAngle(30005);

//			switchPos = 1;
		}
		else if (switchPos == 1)
		{
			thumb.changedPosMotor1 = 1;
			thumb.changedPosMotor2 = 1;
			finger1.changedPosMotor1 = 1;
			finger1.changedPosMotor2 = 1;
			finger2.changedPosMotor1 = 1;
			finger2.changedPosMotor2 = 1;
			dynamicGrasp.changedPosMotor1 = 1;
			dynamicGrasp.changedPosMotor2 = 1;

			*positions.posThumbMotor1 = pos2M1;
			*positions.posThumbMotor2 = pos2M2;
//			*positions.posFinger1Motor0 = pos2M0;
//			*positions.posFinger2Motor0 = 512 + (512 - pos2M0);
			*positions.posFinger1Motor1 = pos2M1;
			*positions.posFinger1Motor2 = pos2M2;
			*positions.posFinger2Motor1 = pos2M1;
			*positions.posFinger2Motor2 = pos2M2;

			gripper.thumbM1.goalPosition = pos2M1;
			gripper.thumbM2.goalPosition = pos2M2;
//			gripper.finger1Motor0.goalPosition = pos2M0;
			gripper.finger1Motor1.goalPosition = pos2M1;
			gripper.finger1Motor2.goalPosition = pos2M2;
//			gripper.finger2Motor0.goalPosition = pos2M0;
			gripper.finger2Motor1.goalPosition = pos2M1;
			gripper.finger2Motor2.goalPosition = pos2M2;

			switchPos = 0;
		}
		/**/

  }
	osThreadExit();
}

