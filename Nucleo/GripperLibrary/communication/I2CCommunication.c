/*
 * I2CCommunication.c
 *
 *  Created on: Nov 17, 2020
 *      Author: AutoBike01
 */

#include "I2CCommunication.h"






void I2CCommunicationHandle( I2C_HandleTypeDef *hi2cHandle, UART_HandleTypeDef *uartDebugHandle )
{
	/*
	 * Take care of all I2C communication between Nucleo and other boards.
	 */

	// Set up time variables.
	const uint32_t deadlineCommunication = 2000;
	const uint32_t communicationSleepTime = 25;
	uint32_t transmitionStatus;
	uint32_t lastTransmitTime = osKernelGetTickCount();

	// Indicate that I2C communication is started.
	const char str0[] = "Starting I2C Communication.\n\r";
	HAL_UART_Transmit(uartDebugHandle,(uint8_t *) str0, sizeof(str0), 50);

	while(1)
	{

		// Check if for new incoming I2C messages.

		// Handle received I2C data.
		I2CCommandHandle(hi2cHandle,uartDebugHandle);

		// Check if it is time to do a new transmit.
		if( (lastTransmitTime + deadlineCommunication) <= osKernelGetTickCount() )
		{


			// Transmit data from Nucleo.
			transmitionStatus = I2CTransmitHandle(hi2cHandle,uartDebugHandle);

			// Check if the data were transmitted.
			if(transmitionStatus != 0)
			{
				lastTransmitTime = transmitionStatus;
			}
		}

		// Communication task sleep.
		osDelay(communicationSleepTime);


	}



}




void I2CCommandHandle( I2C_HandleTypeDef *hi2cHandle, UART_HandleTypeDef *uartDebugHandle )
{
	/*
	 * Handles all received I2C messages. It reads the first 2 bytes as a frame.
	 * Then depending on the frame type it handle the command requested from the master.
	 */

	// Debug messages.
	const char strF[] = "I2C buffer is empty.\n\r";
	const char str0[] = "Undefined command.\n\r";
	const char str1[] = "Start the gripper.\n\r";
	const char str2[] = "Stop the gripper.\n\r";
	const char str3[] = "Release object.\n\r";
	const char str4[] = "Pause the gripper.\n\r";
	const char str5[] = "Set motor angle.\n\r";

	//int arrSize = 30;
	//char nrBuff[arrSize];

	// Standard receive packages.
	messageStructHeaderFromNano messageHeaderFromNano;


	// Indicate status of I2C.
	int I2CReceiveStatus;


	// Suspend all other task from interrupt while reading.
	osKernelLock();
	// Check if new I2C messages is available.
	I2CReceiveStatus = HAL_I2C_Slave_Receive(hi2cHandle, (uint8_t *) &messageHeaderFromNano, (uint16_t) sizeof(messageStructHeaderFromNano), (uint32_t) 1);
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
				HAL_UART_Transmit(uartDebugHandle,(uint8_t *) str1, sizeof(str1), 50);
			}
				break;

			case 2:
			{
				// Should stop the gripper and set it to the standby mode.
				HAL_UART_Transmit(uartDebugHandle,(uint8_t *) str2, sizeof(str2), 100);
			}
				break;

			case 3:
			{
				// Should set the gripper to release mode.
				HAL_UART_Transmit(uartDebugHandle,(uint8_t *) str3, sizeof(str3), 100);
			}
				break;

			case 4:
			{
				// Should pause the gripper in its current stage.
				HAL_UART_Transmit(uartDebugHandle,(uint8_t *) str4, sizeof(str4), 100);
			}
				break;

			case 5:
			{
				// Should handle recommended motor commands from the Nano.
				HAL_UART_Transmit(uartDebugHandle,(uint8_t *) str5, sizeof(str5), 100);
			}
				break;

			default:
			{
				// Should Flush all I2C messages.
				HAL_I2C_Init(hi2cHandle);
				HAL_UART_Transmit(uartDebugHandle,(uint8_t *) str0, sizeof(str0), 100);
			}
				break;
		}
	}else{
		// Indicate that there was no data in the I2C buffer.
		HAL_UART_Transmit(uartDebugHandle,(uint8_t *) strF, sizeof(strF), 10);

		// Have to reset I2C if there was no message available...
		HAL_I2C_Init(hi2cHandle);

	}

}



uint32_t I2CTransmitHandle( I2C_HandleTypeDef *hi2cHandle, UART_HandleTypeDef *uartDebugHandle )
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

	// Debug messages.
	const char str1[] = "Transmit Success.\n\r";
	const char str2[] = "Transmit Failure.\n\r";
	const char str3[] = "About to transmit.\n\r";

	// Is to debug communication with receiver.
	messageFormNucleo.motorStatus[0] = 1;
	messageFormNucleo.motorStatus[1] = 3;
	messageFormNucleo.motorStatus[2] = 3;
	messageFormNucleo.motorStatus[3] = 7;


	// Suspend all other task from interrupt, while transmitting..
	osKernelLock();
	// Indicate that a I2C transimtion is about to happen.
	HAL_UART_Transmit(uartDebugHandle,(uint8_t *) str3, sizeof(str1), 150);
	osKernelUnlock();

	// Need to reset I2C before transmition, don't know why...

	// Transmit the data from Nucleo.
	transStatus = HAL_I2C_Slave_Transmit(hi2cHandle,(uint8_t *) &messageFormNucleo, sizeof(messageStructFromNucleo), 100);

	//Print transmit status.
	if(transStatus == 0)
	{
		// Transmit gripper information.
		HAL_UART_Transmit(uartDebugHandle,(uint8_t *) str1, sizeof(str1), 50);

		// Toggle orange led to see transmition.
		HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_1);

		// Return the latest transmit time.
		return osKernelGetTickCount();

	}else{

		// Transmit debug message.
		HAL_UART_Transmit(uartDebugHandle,(uint8_t *) str2, sizeof(str2), 50);
		// Return error value.
		return 0;
	}

}
