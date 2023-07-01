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

//#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

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
	compareMatches++;
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

ISR(TIMER0_COMP_vect) {

}

int main(void) {





	while (1) {

	}
}

