/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#include "stm32h7xx_hal_rcc.h"
#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "AX_12A_API.h"
#include "motorControl.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

SPI_HandleTypeDef hspi4;

UART_HandleTypeDef huart4;
UART_HandleTypeDef huart5;
UART_HandleTypeDef huart7;
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;
DMA_HandleTypeDef hdma_uart5_rx;

PCD_HandleTypeDef hpcd_USB_OTG_FS;

/* USER CODE BEGIN PV */
/*
// Motor AX-12A instructions
const uint8_t MOTOR_HEADER =		0xFF;
const uint8_t MOTOR_ID_BROADCAST = 	0xFE;
const uint8_t MOTOR_PING = 			0x01;
const uint8_t MOTOR_READ = 			0x02;
const uint8_t MOTOR_WRITE = 		0x03;
const uint8_t MOTOR_REG_WRITE = 	0x04;
const uint8_t MOTOR_ACTION = 		0x05;
const uint8_t MOTOR_FAC_RESET = 	0x06;
const uint8_t MOTOR_REBOOT = 		0x08;
const uint8_t MOTOR_SYNC_WRITE =	0x83;
const uint8_t MOTOR_BULK_READ = 	0x92;


// Motor AX-12A register addresses
// ----- ROM ADDRESSES ----------
const uint8_t ADDR_MODEL_NUMBER = 			0;
const uint8_t ADDR_FIRMWARE_VERSION = 		2;
const uint8_t ADDR_ID = 					3;
const uint8_t ADDR_BAUD_RATE = 				4;
const uint8_t ADDR_RETURN_DELAY = 			5;
const uint8_t ADDR_CW_ANGLE_LIMIT = 		6;
const uint8_t ADDR_CCW_ANGLE_LIMIT = 		8;
const uint8_t ADDR_TEMPERATURE_LIMIT = 		11;
const uint8_t ADDR_MIN_VOLTAGE_LIMIT = 		12;
const uint8_t ADDR_MAX_VOLTAGE_LIMIT = 		13;
const uint8_t ADDR_MAX_TORQUE = 			14;
const uint8_t ADDR_STATUS_RETURN = 			16;
const uint8_t ADDR_ALARM_LED = 				17;
const uint8_t ADDR_SHUTDOWN = 				18;

// ----- RAM ADDRESSES ---------
const uint8_t ADDR_TORQUE_ENABLE = 			24;
const uint8_t ADDR_LED = 					25;
const uint8_t ADDR_CW_COMPLIANCE_MARGIN = 	26;
const uint8_t ADDR_CCW_COMPLIANCE_MARGIN = 	27;
const uint8_t ADDR_CW_COMPLIANCE_SLOPE = 	28;
const uint8_t ADDR_CCW_COMPLIANCE_SLOPE = 	29;
const uint8_t ADDR_GOAL_POSITION = 			30;
const uint8_t ADDR_MOVING_SPEED = 			32;
const uint8_t ADDR_TORQUE_LIMIT = 			34;
const uint8_t ADDR_PRESENT_POSITION = 		36;
const uint8_t ADDR_PRESENT_SPEED = 			38;
const uint8_t ADDR_PRESENT_LOAD = 			40;
const uint8_t ADDR_PRESENT_VOLTAGE = 		42;
const uint8_t ADDR_PRESENT_TEMPERATURE = 	43;
const uint8_t ADDR_REGISTERED = 			44;
const uint8_t ADDR_MOVING = 				46;
const uint8_t ADDR_LOCK = 					47;
const uint8_t ADDR_PUNCH = 					48;



uint16_t DELAY_TRANSMIT = 200;



uint8_t ROM_WRITE = 1;
uint8_t FAILURE = 0;
*/
//#define PACKAGE_LENGTH 9

struct sensValue{

	bool mouseMotion;

    int16_t mouse_D_X;
    int16_t mouse_D_Y;



}typedef sensValue;


struct motorData
{
    // Motor
    uint8_t sendStatus;
    uint8_t receiveStatus;
    uint8_t sendPack[PACKAGE_LENGTH];
    uint8_t recPack[PACKAGE_LENGTH];
}typedef motorData;
/*
struct motorConfiguration
{
	uint8_t id;
	uint16_t cwAngleLimit;
	uint16_t ccwAngleLimit;
	uint16_t maxTorque;

	uint8_t startCwComplianceMargin;
	uint8_t startCcwComplianceMargin;
	uint8_t startCwComplianceSlope;
	uint8_t startCcwComplianceSlope;
	//uint8_t startPosition[2];
	uint16_t startPosition;
	uint16_t startSpeed;
	uint16_t startTorqueLimitRAM;

	uint8_t torqueEnable;
	uint8_t cwComplianceMargin;
	uint8_t ccwComplianceMargin;
	uint8_t cwComplianceSlope;
	uint8_t ccwComplianceSlope;
	uint16_t goalPosition;
	uint16_t movingSpeed;
	uint16_t torqueLimitRAM;
	uint8_t lockEEPROM;
	uint16_t punch;


}typedef motorConfiguration;
*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_SPI4_Init(void);
static void MX_UART7_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_UART5_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_UART4_Init(void);
static void MX_USB_OTG_FS_PCD_Init(void);
/* USER CODE BEGIN PFP */

void MotorController(void *argument);
void plotSensorData(motorData *dataToPlot );
/*
int MotorInitConfig (UART_HandleTypeDef huart,uint8_t *id, motorConfiguration *motor);
int motorInstrChecksum(uint8_t *frame, uint8_t bytesToSend);



// Motor configuration functions
int MotorSetAngleLimit(UART_HandleTypeDef huart, uint8_t *id, uint16_t *cwLimit, uint16_t *ccwLimit); // 0x00 - 0x3FF
int MotorSetMaxTorque(UART_HandleTypeDef huart, uint8_t *id, uint16_t *maxTorque);		// 0x00 - 0x3FF
int MotorSetTorqueEnable(UART_HandleTypeDef huart, uint8_t *id, uint8_t *enableMotor); 		// Activate torque: 0 = OFF, 1 = ON
int MotorSetComplianceMargin(UART_HandleTypeDef huart, uint8_t *id, uint8_t *cwComplianceMargin, uint8_t *ccwComplianceMargin);	// 0x00 - 0xFF
int MotorSetComplianceSlope(UART_HandleTypeDef huart, uint8_t *id, uint8_t *cwComplianceSlope, uint8_t *ccwComplianceSlope);	// 0x00 - 0xFF
int MotorSetGoalPosition(UART_HandleTypeDef huart, uint8_t *id, uint16_t *goalPosition);	// 0x00 - 0x3FF
int MotorSetMovingSpeed(UART_HandleTypeDef huart, uint8_t *id, uint16_t *movingSpeed);	// 0x00 - 0x3FF
int MotorSetTorqueLimit(UART_HandleTypeDef huart, uint8_t *id, uint16_t *torqueLimit); 	// 0x00 - 0x3FF
int MotorSetLock(UART_HandleTypeDef huart, uint8_t *id, uint8_t *lockROM); 	// Lock EEPROM area: 0 = modifiable, 1 = locked ---- IF LOCK IS SET TO 1, POWER MUST BE SWITCHED OFF AND BACK ON TO CHANGE IT BACK TO 0 -----
int MotorSetPunch(UART_HandleTypeDef huart, uint8_t *id, uint16_t *minCurrentThreshold); 	// 0x20 - 0x3FF Minimum current to drive the motor ---- DEFAULT = 32 ----
int MotorSetId(UART_HandleTypeDef huart, uint8_t *id, uint8_t *newId);

*/




/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART3_UART_Init();
  MX_SPI4_Init();
  MX_UART7_Init();
  MX_USART2_UART_Init();
  MX_UART5_Init();
  MX_USART1_UART_Init();
  MX_UART4_Init();
  MX_USB_OTG_FS_PCD_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  MotorController(NULL);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);
  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.HSIState = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 24;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV1;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART3|RCC_PERIPHCLK_USART2
                              |RCC_PERIPHCLK_UART4|RCC_PERIPHCLK_UART7
                              |RCC_PERIPHCLK_USART1|RCC_PERIPHCLK_UART5
                              |RCC_PERIPHCLK_SPI4|RCC_PERIPHCLK_USB;
  PeriphClkInitStruct.Spi45ClockSelection = RCC_SPI45CLKSOURCE_D2PCLK1;
  PeriphClkInitStruct.Usart234578ClockSelection = RCC_USART234578CLKSOURCE_D2PCLK1;
  PeriphClkInitStruct.Usart16ClockSelection = RCC_USART16CLKSOURCE_D2PCLK2;
  PeriphClkInitStruct.UsbClockSelection = RCC_USBCLKSOURCE_PLL;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Enable USB Voltage detector
  */
  HAL_PWREx_EnableUSBVoltageDetector();
}

/**
  * @brief SPI4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI4_Init(void)
{

  /* USER CODE BEGIN SPI4_Init 0 */

  /* USER CODE END SPI4_Init 0 */

  /* USER CODE BEGIN SPI4_Init 1 */

  /* USER CODE END SPI4_Init 1 */
  /* SPI4 parameter configuration*/
  hspi4.Instance = SPI4;
  hspi4.Init.Mode = SPI_MODE_MASTER;
  hspi4.Init.Direction = SPI_DIRECTION_2LINES;
  hspi4.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi4.Init.CLKPolarity = SPI_POLARITY_HIGH;
  hspi4.Init.CLKPhase = SPI_PHASE_2EDGE;
  hspi4.Init.NSS = SPI_NSS_SOFT;
  hspi4.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
  hspi4.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi4.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi4.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi4.Init.CRCPolynomial = 0x0;
  hspi4.Init.NSSPMode = SPI_NSS_PULSE_DISABLE;
  hspi4.Init.NSSPolarity = SPI_NSS_POLARITY_LOW;
  hspi4.Init.FifoThreshold = SPI_FIFO_THRESHOLD_01DATA;
  hspi4.Init.TxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
  hspi4.Init.RxCRCInitializationPattern = SPI_CRC_INITIALIZATION_ALL_ZERO_PATTERN;
  hspi4.Init.MasterSSIdleness = SPI_MASTER_SS_IDLENESS_00CYCLE;
  hspi4.Init.MasterInterDataIdleness = SPI_MASTER_INTERDATA_IDLENESS_00CYCLE;
  hspi4.Init.MasterReceiverAutoSusp = SPI_MASTER_RX_AUTOSUSP_DISABLE;
  hspi4.Init.MasterKeepIOState = SPI_MASTER_KEEP_IO_STATE_DISABLE;
  hspi4.Init.IOSwap = SPI_IO_SWAP_DISABLE;
  if (HAL_SPI_Init(&hspi4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI4_Init 2 */

  /* USER CODE END SPI4_Init 2 */

}

/**
  * @brief UART4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_UART4_Init(void)
{

  /* USER CODE BEGIN UART4_Init 0 */

  /* USER CODE END UART4_Init 0 */

  /* USER CODE BEGIN UART4_Init 1 */

  /* USER CODE END UART4_Init 1 */
  huart4.Instance = UART4;
  huart4.Init.BaudRate = 1000000;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  huart4.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart4.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart4.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart4) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart4, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart4, UART_RXFIFO_THRESHOLD_1_4) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_EnableFifoMode(&huart4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART4_Init 2 */

  /* USER CODE END UART4_Init 2 */

}

/**
  * @brief UART5 Initialization Function
  * @param None
  * @retval None
  */
static void MX_UART5_Init(void)
{

  /* USER CODE BEGIN UART5_Init 0 */

  /* USER CODE END UART5_Init 0 */

  /* USER CODE BEGIN UART5_Init 1 */

  /* USER CODE END UART5_Init 1 */
  huart5.Instance = UART5;
  huart5.Init.BaudRate = 1000000;
  huart5.Init.WordLength = UART_WORDLENGTH_8B;
  huart5.Init.StopBits = UART_STOPBITS_1;
  huart5.Init.Parity = UART_PARITY_NONE;
  huart5.Init.Mode = UART_MODE_TX_RX;
  huart5.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart5.Init.OverSampling = UART_OVERSAMPLING_16;
  huart5.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart5.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart5.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart5) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart5, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart5, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart5) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART5_Init 2 */

  /* USER CODE END UART5_Init 2 */

}

/**
  * @brief UART7 Initialization Function
  * @param None
  * @retval None
  */
static void MX_UART7_Init(void)
{

  /* USER CODE BEGIN UART7_Init 0 */

  /* USER CODE END UART7_Init 0 */

  /* USER CODE BEGIN UART7_Init 1 */

  /* USER CODE END UART7_Init 1 */
  huart7.Instance = UART7;
  huart7.Init.BaudRate = 1000000;
  huart7.Init.WordLength = UART_WORDLENGTH_8B;
  huart7.Init.StopBits = UART_STOPBITS_1;
  huart7.Init.Parity = UART_PARITY_NONE;
  huart7.Init.Mode = UART_MODE_TX_RX;
  huart7.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart7.Init.OverSampling = UART_OVERSAMPLING_16;
  huart7.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart7.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart7.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart7) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart7, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart7, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart7) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART7_Init 2 */

  /* USER CODE END UART7_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 1000000;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart1, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart1, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 1000000;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart2, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart2, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart3.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart3, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart3, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_UARTEx_DisableFifoMode(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief USB_OTG_FS Initialization Function
  * @param None
  * @retval None
  */
static void MX_USB_OTG_FS_PCD_Init(void)
{

  /* USER CODE BEGIN USB_OTG_FS_Init 0 */

  /* USER CODE END USB_OTG_FS_Init 0 */

  /* USER CODE BEGIN USB_OTG_FS_Init 1 */

  /* USER CODE END USB_OTG_FS_Init 1 */
  hpcd_USB_OTG_FS.Instance = USB_OTG_FS;
  hpcd_USB_OTG_FS.Init.dev_endpoints = 9;
  hpcd_USB_OTG_FS.Init.speed = PCD_SPEED_FULL;
  hpcd_USB_OTG_FS.Init.dma_enable = DISABLE;
  hpcd_USB_OTG_FS.Init.phy_itface = PCD_PHY_EMBEDDED;
  hpcd_USB_OTG_FS.Init.Sof_enable = ENABLE;
  hpcd_USB_OTG_FS.Init.low_power_enable = DISABLE;
  hpcd_USB_OTG_FS.Init.lpm_enable = DISABLE;
  hpcd_USB_OTG_FS.Init.battery_charging_enable = ENABLE;
  hpcd_USB_OTG_FS.Init.vbus_sensing_enable = ENABLE;
  hpcd_USB_OTG_FS.Init.use_dedicated_ep1 = DISABLE;
  if (HAL_PCD_Init(&hpcd_USB_OTG_FS) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USB_OTG_FS_Init 2 */

  /* USER CODE END USB_OTG_FS_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Stream0_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream0_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_4|LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);

  /*Configure GPIO pins : PE4 LD2_Pin */
  GPIO_InitStruct.Pin = GPIO_PIN_4|LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PB0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
/*
int MotorSetId(UART_HandleTypeDef huart, uint8_t *id, uint8_t *newId)
{
	int status;
	uint8_t frame[8] = {0xFF, 0xFF, *id, 4, MOTOR_WRITE, ADDR_ID, *newId, 0};
	frame[7] = motorInstrChecksum(frame, 1);
	status = HAL_UART_Transmit(&huart, frame, sizeof(frame), 100);
	return status;
}

int MotorSetAngleLimit(UART_HandleTypeDef huart, uint8_t *id, uint16_t *cwLimit, uint16_t *ccwLimit) // 0x00 - 0x3FF
{
	int status;
	uint8_t frame[11] = {0xFF, 0xFF, *id, 7, MOTOR_WRITE, ADDR_CW_ANGLE_LIMIT, (uint8_t)(*cwLimit & 0xFF), (uint8_t)(*cwLimit >> 8), (uint8_t)(*ccwLimit & 0xFF), (uint8_t)(*ccwLimit >> 8), 0};
	frame[10] = motorInstrChecksum(frame, 4);
	status = HAL_UART_Transmit(&huart, frame, sizeof(frame), 100);
	return status;
}

int MotorSetMaxTorque(UART_HandleTypeDef huart, uint8_t *id, uint16_t *maxTorque)		// 0x00 - 0x3FF
{
	int status;
	uint8_t frame[9] = {0xFF, 0xFF, *id, 5, MOTOR_WRITE, ADDR_MAX_TORQUE, (uint8_t)(*maxTorque & 0xFF), (uint8_t)(*maxTorque >> 8), 0};
	frame[8] = motorInstrChecksum(frame, 2);
	status = HAL_UART_Transmit(&huart, frame, sizeof(frame), 100);
	return status;
}

int MotorSetTorqueEnable(UART_HandleTypeDef huart, uint8_t *id, uint8_t *enableMotor) 		// Activate torque: 0 = OFF, 1 = ON
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
	frame[7] = motorInstrChecksum(frame, 1);
	status = HAL_UART_Transmit(&huart, frame, sizeof(frame), 100);
	return status;
}

int MotorSetComplianceMargin(UART_HandleTypeDef huart, uint8_t *id, uint8_t *cwComplianceMargin, uint8_t *ccwComplianceMargin)	// 0x00 - 0xFF
{
	int status;
	uint8_t frame[9] = {0xFF, 0xFF, *id, 5, MOTOR_WRITE, ADDR_CW_COMPLIANCE_MARGIN, *cwComplianceMargin, *ccwComplianceMargin, 0};
	frame[8] = motorInstrChecksum(frame, 2);
	status = HAL_UART_Transmit(&huart, frame, sizeof(frame), 100);
	return status;
}

int MotorSetComplianceSlope(UART_HandleTypeDef huart, uint8_t *id, uint8_t *cwComplianceSlope, uint8_t *ccwComplianceSlope)	// 0x00 - 0xFF
{
	int status;
	uint8_t frame[9] = {0xFF, 0xFF, *id, 5, MOTOR_WRITE, ADDR_CW_COMPLIANCE_SLOPE, *cwComplianceSlope, *ccwComplianceSlope, 0};
	frame[8] = motorInstrChecksum(frame, 2);
	status = HAL_UART_Transmit(&huart, frame, sizeof(frame), 100);
	return status;
}

int MotorSetGoalPosition(UART_HandleTypeDef huart, uint8_t *id, uint16_t *goalPosition)	// 0x00 - 0x3FF
{
	int status;
	uint8_t frame[9] = {0xFF, 0xFF, *id, 5, MOTOR_WRITE, ADDR_GOAL_POSITION, (uint8_t)(*goalPosition & 0xFF), (uint8_t)(*goalPosition >> 8), 0};
	frame[8] = motorInstrChecksum(frame, 2);
	status = HAL_UART_Transmit(&huart, frame, sizeof(frame), 100);
	return status;
}

int MotorSetMovingSpeed(UART_HandleTypeDef huart, uint8_t *id, uint16_t *movingSpeed)	// 0x00 - 0x3FF
{
	int status;
	uint8_t frame[9] = {0xFF, 0xFF, *id, 5, MOTOR_WRITE, ADDR_MOVING_SPEED, (uint8_t)(*movingSpeed & 0xFF), (uint8_t)(*movingSpeed >> 8), 0};
	frame[8] = motorInstrChecksum(frame, 2);
	status = HAL_UART_Transmit(&huart, frame, sizeof(frame), 100);
	return status;
}

int MotorSetTorqueLimit(UART_HandleTypeDef huart, uint8_t *id, uint16_t *torqueLimit) 	// 0x00 - 0x3FF
{
	int status;
	uint8_t frame[9] = {0xFF, 0xFF, *id, 5, MOTOR_WRITE, ADDR_TORQUE_LIMIT, (uint8_t)(*torqueLimit & 0xFF), (uint8_t)(*torqueLimit >> 8), 0};
	frame[8] = motorInstrChecksum(frame, 2);
	status = HAL_UART_Transmit(&huart, frame, sizeof(frame), 100);
	return status;
}

int MotorSetLock(UART_HandleTypeDef huart, uint8_t *id, uint8_t *lockROM) 	// Lock EEPROM area: 0 = modifiable, 1 = locked ---- IF LOCK IS SET TO 1, POWER MUST BE SWITCHED OFF AND BACK ON TO CHANGE IT BACK TO 0 -----
{
	int status;
	uint8_t frame[8] = {0xFF, 0xFF, *id, 4, MOTOR_WRITE, ADDR_LOCK, *lockROM, 0};
	frame[7] = motorInstrChecksum(frame, 1);
	status = HAL_UART_Transmit(&huart, frame, sizeof(frame), 100);
	return status;
}

int MotorSetPunch(UART_HandleTypeDef huart, uint8_t *id, uint16_t *minCurrentThreshold) 	// 0x20 - 0x3FF Minimum current to drive the motor
{
	int status;
	uint8_t frame[9] = {0xFF, 0xFF, *id, 5, MOTOR_WRITE, ADDR_PUNCH, (uint8_t)(*minCurrentThreshold & 0xFF), (uint8_t)(*minCurrentThreshold >> 8), 0};
	frame[8] = motorInstrChecksum(frame, 2);
	status = HAL_UART_Transmit(&huart, frame, sizeof(frame), 100);
	return status;
}
*/

void plotSensorData(motorData *dataToPlot )
{

	// ASCII commands
	char CR = '\r';
	char NL = '\n';
	char TB = '\t';
	char MoveBack[] = "\033[F";
/*
	//Text to send
	char mouseInfo[] = "Mouse Sensor:\n\r";
	char M_D_X[] = "Delta_X ";
	char M_D_Y[] = "Delta_Y ";

	char M_M[] = "Moving";
	char M_S[] = "Still ";
*/
	// Motor information
	char statusMotor[] = "Status of motor intructions:\n\r";
	char sendMotor[] = "Send Status ";
	char receiveMotor[] = "Receive Status ";
	char send[2], receive[2];
	int frameLength = 128;
	char frameSend[frameLength];
	char frameRec[frameLength];

	memset(frameSend,'\0',frameLength);
	memset(frameRec,'\0',frameLength);

	sprintf(send, "%d", (int) dataToPlot->sendStatus);
	sprintf(receive, "%d", (int) dataToPlot->receiveStatus);
	sprintf(frameSend, "%X  %X  %X  %X  %X  %X  %X  %X  %X  ", (int) dataToPlot->sendPack[0], (int) dataToPlot->sendPack[1], (int) dataToPlot->sendPack[2], (int) dataToPlot->sendPack[3], (int) dataToPlot->sendPack[4], (int) dataToPlot->sendPack[5], (int) dataToPlot->sendPack[6], (int) dataToPlot->sendPack[7], (int) dataToPlot->sendPack[8]);
	sprintf(frameRec, "%X  %X  %X  %X  %X  %X  %X  %X  %X  ", (int) dataToPlot->recPack[0], (int) dataToPlot->recPack[1], (int) dataToPlot->recPack[2], (int) dataToPlot->recPack[3], (int) dataToPlot->recPack[4], (int) dataToPlot->recPack[5], (int) dataToPlot->recPack[6], (int) dataToPlot->recPack[7], (int) dataToPlot->recPack[8]);
/*
	//sprintf(tick, "%d", (int) osKernelGetSysTimerCount());
	int arrSize = 8;
	char u16charArr[arrSize];

	memset(u16charArr,'\0',arrSize);

	// Send mouse sensor data
	HAL_UART_Transmit(&huart3,(uint8_t *) mouseInfo, sizeof(mouseInfo), 100);

    // Convert sensor value
	//u16ToString( dataToPlot->mouse_D_X, u16charArr,5);

	sprintf(u16charArr, "%d", dataToPlot->mouse_D_X);

	// Send delta X
	HAL_UART_Transmit(&huart3,(uint8_t *) M_D_X, sizeof(M_D_X), 100);
    HAL_UART_Transmit(&huart3,(uint8_t *) u16charArr, arrSize, 100);

    // Convert sensor value
    //u16ToString( dataToPlot->mouse_D_Y, u16charArr,5);
    sprintf(u16charArr, "%d", dataToPlot->mouse_D_Y);
    // Send delta Y
    HAL_UART_Transmit(&huart3,(uint8_t *) M_D_Y, sizeof(M_D_Y), 100);
    HAL_UART_Transmit(&huart3,(uint8_t *) u16charArr, arrSize, 100);

    if(dataToPlot->mouseMotion)
    {
      HAL_UART_Transmit(&huart3,(uint8_t *) M_M, sizeof(M_M), 100);
    }
    else
    {
	  HAL_UART_Transmit(&huart3,(uint8_t *) M_S, sizeof(M_S), 100);
    }

    HAL_UART_Transmit(&huart3,(uint8_t *) &CR, 1, 100);
*/
	//osKernelLock();
    // Send motor information
    HAL_UART_Transmit(&huart3,(uint8_t *) statusMotor, sizeof(statusMotor), 100);

    HAL_UART_Transmit(&huart3,(uint8_t *) sendMotor, sizeof(sendMotor), 100);
	HAL_UART_Transmit(&huart3,(uint8_t *) frameSend, sizeof(frameSend), 100);
	HAL_UART_Transmit(&huart3,(uint8_t *) &TB, sizeof(TB), 100);
	HAL_UART_Transmit(&huart3,(uint8_t *) send, sizeof(send), 100);

	HAL_UART_Transmit(&huart3,(uint8_t *) &NL, sizeof(NL), 100);
	HAL_UART_Transmit(&huart3,(uint8_t *) &CR, sizeof(CR), 100);

	// Convert sensor value
	//u16ToString( dataToPlot->mouse_D_Y, u16charArr,5);
	// Send delta Y
	HAL_UART_Transmit(&huart3,(uint8_t *) receiveMotor, sizeof(receiveMotor), 100);
	HAL_UART_Transmit(&huart3,(uint8_t *) frameRec, sizeof(frameRec), 100);
	HAL_UART_Transmit(&huart3,(uint8_t *) &TB, sizeof(TB), 100);
	HAL_UART_Transmit(&huart3,(uint8_t *) receive, sizeof(receive), 100);
	HAL_UART_Transmit(&huart3,(uint8_t *) &NL, sizeof(NL), 100);
	HAL_UART_Transmit(&huart3,(uint8_t *) &CR, sizeof(CR), 100);


    HAL_UART_Transmit(&huart3,(uint8_t *) MoveBack, sizeof(MoveBack), 100);
    HAL_UART_Transmit(&huart3,(uint8_t *) MoveBack, sizeof(MoveBack), 100);
    HAL_UART_Transmit(&huart3,(uint8_t *) MoveBack, sizeof(MoveBack), 100);
    //osKernelUnlock();
}

/*
// Checksum = ~(ID + Length + Instruction + Parameter1 + ... + Parameter N)
int motorInstrChecksum(uint8_t *frame, uint8_t bytesToSend)
{
	int checksum = 0;
	//frame->checksum = ~(frame->id + frame->packLength + frame->instruction + frame->address + frame->byte1 + frame->byte2) & 0xFF;
	if (bytesToSend == 1)
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
		perror("bad instruction checksum");
		return -1;
	}
	//return ~(chksum) & 0xFF;
	return checksum;
}

// Checksum = ~(ID + Length + Error + Parameter1 + ... + Parameter N)
uint8_t motorReturnChecksum(uint8_t *argument, int length)
{
	int chksum = 0;
	for (int i=2; i < sizeof(argument) -1; i++)		// Start at 3rd byte to skip communication initialization (2 * 0xFF)
	{
		chksum += argument[i];
	}
	return ~(chksum) & 0xFF;
}

int motorSendInstruction (uint8_t *frame)
{
	int status;
	//osKernelLock();
	status = HAL_UART_Transmit(&huart2, frame, sizeof(frame), 100);
	//osKernelUnlock();
	return status;
}

int motorReceiveInstruction (uint8_t *data)
{
	int status;
	//osKernelLock();
	status = HAL_UART_Receive(&huart2, data, sizeof(data), 1000);
	//osKernelUnlock();
	return status;
}

int motor (UART_HandleTypeDef huart,uint8_t *frame, int timeout)
{
	int status;
	//osKernelLock();
	status = HAL_UART_Transmit(&huart, frame, sizeof(frame), timeout);
	//osKernelUnlock();
	return status;
}

uint16_t MotorConvertAngle (uint16_t *newAngle)
{
	if (*newAngle > 54765)
	{
		return 0;
	}
	return ((uint16_t) (*newAngle * (1023 / 65535)));
}

uint16_t MotorGenerateAngle (uint16_t *angle)
{
	if (*angle > 359)
	{
		return 0;
	}
	return ((uint16_t) (*angle * (65535 / 359)));
}

// --------- FUTURE WORK - ADD EEPROM RESET TO OTHER VALUES ----------
int MotorInitConfig (UART_HandleTypeDef huart,uint8_t *id, motorConfiguration *motor)
{
	// Write to ROM area to reset initial configuration
	if (ROM_WRITE || FAILURE)
	{
		if (MotorSetAngleLimit(huart, id, &motor->cwAngleLimit, &motor->ccwAngleLimit))
		{
			return -1;
		}
		HAL_Delay(DELAY_TRANSMIT);
		if (MotorSetMaxTorque(huart, id, &motor->maxTorque))
		{
			return -2;
		}
		HAL_Delay(DELAY_TRANSMIT);
	}

	// Write to RAM area to configure start-up values
	if (MotorSetTorqueEnable(huart, id, &motor->torqueEnable)) // Activate torque
	{
		return -3;
	}
	HAL_Delay(DELAY_TRANSMIT);
	if (MotorSetComplianceMargin(huart, id, &motor->cwComplianceMargin, &motor->ccwComplianceMargin))
	{
		return -4;
	}
	HAL_Delay(DELAY_TRANSMIT);
	if (MotorSetComplianceSlope(huart, id, &motor->startCwComplianceSlope, &motor->startCcwComplianceSlope))	// 0x00 - 0xFF
	{
		return -5;
	}
	HAL_Delay(DELAY_TRANSMIT);
	if (MotorSetGoalPosition(huart, id, &motor->startPosition))//(uint16_t*) &motor->startPosition))	// 0x00 - 0x3FF
	{
		return -6;
	}
	HAL_Delay(DELAY_TRANSMIT);
	if (MotorSetMovingSpeed(huart, id, &motor->startSpeed))	// 0x00 - 0x3FF
	{
		return -7;
	}
	HAL_Delay(DELAY_TRANSMIT);
	if (MotorSetTorqueLimit(huart, id, &motor->startTorqueLimitRAM)) 	// 0x00 - 0x3FF
	{
		return -8;
	}



	return 0;
}

int MotorRead (uint8_t *buf, uint8_t id, uint8_t addr, uint8_t bytesToRead)
{
	int status = 0, length = 4;
	uint8_t frame[8] = {MOTOR_HEADER, MOTOR_HEADER, id, length, MOTOR_READ, addr, bytesToRead, motorInstrChecksum(frame, 1)};
	switch (id) {
		case 1:
			while (HAL_UART_Transmit(&huart7, frame, sizeof(frame), 200))
			{}
			status = HAL_UART_Receive(&huart5, buf, PACKAGE_LENGTH, 5000);
			break;
		default:
			status -1;
			break;
	}
	//return HAL_UART_Receive(&huart5, pData, Size, Timeout);
	return status;
}
*/

/* USER CODE BEGIN Header_MotorController */
/**
* @brief Function implementing the MotorControl thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_MotorController */

void MotorController(void *argument)
{
	/* USER CODE BEGIN MotorController */
	/* [Header1, Header2, Packet ID, Length, Instruction, Param 1, …, Param N, Checksum]
	 * 0xFF, 0xFF, 0-253 (254 broadcast), nr. of params +2, */
	uint8_t buf[18] = {0}, sendStatus = -1, receiveStatus = -1, pos1 = 0, pos2 = 0, newId = 8, id = 2;
	uint8_t frame[PACKAGE_LENGTH];
	//uint16_t offsetM2 = 12;
	int statusM1,statusM2;
	uint8_t setId = 0;
	motorData plotValues;
	motorConfiguration motor1, motor2;
	gripperStruct motors;
	UART_HandleTypeDef *h_uart = &huart4;
	uint16_t offsetM2 = MotorConvertAngle(MotorGenerateAngle((float)12U));
	//{ 0x01, 0x1C4, 0x23C, 0x00, 0xFF, 0x01, 0x01, 0x20, 0x20, 0x1FF, 0x01, 0x00, 0x08, 0x00, 0x01, 0x01, 0x01, 0x20, 0x20, 0xFF, 0x01, 0x01, 0x00, 0x08, 0x00, 0x01, 0x20, 0x00};
	// Static motor values

	uint16_t posM0 = 719, posM1 = 714, posM2 = 408, testPos = 600;
	uint16_t testAngle1, testAngle2, testAngle3;


	if (setId == 0)
	{


		while (1)
		{

			GripperStartupConfiguration(h_uart, &motors);
			HAL_Delay(2000);
			MotorSetGoalPosition(h_uart, &motors.finger2Motor0.id, &posM0);
			HAL_Delay(200);
			MotorSetGoalPosition(h_uart, &motors.finger2Motor1.id, &posM1);
			HAL_Delay(200);
			MotorSetGoalPosition(h_uart, &motors.finger2Motor2.id, &posM2);

			testAngle1 = MotorConvertShortToDegree(MotorConvertPosToShort(posM0));
			testAngle2 = MotorConvertShortToDegree(MotorConvertPosToShort(posM1));
			testAngle3 = MotorConvertShortToDegree(MotorConvertPosToShort(posM2));
			//MotorSetId(h_uart, &setId, &newId);
			//setId = (setId + 1) % 10;
			MotorRead(h_uart, buf, motors.finger2Motor0.id, ADDR_PRESENT_POSITION, 2);
			MotorRead(h_uart, buf, motors.finger2Motor1.id, ADDR_PRESENT_POSITION, 2);
			MotorRead(h_uart, buf, motors.finger2Motor2.id, ADDR_PRESENT_POSITION, 2);
			HAL_Delay(3000);
		}
	}
	else{
		MotorSetId(h_uart, &id, &newId);
		//GripperStartupConfiguration(h_uart, &motors);

		while(1)
		{
			for (uint8_t i=0; i < 10; i++)
			{
				MotorSetGoalPosition(h_uart, &i, &testPos);
				HAL_Delay(100);
			}
		}
	}
	motor1.id = 1;
	motor1.cwAngleLimit = 452;
	motor1.ccwAngleLimit = 572;
	motor1.maxTorque = 512;
	motor1.punch = 32;
	// Initial Values
	motor1.startCwComplianceMargin = 0;
	motor1.startCcwComplianceMargin = 0;
	motor1.startCwComplianceSlope = 32;
	motor1.startCcwComplianceSlope = 32;
	motor1.startPosition = 512;
	motor1.startSpeed = 40;
	motor1.startTorqueLimitRAM = 500;
	// Runtime values
	motor1.torqueEnable = 0x01;
	motor1.cwComplianceMargin = 1;
	motor1.ccwComplianceMargin = 1;
	motor1.cwComplianceSlope = 32;
	motor1.ccwComplianceSlope = 32;
	motor1.goalPosition = motor1.startPosition + 50;
	motor1.movingSpeed = motor1.startSpeed;
	motor1.torqueLimitRAM = motor1.startTorqueLimitRAM;
	motor1.lockEEPROM = 0;

	//{ 0x02, 0x1E2, 0x21E, 0x00, 0xFF, 0x01, 0x01, 0x20, 0x20, 0x1FF, 0x01, 0x00, 0x08, 0x00, 0x01, 0x01, 0x01, 0x20, 0x20, 0xFF, 0x01, 0x01, 0x00, 0x08, 0x00, 0x01, 0x20, 0x00};
	// Static motor values
	motor2.id = 2;
	motor2.cwAngleLimit = 350;
	motor2.ccwAngleLimit = 580;
	motor2.maxTorque = 512;
	motor2.punch = 32;
	// Initial Values
	motor2.startCwComplianceMargin = 0;
	motor2.startCcwComplianceMargin = 0;
	motor2.startCwComplianceSlope = 32;
	motor2.startCcwComplianceSlope = 32;
	motor2.startPosition = 512 - offsetM2;
	motor2.startSpeed = 40;
	motor2.startTorqueLimitRAM = 500;
	// Runtime values
	motor2.torqueEnable = 0x01;
	motor2.cwComplianceMargin = 1;
	motor2.ccwComplianceMargin = 1;
	motor2.cwComplianceSlope = 32;
	motor2.ccwComplianceSlope = 32;
	motor2.goalPosition = motor2.startPosition;
	motor2.movingSpeed = motor2.startSpeed;
	motor2.torqueLimitRAM = motor2.startTorqueLimitRAM;
	motor2.lockEEPROM = 0;

	motor1.goalPosition = motor1.cwAngleLimit;
	motor2.goalPosition = motor2.cwAngleLimit;

	int wander = 0;
	int  directionM1 = 1, directionM2 = 1;
	uint16_t position = motor1.startPosition;
	uint16_t currentPosMotor1 = 0, currentPosMotor2 = 0;

	float testAng = MotorConvertAngle(MotorGenerateAngle(150.0));
	/*
	 * MOTOR CONFIG
	uint8_t id;
	uint8_t cwAngleLimit[2];
	uint8_t ccwAngleLimit[2];
	uint8_t maxTorque[2];

	uint8_t startCwComplianceMargin;
	uint8_t startCcwComplianceMargin;
	uint8_t startCwComplianceSlope;
	uint8_t startCcwComplianceSlope;
	uint8_t startPosition[2];
	uint8_t startSpeed[2];
	uint8_t startTorqueLimitRAM[2];

	uint8_t torqueEnable;
	uint8_t cwComplianceMargin;
	uint8_t ccwComplianceMargin;
	uint8_t cwComplianceSlope;
	uint8_t ccwComplianceSlope;
	uint8_t goalPosition[2];
	uint8_t movingSpeed[2];
	uint8_t torqueLimitRAM[2];
	uint8_t lockEEPROM;
	uint8_t punch[2];
	*/

	frame[0] = MOTOR_HEADER;
	frame[1] = MOTOR_HEADER;	// Start communication
	frame[2] = 0x01;			// Motor ID
	frame[3] = 3 + 2;			// Length (nParams + 2)
	frame[4] = MOTOR_WRITE;		// Instruction
	frame[5] = ADDR_GOAL_POSITION; 				// Param 1, AX_GOAL_POSITION_L;
	frame[6] = 0;		// Param 2
	frame[7] = 0;		// Param 3
	//frame[8] = motorInstrChecksum(frame); // Checksum

	//motorFrame frame1;
	//frame1.H1 = 0xFF;
	//frame1.H2 = 0xFF;
	//frame1.id = 1;

	//frame[5] = 0xDF;

	//MotorSetId(h_uart, &motor1.id, &newId);
	//motor1.id = newId;

	/*
	 * TEST VALUES
	motor1.cwAngleLimit = 0x1C4;
	motor1.ccwAngleLimit = 0x25A;
	motor2.cwAngleLimit = 0x1B0;
	motor2.ccwAngleLimit = 0x210;
	 */

	MotorInitConfig(h_uart, &motor1.id, &motor1);
	//while (HAL_UART_Receive(&h_uart, &buf[1], 1, 50) != 3)
	//{}
	MotorInitConfig(h_uart, &motor2.id, &motor2);
	//while (HAL_UART_Receive(&h_uart, &buf[1], 1, 50) != 3)
	//{}

	/* Infinite loop */
	for(;;)
	{
		/*
		if (pos1 > 235)
		{
			pos1 = 0;
			pos2++;
		}
		if (pos2 > 3)
		{
			pos2 = 0;
		}

		frame[6] = pos1;
		frame[7] = pos2;

//		position = 0x1FF;
		frame[6] = (uint8_t) (position & 0xFF);
		frame[7] = (uint8_t) ((position >> 8));
		frame[8] = (uint8_t) motorInstrChecksum(frame, 2); // Checksum ---- ADD ERROR CATCH FOR RETURN VALUE
		 */

		plotValues.receiveStatus = MotorRead(h_uart, buf, motor1.id, ADDR_PRESENT_POSITION, 2);
		currentPosMotor1 = (buf[7] << 8) | buf[6];
		HAL_Delay(10);
		plotValues.receiveStatus = MotorRead(h_uart, buf, motor2.id, ADDR_PRESENT_POSITION, 2);
		currentPosMotor2 = (buf[7] << 8) | buf[6];
		HAL_Delay(10);
		MotorSetGoalPosition(h_uart, &motor1.id, &motor1.goalPosition);
		MotorSetGoalPosition(h_uart, &motor2.id, &motor2.goalPosition);
//		currentPosMotor1 << 8;
//		currentPosMotor1 |= buf[6];
		if (wander == 0)
		{
			for (;;)
			{
				plotValues.receiveStatus = MotorRead(h_uart, buf, motor1.id, ADDR_PRESENT_POSITION, 2);
				currentPosMotor1 = (buf[7] << 8) | buf[6];
				plotValues.receiveStatus = MotorRead(h_uart, buf, motor2.id, ADDR_PRESENT_POSITION, 2);
				currentPosMotor2 = (buf[7] << 8) | buf[6];

				if (currentPosMotor1 <= (motor1.cwAngleLimit + motor1.cwComplianceMargin + 10))
				{
					motor1.goalPosition = motor1.ccwAngleLimit;
					MotorSetGoalPosition(h_uart, &motor1.id, &motor1.goalPosition);
				}
				else if (currentPosMotor1 >= (motor1.ccwAngleLimit - motor1.ccwComplianceMargin - 10))
				{
					motor1.goalPosition = motor1.cwAngleLimit;
					MotorSetGoalPosition(h_uart, &motor1.id, &motor1.goalPosition);
				}

				if (currentPosMotor2 <= (motor2.cwAngleLimit + motor2.cwComplianceMargin + 10))
				{
					motor2.goalPosition = motor2.ccwAngleLimit;
					MotorSetGoalPosition(h_uart, &motor2.id, &motor2.goalPosition);
				}
				else if (currentPosMotor2 >= (motor2.ccwAngleLimit - motor2.ccwComplianceMargin - 10))
				{
					motor2.goalPosition = motor2.cwAngleLimit;
					MotorSetGoalPosition(h_uart, &motor2.id, &motor2.goalPosition);
				}

				HAL_Delay(200);

			}
		}
		//frame1.byte1 = pos1;
		//frame1.byte2 = pos2;
		//motorInstrChecksum(&frame1);
		//frame1.checksum = motorInstrChecksum(frame1, PACKAGE_LENGTH); // Checksum

		//HAL_HalfDuplex_EnableTransmitter(&huart2);
		//HAL_Delay(10);
		//sendStatus = motorSendInstruction(frame);
		//HAL_Delay(10);
		//HAL_HalfDuplex_EnableReceiver(&huart2);
		//HAL_Delay(10);
		//receiveStatus = motorReceiveInstruction(buf);
		//HAL_Delay(10);

		//HAL_HalfDuplex_EnableTransmitter(&huart7);
		//HAL_HalfDuplex_EnableReceiver(&huart5);
//		sendStatus = HAL_UART_Transmit(&huart7, frame, PACKAGE_LENGTH, 200);
		//HAL_Delay(10);
		/*
		for (int i = 0; i < PACKAGE_LENGTH; i++)
		{
			receiveStatus = HAL_UART_Receive(&huart5, &buf[i], 1, 500);
		}
		*/
//		receiveStatus = HAL_UART_Receive(&huart5, buf, 3, 500);

//		receiveStatus = MotorRead(buf, 1, 36, 2);


//		plotValues.sendStatus = sendStatus;
//		plotValues.receiveStatus = receiveStatus;
//		memcpy(plotValues.sendPack, frame, sizeof(frame));
//		memcpy(plotValues.recPack, &buf, sizeof(buf));
//		plotSensorData( &plotValues );

		if (wander == 1)
		{
			if (motor1.goalPosition > motor1.ccwAngleLimit)
				{
					directionM1 = 1; // CW
				}
			else if (motor1.goalPosition < motor1.cwAngleLimit)
				{
					directionM1 = 2; // CCW
				}
			if (motor2.goalPosition > motor2.ccwAngleLimit)
				{
					directionM2 = 1; // CW
				}
			else if (motor2.goalPosition < motor2.cwAngleLimit)
				{
					directionM2 = 2; // CCW
				}
			//status = MotorInitConfig(huart7, &motor1.id, &motor1);
			frame[6] = (uint8_t)(motor1.goalPosition & 0xFF);
			frame[7] = (uint8_t)(motor1.goalPosition >> 8);
			statusM1 = MotorSetGoalPosition(h_uart, &motor1.id, &motor1.goalPosition);
			plotValues.sendStatus = statusM1;
			//plotValues.receiveStatus = HAL_UART_Receive(&h_uart, buf, PACKAGE_LENGTH, 200);
			memcpy(plotValues.sendPack, frame, sizeof(frame));
			memcpy(plotValues.recPack, buf, sizeof(plotValues.recPack));
			plotSensorData(&plotValues);

			statusM2 = MotorSetGoalPosition(h_uart, &motor2.id, &motor2.goalPosition);
			//HAL_Delay(100);
			//pos1 += 2;
			if (directionM1 == 1)
			{
				motor1.goalPosition -= 5+5;
				//motor1.goalPosition = motor1.cwAngleLimit;
			}
			else
			{
				motor1.goalPosition += 5+5;
				//motor1.goalPosition = motor1.ccwAngleLimit;
			}

			if (directionM2 == 1)
			{
				motor2.goalPosition -= 5+5;
				//motor2.goalPosition = motor2.cwAngleLimit;
			}
			else
			{
				motor2.goalPosition += 5+5;
				//motor2.goalPosition = motor2.ccwAngleLimit;
			}
		}

		//HAL_Delay(10);
  }

	/* USER CODE END MotorController */
}
/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
	char error[] = "HAL ERROR";
	while (1)
	{

	}
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
