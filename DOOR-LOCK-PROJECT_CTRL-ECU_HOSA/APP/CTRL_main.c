/******************************************************************************
 *
 * Application
 *
 * File Name: CTRL_main.c
 *
 * Description: Application file for this CTRL ECU in the final project
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/


/*******************************************************************************
 *                              					 Application Libraries                                					  *
 *******************************************************************************/

#include "mainApp_Functions.h"

/*******************************************************************************
 *                              						  Modules Drivers                                  					  *
 *******************************************************************************/

//#include "../MCAL/ADC_DRIVER/ADC.h"
//#include "../MCAL/ICU_DRIVER/ICU.h"
//#include "../MCAL/SPI_DRIVER/SPI.h"
//#include "../MCAL/EXT_INTERRUPT_DRIVER/EXT_INTERRUPT.h"

#include "../MCAL/I2C_DRIVER/I2C.h"
#include "../MCAL/TIMER_DRIVER/TIMER.h" // I will need this driver for this ECU Driver
#include "../MCAL/USART_DRIVER/USART.h" // I will need this driver for this ECU Driver

/*******************************************************************************/

//#include "../ECUAL/EEPROM_DRIVER/EEPROM.h"
//#include "../ECUAL/LM35_DRIVER/LM35.h"
//#include "../ECUAL/SEVEN-SEGMENT_DRIVER/SEGMENT.h"
//#include "../ECUAL/BUTTON_DRIVER/BUTTON.h"

#include "../ECUAL/KEYPAD_DRIVER/KEYPAD.h" // I will need this driver for this ECU Driver
#include "../ECUAL/LCD_DRIVER/LCD.h" // I will need this driver for this ECU Driver
#include "../ECUAL/LED_DRIVER/LED.h" // I will need this driver for this ECU Driver

/*******************************************************************************
 *                              						Application Execution                              					  *
 *******************************************************************************/

volatile uint8 dataReceived 	= 0;
volatile uint8 ackSent 			= 0;


// USART receive ISR
ISR(USART_RXC_vect) {
    // Handle receive interrupt
    dataReceived = UDR;

    // Send acknowledgment
    ackSent = 1;
    USART_Transmit(dataReceived);
}

ISR(USART_TXC_vect) {
    // Handle transmit complete interrupt
	// Acknowledgment transmission is complete
	ackSent = 0;
}


int main(void) {
	USART_ConfigType *USARTConfig;
	USARTConfig -> bitData 		= USART_8_BIT;
	USARTConfig -> stopBit 		= USART_STOP_1_BIT;
	USARTConfig -> parity 		= USART_PARITY_DISABLED;
	USARTConfig -> baudRate 	= USART_BAUDRATE_9600;
	USART_Init(USARTConfig);
	I2C_Init();

    // Set the receive complete callback function
    USART_setReceiveCompleteCallback(USART_receiveCompleteCallback());

    // Enable UART receive interrupt
    UART_enableReceiveInterrupt();

	while (1) {

	}

}

