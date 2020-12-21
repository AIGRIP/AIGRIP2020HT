/*
 * I2CCommunication.c
 *
 *  Created on: Nov 17, 2020
 *      Author: AutoBike01
 */

#include "I2CCommunication.h"

// Change to a general header!!!!!!



void I2CCommunicationHandle( I2C_HandleTypeDef *hi2cHandle, osSemaphoreId_t semaforMotorCommand, osMessageQueueId_t messageQueueControlHandle )
{
	/*
	 * Take care of all I2C communication between Nucleo and other boards.
	 */

	// Set up time variables.
	const uint32_t deadlineCommunication = 2000;
	const uint32_t communicationSleepTime = 300;
	uint32_t transmitionStatus;
	uint32_t lastTransmitTime = osKernelGetTickCount();

	uint64_t currTick1, currTick2, executionTicks = 0;

	while(1)
	{
		currTick1 = osKernelGetTickCount();

		// Check if for new incoming I2C messages.

		// Handle received I2C data.
		I2CCommandHandle(hi2cHandle,semaforMotorCommand, messageQueueControlHandle);

		currTick2 = osKernelGetTickCount();

		if ((currTick2 - currTick1) > executionTicks)
		{
			executionTicks = currTick2 - currTick1;
		}
/*
		// Check if it is time to do a new transmit.
		if( (lastTransmitTime + deadlineCommunication) <= osKernelGetTickCount() )
		{

			// Transmit data from Nucleo.
			transmitionStatus = I2CTransmitHandle(hi2cHandle);

			// Check if the data were transmitted.
			if(transmitionStatus == 0)
			{
				lastTransmitTime = osKernelGetTickCount();
			}
		}
*/
		// Communication task sleep.
		osDelay(communicationSleepTime);

	}
}




void I2CCommandHandle( I2C_HandleTypeDef *hi2cHandle, osSemaphoreId_t semaforMotorCommand, osMessageQueueId_t messageQueueControlHandle )
{
	/*
	 * Handles all received I2C messages. It reads the first 2 bytes as a frame.
	 * Then depending on the frame type it handle the command requested from the master.
	 */

	// Standard receive packages.
	messageStructHeaderFromNano messageHeaderFromNano;
	messageI2CToNucleoMotor motorValues;

	// Indicate status of I2C.
	int I2CReceiveStatus,i;


	// Suspend all other task from interrupt while reading.
	osKernelLock();
	// Check if new I2C messages is available.
	I2CReceiveStatus = HAL_I2C_Slave_Receive(hi2cHandle, (uint8_t *) &messageHeaderFromNano, (uint16_t) sizeof(messageStructHeaderFromNano), (uint32_t) 100);
	osKernelUnlock();


	// If there is a message, follow the instructions dependent of the type of message.
	if( I2CReceiveStatus == 0 )
	{

		// This switch case take care of each request from the master.
		switch(messageHeaderFromNano.frameType)
		{

			case 1:
			{
				// Should start the gripper
				uint16_t sendBuff = 1;

				if (osMessageQueueGetSpace(messageQueueControlHandle) > 0)
				{
					if (osSemaphoreAcquire( semaforMotorCommand, 200) == osOK)
					{
						osMessageQueuePut(messageQueueControlHandle,(uint16_t *) &sendBuff, 1, 10);
					}
					osSemaphoreRelease(semaforMotorCommand);
				}

			}
				break;

			case 2:
			{
				// Should stop the gripper and set it to the standby mode.
				uint16_t sendBuff = 2;

				if (osMessageQueueGetSpace(messageQueueControlHandle) > 0)
				{
					if (osSemaphoreAcquire( semaforMotorCommand, 200) == osOK)
					{
						osMessageQueuePut(messageQueueControlHandle,(uint16_t *) &sendBuff, 1, 10);
					}
					osSemaphoreRelease(semaforMotorCommand);
				}

			}
				break;

			case 3:
			{
				// Should set the gripper to release mode.
			}
				break;

			case 4:
			{
				// Should pause the gripper in its current stage.
			}
				break;

			case 5:
			{
				// Should handle recommended motor commands from the Nano.

				osKernelLock();
				// Check if new I2C messages is available.
				I2CReceiveStatus = HAL_I2C_Slave_Receive(hi2cHandle, (uint8_t *) &motorValues, (uint16_t) sizeof(messageI2CToNucleoMotor), (uint32_t) 2000);
				osKernelUnlock();
				for (int i = 0; i < NUMBER_OF_MOTORS; i++)
				{
					if (motorValues.motorAngle[i] == 0)
					{
						return;
					}
				}

  				uint16_t sendBuff = 5;

				// Prevent the control task to preempt while sending motor commands to it,

				if (osMessageQueueGetSpace(messageQueueControlHandle) >= (1 + NUMBER_OF_MOTORS) )
				{
					if (osSemaphoreAcquire( semaforMotorCommand, 100) == osOK)
					{
						// Send message frame to control task.
						osMessageQueuePut(messageQueueControlHandle,(uint16_t *) &sendBuff, 1, 10);
						// Send desired motor position to the control task.
						for( i=0;i<NUMBER_OF_MOTORS;i++)
						{
							osMessageQueuePut(messageQueueControlHandle,(uint16_t *) &motorValues.motorAngle[i], 1, 10);
						}

						// Release semaphore.
						osSemaphoreRelease(semaforMotorCommand);
					}
				}

			}
			break;

			default:
			{
				// Should Flush all I2C messages.
				HAL_I2C_Init(hi2cHandle);
			}
				break;
		}
	}else{
		// Indicate that there was no data in the I2C buffer.
		// HAL_UART_Transmit(uartDebugHandle,(uint8_t *) strF, sizeof(strF), 10);

		// Have to reset I2C if there was no message available...
		osKernelLock();
		HAL_I2C_Init(hi2cHandle);
		osKernelUnlock();
	}

}



uint32_t I2CTransmitHandle( I2C_HandleTypeDef *hi2cHandle )
{
	// This function handles the I2C transmition to other controllers.
	// It sends the sensor/motor values and status of the gripper.
	//
	// On success it return the transmition time.
	// On failure it return 0.

	// Transmit struct for Nucleo.
	messageStructFromNucleo messageFormNucleo;

	// Indicate status of I2C transmition.
	int transStatus;

	// Is to debug communication with receiver.

	int i;

	for( i=0;i<NUMBER_OF_MOTORS;i++)
	{
		messageFormNucleo.motorStatus[i] = i;
	}

	for( i=0;i<NUMBER_OF_PROXIMITY_SENSORS;i++)
	{
		messageFormNucleo.proximitySensor[i] = i;
	}


	for( i=0;i<NUMBER_OF_MOUSE_SESNORS;i++)
	{
		messageFormNucleo.mouseSensor[i].XMagnitud = i;
		messageFormNucleo.mouseSensor[i].YMagnitud = i;
	}

	messageFormNucleo.statusOfNucelo = 1;

	// Suspend all other task from interrupt, while transmitting..
	// Transmit the data from Nucleo.
	osKernelLock();
	transStatus = HAL_I2C_Slave_Transmit(hi2cHandle,(uint8_t *) &messageFormNucleo, sizeof(messageStructFromNucleo), 100);
	osKernelUnlock();

	//Print transmit status.
	if(transStatus == 0)
	{
		// Return the latest transmit time.
		return osKernelGetTickCount();

	}else{

		// osKernelLock();
		// HAL_I2C_Init(hi2cHandle);
		// osKernelUnlock();

		// Transmit debug message.
		// HAL_UART_Transmit(uartDebugHandle,(uint8_t *) str2, sizeof(str2), 50);
		// Return error value.
		return 0;
	}

}
