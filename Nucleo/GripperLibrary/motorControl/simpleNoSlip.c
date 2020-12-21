/* 
*  --------------------------------------------------------------------------------------
*  Comments in the code marked with '-----' are unfinished, and dependent on other modules
*  Semaphores needs to be implemented for shared resources, but also needs to be dacided upon
*  --------------------------------------------------------------------------------------
*/

#include <math.h>
#include "AX_12A_API.h"
#include "motorControl.h"
#include "cmsis_os.h"
#include "stdio.h"
#include "PMW3360Drivers.h"
#include "simpleNoSlip.h"


#define SLIP_MAX_VALUE 32767    // Upper limit for optical sensor output
#define SLIP_MIN_VALUE -32768   // Lower limit for optical sensor output
#define SLIP_THRESHOLD 100      // Threshold for interpreting output from optical sensors as slippage






/*
uint8_t[NR_GRASP_MOTORS] MotorSetPos();
uint8_t[NR_GRASP_MOTORS] MotorSetForce();
uint8_t[NR_GRASP_MOTORS] MotorReadPos();
uint8_t[NR_GRASP_MOTORS] MotorReadForce();
*/



// Task function for NoSlip
void IfSlipIncreaseForce(motorPair* thumb, motorPair* finger1, motorPair* finger2, osMessageQueueId_t opticalSensorQueue)
{
	//uint8_t torqueLimit                      = 10;           // Aplied force versus instructed force, for when increase of force should be performed
	uint8_t posIncrementMotor1                 = 10;            // Incrementation step for increasing motor position
	uint8_t posIncrementMotor2				   = 5;
	//uint8_t torqueIncrement                  = 2;            // Incrementation step for increasing motor force
	//uint8_t currentForce;
	//uint8_t currentPos;

	uint8_t buf[18] = {0};
	uint8_t newSlip = 0;
	float slip = 0;
	//uint16_t tempPos;

	sensValue sens1, sens2, sens3, sens4, sens5, sens6;
	motorValues currentPositions = {0};
	motorValues currentLoads;

	uint64_t currTick1, currTick2, executionTicks = 0;


	//const char str1[] = "Went to get mesage count.\n\r";
	//HAL_UART_Transmit(debugUART,(uint8_t *) str1, sizeof(str1), 100);

		if (osMessageQueueGetCount(opticalSensorQueue) >= 12)
		{

			// READ FROM REGISTERS -- DMA SHOULD CONSTANTLY READ DATA -------------
			osMessageQueueGet(opticalSensorQueue, &sens1.mouse_D_X, NULL, 0U);
			osMessageQueueGet(opticalSensorQueue, &sens1.mouse_D_Y, NULL, 0U);

			osMessageQueueGet(opticalSensorQueue, &sens2.mouse_D_X, NULL, 0U);
			osMessageQueueGet(opticalSensorQueue, &sens2.mouse_D_Y, NULL, 0U);

			osMessageQueueGet(opticalSensorQueue, &sens3.mouse_D_X, NULL, 0U);
			osMessageQueueGet(opticalSensorQueue, &sens3.mouse_D_Y, NULL, 0U);

			osMessageQueueGet(opticalSensorQueue, &sens4.mouse_D_X, NULL, 0U);
			osMessageQueueGet(opticalSensorQueue, &sens4.mouse_D_Y, NULL, 0U);

			osMessageQueueGet(opticalSensorQueue, &sens5.mouse_D_X, NULL, 0U);
			osMessageQueueGet(opticalSensorQueue, &sens5.mouse_D_Y, NULL, 0U);

			osMessageQueueGet(opticalSensorQueue, &sens6.mouse_D_X, NULL, 0U);
			osMessageQueueGet(opticalSensorQueue, &sens6.mouse_D_Y, NULL, 0U);

			/*
			//Deubg Message queue
			const short buffLength = 60;
			char messageBuffer[buffLength];
			short bufferStringLength;
			memset((char *) messageBuffer,0,buffLength);
			sprintf(messageBuffer,"Debug slipnot mouse in x %hu, y %hu \n\r",sens1.mouse_D_X,sens1.mouse_D_Y);
			bufferStringLength = strlen(messageBuffer);
			*/



			// CALCULATE AVERAGE MOVEMENT VECTOR MAGNITUDE -- SHOULD ADD FAILSAFE IF A SENSOR IS NOT WORKING/ALIGNED --------------
			slip = (float) (sqrt(pow((double) sens1.mouse_D_X, 2) + pow((double) sens1.mouse_D_Y, 2)) +
					sqrt(pow((double) sens2.mouse_D_X, 2) + pow((double) sens2.mouse_D_Y, 2)) +
					sqrt(pow((double) sens3.mouse_D_X, 2) + pow((double) sens3.mouse_D_Y, 2)) +
					sqrt(pow((double) sens4.mouse_D_X, 2) + pow((double) sens4.mouse_D_Y, 2)) +
					sqrt(pow((double) sens5.mouse_D_X, 2) + pow((double) sens5.mouse_D_Y, 2)) +
					sqrt(pow((double) sens6.mouse_D_X, 2) + pow((double) sens6.mouse_D_Y, 2))
					) / NUMBER_OF_MOUSE_SESNORS;

			/*
			currTick1 = osKernelGetTickCount();

			// READ: Gather data of each motor regarding grasp
			MotorRead(thumb->huart, buf, thumb->motor1->id, ADDR_PRESENT_POSITION, 2);
			currentPositions.thumbMotor1 = (buf[7] << 8) | buf[6];
			MotorRead(thumb->huart, buf, thumb->motor2->id, ADDR_PRESENT_POSITION, 2);
			currentPositions.thumbMotor2 = (buf[7] << 8) | buf[6];
			MotorRead(finger1->huart, buf, finger1->motor1->id, ADDR_PRESENT_POSITION, 2);
			currentPositions.finger1Motor1 = (buf[7] << 8) | buf[6];
			MotorRead(finger1->huart, buf, finger1->motor2->id, ADDR_PRESENT_POSITION, 2);
			currentPositions.finger1Motor2 = (buf[7] << 8) | buf[6];
			MotorRead(finger2->huart, buf, finger2->motor1->id, ADDR_PRESENT_POSITION, 2);
			currentPositions.finger2Motor1 = (buf[7] << 8) | buf[6];
			MotorRead(finger2->huart, buf, finger2->motor2->id, ADDR_PRESENT_POSITION, 2);
			currentPositions.finger2Motor2 = (buf[7] << 8) | buf[6];


			MotorRead(thumb->huart, buf, thumb->motor1->id, ADDR_PRESENT_LOAD, 2);
			currentLoads.thumbMotor1 = (buf[7] << 8) | buf[6];
			MotorRead(thumb->huart, buf, thumb->motor2->id, ADDR_PRESENT_LOAD, 2);
			currentLoads.thumbMotor2 = (buf[7] << 8) | buf[6];
			MotorRead(finger1->huart, buf, finger1->motor1->id, ADDR_PRESENT_LOAD, 2);
			currentLoads.finger1Motor1 = (buf[7] << 8) | buf[6];
			MotorRead(finger1->huart, buf, finger1->motor2->id, ADDR_PRESENT_LOAD, 2);
			currentLoads.finger1Motor2 = (buf[7] << 8) | buf[6];
			MotorRead(finger2->huart, buf, finger2->motor1->id, ADDR_PRESENT_LOAD, 2);
			currentLoads.finger2Motor1 = (buf[7] << 8) | buf[6];
			MotorRead(finger2->huart, buf, finger2->motor2->id, ADDR_PRESENT_LOAD, 2);
			currentLoads.finger2Motor2 = (buf[7] << 8) | buf[6];

			currTick2 = osKernelGetTickCount() - currTick1;
			*/
			/*
			sprintf(messageBuffer, "Average Movement Magnitude: %lu \n\r", slip);
			bufferStringLength = strlen(messageBuffer);


			HAL_UART_Transmit(debugUART,(uint8_t *) messageBuffer, bufferStringLength, 100);
			*/


			if (slip > SLIP_THRESHOLD)
			{

				//if ((currentLoads.thumbMotor1) < (thumb.motor1->torqueLimitRAM - torqueIncrement))
				//{
				//	MotorSetTorqueLimit(thumb.huart, &thumb.motor1->id, (uint16_t*) (currentLoads.thumbMotor1 + torqueIncrement));
				//}
				//else
				//if (currentPositions.thumbMotor1 < (thumb.motor1->goalPosition - thumb.motor1->cwComplianceMargin - posIncrement))
				//{
					//tempPos = thumb.motor1->goalPosition + posIncrement;

					/*
					sprintf(messageBuffer, "Updating motor position: %u \n\r", tempPos);
					bufferStringLength = strlen(messageBuffer);

					HAL_UART_Transmit(debugUART,(uint8_t *) messageBuffer, bufferStringLength, 100);
					 */


				/***************************************************
				 * *************************************************
				 * ADD DIFFERENT CASES FOR BDG, SDG AND BFDLR GRASPS
				 * *************************************************
				 ***************************************************/
				thumb->changedPosMotor1 = 1;
				thumb->motor1->goalPosition -= posIncrementMotor1;
				//MotorSetGoalPosition(thumb.huart, &thumb.motor1->id, &thumb.motor1->goalPosition);
				thumb->motor2->goalPosition -= posIncrementMotor2;
				thumb->changedPosMotor2 = 1;
				//MotorSetGoalPosition(thumb.huart, &thumb.motor2->id, &thumb.motor2->goalPosition);

				finger1->motor1->goalPosition -= posIncrementMotor1;
				finger1->changedPosMotor1 = 1;
				//MotorSetGoalPosition(finger1.huart, &finger1.motor1->id, &finger1.motor1->goalPosition);
				finger1->motor2->goalPosition -= posIncrementMotor2;
				finger1->changedPosMotor2 = 1;
				//MotorSetGoalPosition(finger2.huart, &finger1.motor2->id, &finger2.motor2->goalPosition);

				finger2->motor1->goalPosition -= posIncrementMotor1;
				finger2->changedPosMotor1 = 1;
				//MotorSetGoalPosition(finger2.huart, &finger2.motor1->id, &finger2.motor1->goalPosition);
				finger2->motor2->goalPosition -= posIncrementMotor2;
				finger2->changedPosMotor2 = 1;
				//MotorSetGoalPosition(finger2.huart, &finger2.motor2->id, &finger2.motor2->goalPosition);

				newSlip = 1;

			}
			else if (newSlip == 1)
			{
				//newPos = MotorSetPos(currentPos, 0);
				//newForce = MotorSetForce(currentForce, 0);

				newSlip = 0;
			}
		}
        // --- ADD LOG OF NEW MOTOR INSTRUCTIONS --------
        // log newPos, newForce --- should current status be logged here of handled by DMA? -----

        osDelay(1);

    // Catch unexpected termination
    //osThreadExit();
}
