
#ifndef AX_12A_API_h
#define AX_12A_API_h

#include "stm32h7xx_hal.h"
//#include "stm32h7xx_hal_uart.h"
#include "stm32h7xx_hal_rcc.h"

// Motor AX-12A instructions
#define MOTOR_HEADER 		0xFF
#define MOTOR_ID_BROADCAST 	0xFE
#define MOTOR_PING  		0x01
#define MOTOR_READ  		0x02
#define MOTOR_WRITE  		0x03
#define MOTOR_REG_WRITE  	0x04
#define MOTOR_ACTION 		0x05
#define MOTOR_FAC_RESET  	0x06
#define MOTOR_REBOOT  		0x08
#define MOTOR_SYNC_WRITE 	0x83
#define MOTOR_BULK_READ  	0x92


// Motor AX-12A register addresses
// ----- ROM ADDRESSES ----------
#define ADDR_MODEL_NUMBER  			0
#define ADDR_FIRMWARE_VERSION  		2
#define ADDR_ID  					3
#define ADDR_BAUD_RATE  			4
#define ADDR_RETURN_DELAY  			5
#define ADDR_CW_ANGLE_LIMIT  		6
#define ADDR_CCW_ANGLE_LIMIT 		8
#define ADDR_TEMPERATURE_LIMIT 		11
#define ADDR_MIN_VOLTAGE_LIMIT  	12
#define ADDR_MAX_VOLTAGE_LIMIT  	13
#define ADDR_MAX_TORQUE  			14
#define ADDR_STATUS_RETURN  		16
#define ADDR_ALARM_LED  			17
#define ADDR_SHUTDOWN 				18

// ----- RAM ADDRESSES ---------
#define ADDR_TORQUE_ENABLE 			24
#define ADDR_LED 					25
#define ADDR_CW_COMPLIANCE_MARGIN  	26
#define ADDR_CCW_COMPLIANCE_MARGIN  27
#define ADDR_CW_COMPLIANCE_SLOPE 	28
#define ADDR_CCW_COMPLIANCE_SLOPE  	29
#define ADDR_GOAL_POSITION  		30
#define ADDR_MOVING_SPEED  			32
#define ADDR_TORQUE_LIMIT  			34
#define ADDR_PRESENT_POSITION  		36
#define ADDR_PRESENT_SPEED  		38
#define ADDR_PRESENT_LOAD  			40
#define ADDR_PRESENT_VOLTAGE  		42
#define ADDR_PRESENT_TEMPERATURE  	43
#define ADDR_REGISTERED  			44
#define ADDR_MOVING  				46
#define ADDR_LOCK  					47
#define ADDR_PUNCH 					48


// Additional values
#define ROM_WRITE  		1
#define FAILURE  		0
#define DELAY_TRANSMIT  10
#define PACKAGE_LENGTH 	9


// Struct containing motor configuration values
struct motorConfiguration
{
	uint8_t id;
	uint16_t cwAngleLimit;
	uint16_t ccwAngleLimit;
	uint16_t maxTorque;
	uint16_t offsetAngle;

	uint8_t startCwComplianceMargin;
	uint8_t startCcwComplianceMargin;
	uint8_t startCwComplianceSlope;
	uint8_t startCcwComplianceSlope;
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





int MotorInstrChecksum(uint8_t *frame, uint8_t bytesToSend); // Calculate checksum for instruction packages, bytesToSend is interpreted as parameters after the register address, ~( ID + Length + Instruction + Parameter1 + … Parameter N )
uint8_t MotorReturnChecksum(uint8_t *argument, int length); // Calculate checksum for status packages ---- VALIDATE ------



uint16_t MotorConvertAngle (uint16_t newAngle); // Convert angle given as a unsigned short into steps for the motor
uint16_t MotorGenerateAngle (float angle); // Convert angle given in degrees into unsigned short
int MotorInitConfig (UART_HandleTypeDef *huart,uint8_t *id, motorConfiguration *motor); // Initialize and configure startup values for the motor
uint16_t MotorConvertShortToDegree (uint16_t ushort);


// Motor configuration functions
int MotorSetAngleLimit(UART_HandleTypeDef *huart, uint8_t *id, uint16_t *cwLimit, uint16_t *ccwLimit); // Configure angle limits for the motor, value range: 0 - 1023
int MotorSetMaxTorque(UART_HandleTypeDef *huart, uint8_t *id, uint16_t *maxTorque);		// Configure maximum torque for the motor, value range: 0 - 1023
int MotorSetTorqueEnable(UART_HandleTypeDef *huart, uint8_t *id, uint8_t *enableMotor); 		// Toggle torque for the motor, value range: 0 = OFF, 1 = ON
int MotorSetComplianceMargin(UART_HandleTypeDef *huart, uint8_t *id, uint8_t *cwComplianceMargin, uint8_t *ccwComplianceMargin);	// Configure compliance margin for each direction of the motor, value range: 0 - 1023
int MotorSetComplianceSlope(UART_HandleTypeDef *huart, uint8_t *id, uint8_t *cwComplianceSlope, uint8_t *ccwComplianceSlope);	// Configure compliance slope for each direction of the motor, value range: 0 - 1023
int MotorSetGoalPosition(UART_HandleTypeDef *huart, uint8_t *id, uint16_t *goalPosition);	// Configure goal position for the motor, value range: 0 - 1023 (0 - 300 degrees)
int MotorSetMovingSpeed(UART_HandleTypeDef *huart, uint8_t *id, uint16_t *movingSpeed);	// Configure the speed of the motor, value range: 0 - 1023
int MotorSetTorqueLimit(UART_HandleTypeDef *huart, uint8_t *id, uint16_t *torqueLimit); 	// Configure the torque limit of the motor, value range: 0 - 1023 (Cannot go higher than max torque)
int MotorSetLock(UART_HandleTypeDef *huart, uint8_t *id, uint8_t *lockROM); 	// Lock EEPROM area: 0 = modifiable, 1 = locked ---- IF LOCK IS SET TO 1, POWER MUST BE SWITCHED OFF AND BACK ON TO CHANGE IT BACK TO 0 -----
int MotorSetPunch(UART_HandleTypeDef *huart, uint8_t *id, uint16_t *minCurrentThreshold); 	// Configure minimum current to drive the motor, value range: 32 - 1023 ---- DEFAULT = 32 ----
int MotorSetId(UART_HandleTypeDef *huart, uint8_t *id, uint8_t *newId); // Rewrite id of motor
int MotorPing(UART_HandleTypeDef *huart, uint8_t *id); // Send a ping request to motor, returns '1' if the motor responds and '0' otherwise
int MotorRead(UART_HandleTypeDef *huart, uint8_t *buf, uint8_t id, uint8_t addr, uint8_t bytesToRead); // Reads bytesToRead bytes at register address addr from motor, and stores it in buf
int MotorSendStop(UART_HandleTypeDef *huart, uint8_t *id); // Send a torque off instruction to motor



#endif

