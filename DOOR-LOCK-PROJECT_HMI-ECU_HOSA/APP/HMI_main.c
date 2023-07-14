/******************************************************************************
 *
 * Application
 *
 * File Name: HMI_main.c
 *
 * Description: Application file for this HMI ECU in the final project
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
//#include "../MCAL/I2C_DRIVER/I2C.h"
//#include "../MCAL/ICU_DRIVER/ICU.h"
//#include "../MCAL/SPI_DRIVER/SPI.h"
//#include "../MCAL/EXT_INTERRUPT_DRIVER/EXT_INTERRUPT.h"

#include "../MCAL/TIMER_DRIVER/TIMER.h" // I will need this driver for this ECU Driver
#include "../MCAL/USART_DRIVER/USART.h" // I will need this driver for this ECU Driver

/*******************************************************************************/

//#include "../ECUAL/EEPROM_DRIVER/EEPROM.h"
//#include "../ECUAL/LM35_DRIVER/LM35.h"
//#include "../ECUAL/SEVEN-SEGMENT_DRIVER/SEGMENT.h"
//#include "../ECUAL/BUTTON_DRIVER/BUTTON.h"

#include "../ECUAL/BUZZER_DRIVER/BUZZER.h"
#include "../ECUAL/KEYPAD_DRIVER/KEYPAD.h" // I will need this driver for this ECU Driver
#include "../ECUAL/LCD_DRIVER/LCD.h" // I will need this driver for this ECU Driver
#include "../ECUAL/LED_DRIVER/LED.h" // I will need this driver for this ECU Driver

/*******************************************************************************
 *                              						Application Execution                              					  *
 *******************************************************************************/

/*
 * The LCD should start with a hello message for 3 seconds
 * 1. then should display the "enter password'
 * password should be of 5 characters
 * the password should be displayed as ***** on the LCD for security
 * enter button as any button on the keypad
 * re enter password for confirmation
 * the ecu will send the 2 passwords to check the matching through USART
 * if matching, then will save it in the EEPROM
 * if unmatched, repeat from step one
 */

/*
ISR(TIMER0_COMP_vect) {
	compadreMatches++;
	LED_Toggle(PORT_C, PIN_0);

	if(compareMatches == 2) {
		LED_Toggle(PORT_C, PIN_1);
	}
	else if(compareMatches == 4) {
		LED_Toggle(PORT_C, PIN_1);
		LED_Toggle(PORT_C, PIN_2);
		compareMatches = 0;
	}
}
*/

volatile uint8 dataReceived 	= 0;
volatile uint8 dataSent 			= 0;

ISR(TIMER0_COMP_vect) {

}

ISR(USART_RXC_vect) {
    // Handle receive interrupt

}

ISR(USART_TXC_vect) {
    // Handle transmit complete interrupt
    // Data transmission is complete
}

int main(void) {
	USART_ConfigType *USARTConfig;
	USARTConfig -> bitData 		= USART_8_BIT;
	USARTConfig -> stopBit 		= USART_STOP_1_BIT;
	USARTConfig -> parity 		= USART_PARITY_DISABLED;
	USARTConfig -> baudRate 	= USART_BAUDRATE_9600;
	USART_Init(USARTConfig);
	Buzzer_Init(PORT_B, PIN_2);
	KEYPAD_Init();
	LCD_Init();

	uint8* password1 						= passwordEntry1();
	uint8* passwordVerification 	= passwordEntry2();

	// Displays the passwords saved in the arrays to check if keypad inputed correctly
	displayPasswords(password1, passwordVerification);

	USART_sendPassword(password1);




	while (1) {



	}





}
