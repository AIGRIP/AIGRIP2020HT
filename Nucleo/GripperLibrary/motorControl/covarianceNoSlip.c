/*
 * covarianceNoSlip.c
 *
 *  Created on: Dec 4, 2020
 *      Author: Lagom med Slip
 */


#include "covarianceNoSlip.h"
#include "string.h"





void covarianceBasedSlipPrevention (motorPair *thumb, motorPair *finger1, motorPair *finger2, osMessageQueueId_t opticalSensorQueue, UART_HandleTypeDef *debugUART)
{

	uint8_t nrSamples = 10;
	uint8_t nrSensors  = 6;
	// -----------------------------------
	// Covariance threshold needs tweaking
	//------------------------------------
	float covarianceThreshold = 0.2;
	uint8_t covThresholdReached = 0;
	uint8_t posIncrement                    = 2;            // Incrementation step for increasing motor position
	uint8_t newSlip = 0;
	int32_t slip = 0;
	uint8_t buf[18] = {0};
	//uint16_t tempPos;
	sensValue sensor1[nrSamples], sensor2[nrSamples], sensor3[nrSamples], sensor4[nrSamples], sensor5[nrSamples], sensor6[nrSamples];
	//float magnitudeSensor1[nrSamples], magnitudeSensor2[nrSamples], magnitudeSensor3[nrSamples], magnitudeSensor4[nrSamples], magnitudeSensor5[nrSamples], magnitudeSensor6[nrSamples];
	//float meanSensor1 = 0, meanSensor2 = 0, meanSensor3 = 0, meanSensor4 = 0, meanSensor5 = 0, meanSensor6 = 0;
	//float covSensor1[nrSensors] = 0, covSensor2[nrSensors] = 0, covSensor3[nrSensors] = 0, covSensor4[nrSensors] = 0, covSensor5[nrSensors] = 0, covSensor6[nrSensors] = 0;
	float magnitudeSensor[nrSensors][nrSamples];
	float meanSensor[nrSensors];
	float covSensor[nrSensors][nrSamples];
	motorValues currentPositions = {0};
	motorValues currentLoads;

	memset(magnitudeSensor, 0, sizeof(magnitudeSensor));
	memset(meanSensor, 0, sizeof(meanSensor));
	memset(covSensor, 0, sizeof(covSensor));


	if (osMessageQueueGetCount(opticalSensorQueue) >= (12 * nrSamples))
	{
		for (int i=0; i < nrSamples; i++)
		{
			osMessageQueueGet(opticalSensorQueue, &sensor1[i].mouse_D_X, NULL, 5);
			osMessageQueueGet(opticalSensorQueue, &sensor1[i].mouse_D_Y, NULL, 5);

			osMessageQueueGet(opticalSensorQueue, &sensor2[i].mouse_D_X, NULL, 5);
			osMessageQueueGet(opticalSensorQueue, &sensor2[i].mouse_D_Y, NULL, 5);

			osMessageQueueGet(opticalSensorQueue, &sensor3[i].mouse_D_X, NULL, 5);
			osMessageQueueGet(opticalSensorQueue, &sensor3[i].mouse_D_Y, NULL, 5);

			osMessageQueueGet(opticalSensorQueue, &sensor4[i].mouse_D_X, NULL, 5);
			osMessageQueueGet(opticalSensorQueue, &sensor4[i].mouse_D_Y, NULL, 5);

			osMessageQueueGet(opticalSensorQueue, &sensor5[i].mouse_D_X, NULL, 5);
			osMessageQueueGet(opticalSensorQueue, &sensor5[i].mouse_D_Y, NULL, 5);

			osMessageQueueGet(opticalSensorQueue, &sensor6[i].mouse_D_X, NULL, 5);
			osMessageQueueGet(opticalSensorQueue, &sensor6[i].mouse_D_Y, NULL, 5);


			// CALCULATE AVERAGE MOVEMENT VECTOR MAGNITUDE -- SHOULD ADD FAILSAFE IF A SENSOR IS NOT WORKING/ALIGNED --------------
			magnitudeSensor[0][i] = (float) (sqrt(pow((double) sensor1[i].mouse_D_X, 2) + pow((double) sensor1[i].mouse_D_Y, 2)));
			magnitudeSensor[1][i] = (float) (sqrt(pow((double) sensor2[i].mouse_D_X, 2) + pow((double) sensor2[i].mouse_D_Y, 2)));
			magnitudeSensor[2][i] = (float) (sqrt(pow((double) sensor3[i].mouse_D_X, 2) + pow((double) sensor3[i].mouse_D_Y, 2)));
			magnitudeSensor[3][i] = (float) (sqrt(pow((double) sensor4[i].mouse_D_X, 2) + pow((double) sensor4[i].mouse_D_Y, 2)));
			magnitudeSensor[4][i] = (float) (sqrt(pow((double) sensor5[i].mouse_D_X, 2) + pow((double) sensor5[i].mouse_D_Y, 2)));
			magnitudeSensor[5][i] = (float) (sqrt(pow((double) sensor6[i].mouse_D_X, 2) + pow((double) sensor6[i].mouse_D_Y, 2)));

			meanSensor[0] += magnitudeSensor[0][i];
			meanSensor[1] += magnitudeSensor[1][i];
			meanSensor[2] += magnitudeSensor[2][i];
			meanSensor[3] += magnitudeSensor[3][i];
			meanSensor[4] += magnitudeSensor[4][i];
			meanSensor[5] += magnitudeSensor[5][i];
		}

		meanSensor[0] = meanSensor[0] / nrSamples;
		meanSensor[1] = meanSensor[1] / nrSamples;
		meanSensor[2] = meanSensor[2] / nrSamples;
		meanSensor[3] = meanSensor[3] / nrSamples;
		meanSensor[4] = meanSensor[4] / nrSamples;
		meanSensor[5] = meanSensor[5] / nrSamples;



		// Calculate covariance between all sensor pairs
		for (int j=0; j < nrSensors; j++)
		{
			for (int k=0; k < nrSensors; k++)
			{
				for (int i=0; i < nrSamples; i++)
				{
					covSensor[j][k] += (magnitudeSensor[j][i] - meanSensor[j]) * (magnitudeSensor[k][i] - meanSensor[k]);
				}
				covSensor[j][k] /= nrSamples;
			}
		}


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


		/* ----------------------------------------------------------
		 *  The current load values did not provide reliable data
		 * ----------------------------------------------------------
		MotorRead(thumb.huart, buf, thumb.motor1->id, ADDR_PRESENT_LOAD, 2);
		currentLoads.thumbMotor1 = (buf[7] << 8) | buf[6];
		MotorRead(thumb.huart, buf, thumb.motor2->id, ADDR_PRESENT_LOAD, 2);
		currentLoads.thumbMotor2 = (buf[7] << 8) | buf[6];
		MotorRead(finger1.huart, buf, finger1.motor1->id, ADDR_PRESENT_LOAD, 2);
		currentLoads.finger1Motor1 = (buf[7] << 8) | buf[6];
		MotorRead(finger1.huart, buf, finger1.motor2->id, ADDR_PRESENT_LOAD, 2);
		currentLoads.finger1Motor2 = (buf[7] << 8) | buf[6];
		MotorRead(finger2.huart, buf, finger2.motor1->id, ADDR_PRESENT_LOAD, 2);
		currentLoads.finger2Motor1 = (buf[7] << 8) | buf[6];
		MotorRead(finger2.huart, buf, finger2.motor2->id, ADDR_PRESENT_LOAD, 2);
		currentLoads.finger2Motor2 = (buf[7] << 8) | buf[6];
		*/






		/***************************************************************************
		 * THE SENSOR NUMBERS NEED TO BE VALIDATED FOR CORRECT FINGERS
		 *
		 * SELECTION OF VALID SENSORS DEPENDING ON PROXIMITY SENSORS SHOULD BE ADDED
		 ***************************************************************************/

		// Increase force of the fingers that detect incipient slippage
		for (int k=0; k < nrSensors; k++)
		{
			if (covSensor[0][k] > covarianceThreshold || covSensor[1][k] > covarianceThreshold)
			{
				thumb->motor1->goalPosition -= posIncrement;
				thumb->changedPosMotor1 = 1;
				thumb->motor2->goalPosition -= 1;
				thumb->changedPosMotor2 = 1;
				covThresholdReached = 1;
			}
			if (covSensor[2][k] > covarianceThreshold || covSensor[3][k] > covarianceThreshold)
			{
				finger1->motor1->goalPosition -= posIncrement;
				finger1->changedPosMotor1 = 1;
				finger1->motor2->goalPosition -= 1;
				finger1->changedPosMotor2 = 1;
				covThresholdReached = 1;
			}
			if (covSensor[4][k] > covarianceThreshold || covSensor[5][k] > covarianceThreshold)
			{
				finger2->motor1->goalPosition -= posIncrement;
				finger2->changedPosMotor1 = 1;
				finger2->motor2->goalPosition -= 1;
				finger2->changedPosMotor2 = 1;
				covThresholdReached = 1;
			}
			if (covThresholdReached)
			{
				break;
			}
		}

	}
}


