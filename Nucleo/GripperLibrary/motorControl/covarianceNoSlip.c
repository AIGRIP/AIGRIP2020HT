/*
 * covarianceNoSlip.c
 *
 *  Created on: Dec 4, 2020
 *      Author: Lagom med Slip
 */


#include "covarianceNoSlip.h"





void covarianceBasedSlipPrevention (motorPair thumb, motorPair finger1, motorPair finger2, osMessageQueueId_t opticalSensorQueue, UART_HandleTypeDef *debugUART)
{

	uint8_t nrSamples = 10;
	uint8_t newSlip = 0;
	int32_t slip = 0;
	uint8_t buf[18] = {0};
	//uint16_t tempPos;
	sensValue sensor1[nrSamples], sensor2[nrSamples], sensor3[nrSamples], sensor4[nrSamples], sensor5[nrSamples], sensor6[nrSamples];
	float magnitudeSensor1[nrSamples], magnitudeSensor2[nrSamples], magnitudeSensor3[nrSamples], magnitudeSensor4[nrSamples], magnitudeSensor5[nrSamples], magnitudeSensor6[nrSamples];
	float meanSensor1 = 0, meanSensor2 = 0, meanSensor3 = 0, meanSensor4 = 0, meanSensor5 = 0, meanSensor6 = 0;
	float covSensor1 = 0, covSensor2 = 0, covSensor3 = 0, covSensor4 = 0, covSensor5 = 0, covSensor6 = 0;
	motorValues currentPositions = {0};
	motorValues currentLoads;


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
			magnitudeSensor1[i] = (float) (sqrt(pow((double) sensor1[i].mouse_D_X, 2) + pow((double) sensor1[i].mouse_D_Y, 2)));
			magnitudeSensor2[i] = (float) (sqrt(pow((double) sensor2[i].mouse_D_X, 2) + pow((double) sensor2[i].mouse_D_Y, 2)));
			magnitudeSensor3[i] = (float) (sqrt(pow((double) sensor3[i].mouse_D_X, 2) + pow((double) sensor3[i].mouse_D_Y, 2)));
			magnitudeSensor4[i] = (float) (sqrt(pow((double) sensor4[i].mouse_D_X, 2) + pow((double) sensor4[i].mouse_D_Y, 2)));
			magnitudeSensor5[i] = (float) (sqrt(pow((double) sensor5[i].mouse_D_X, 2) + pow((double) sensor5[i].mouse_D_Y, 2)));
			magnitudeSensor6[i] = (float) (sqrt(pow((double) sensor6[i].mouse_D_X, 2) + pow((double) sensor6[i].mouse_D_Y, 2)));

			meanSensor1 += magnitudeSensor1[i];
			meanSensor2 += magnitudeSensor2[i];
			meanSensor3 += magnitudeSensor3[i];
			meanSensor4 += magnitudeSensor4[i];
			meanSensor5 += magnitudeSensor5[i];
			meanSensor6 += magnitudeSensor6[i];
		}

		meanSensor1 = meanSensor1 / nrSamples;
		meanSensor2 = meanSensor2 / nrSamples;
		meanSensor3 = meanSensor3 / nrSamples;
		meanSensor4 = meanSensor4 / nrSamples;
		meanSensor5 = meanSensor5 / nrSamples;
		meanSensor6 = meanSensor6 / nrSamples;


		for (int i=0; i < nrSamples; i++)
		{
			covSensor1 += (magnitudeSensor1[i] - meanSensor1) * (magnitudeSensor2[i] - meanSensor2) * (magnitudeSensor3[i] - meanSensor3);
		}



		// READ: Gather data of each motor regarding grasp
		MotorRead(thumb.huart, buf, thumb.motor1->id, ADDR_PRESENT_POSITION, 2);
		currentPositions.thumbMotor1 = (buf[7] << 8) | buf[6];
		MotorRead(thumb.huart, buf, thumb.motor2->id, ADDR_PRESENT_POSITION, 2);
		currentPositions.thumbMotor2 = (buf[7] << 8) | buf[6];
		MotorRead(finger1.huart, buf, finger1.motor1->id, ADDR_PRESENT_POSITION, 2);
		currentPositions.finger1Motor1 = (buf[7] << 8) | buf[6];
		MotorRead(finger1.huart, buf, finger1.motor2->id, ADDR_PRESENT_POSITION, 2);
		currentPositions.finger1Motor2 = (buf[7] << 8) | buf[6];
		MotorRead(finger2.huart, buf, finger2.motor1->id, ADDR_PRESENT_POSITION, 2);
		currentPositions.finger2Motor1 = (buf[7] << 8) | buf[6];
		MotorRead(finger2.huart, buf, finger2.motor2->id, ADDR_PRESENT_POSITION, 2);
		currentPositions.finger2Motor2 = (buf[7] << 8) | buf[6];


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


	}
}


