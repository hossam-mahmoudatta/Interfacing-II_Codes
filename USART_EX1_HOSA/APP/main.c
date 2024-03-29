/******************************************************************************
 *
 * Application
 *
 * File Name: main.c
 *
 * Description: Application file for this exercise
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/


/*******************************************************************************
 *                              					 Application Libraries                                					  *
 *******************************************************************************/

#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

/*******************************************************************************
 *                              						  Modules Drivers                                  					  *
 *******************************************************************************/

//#include "../MCAL/ADC_DRIVER/ADC.h"
//#include "../MCAL/EXT_INTERRUPT_DRIVER/EXT_INTERRUPT.h"
//#include "../MCAL/I2C_DRIVER/I2C.h"
//#include "../MCAL/ICU_DRIVER/ICU.h"
//#include "../MCAL/SPI_DRIVER/SPI.h"
//#include "../MCAL/TIMER_DRIVER/TIMER.h"
//#include "../MCAL/USART_DRIVER/USART.h"
#include "../MCAL/EXT_INTERRUPT_DRIVER/EXT_INTERRUPT.h"

//#include "../ECUAL/EEPROM_DRIVER/EEPROM.h"
//#include "../ECUAL/KEYPAD_DRIVER/KEYPAD.h"
//#include "../ECUAL/LCD_DRIVER/LCD.h"
//#include "../ECUAL/LM35_DRIVER/LM35.h"
//#include "../ECUAL/SEVEN-SEGMENT_DRIVER/SEGMENT.h"
#include "../ECUAL/BUTTON_DRIVER/BUTTON.h"
#include "../ECUAL/LED_DRIVER/LED.h"

/*******************************************************************************
 *                              						Application Execution                              					  *
 *******************************************************************************/

int main(void) {

	// Initializes LED Driver
	LED_Init(PORT_C, PIN_0);
	LED_Off(PORT_C, PIN_0);


	// Initializes Button Driver
	BUTTON_Init(PORT_D, PIN_2);
	BUTTON_Read(PORT_D, PIN_2);

	// Initializes External Interrupt Driver
	EXT_INTERRUPT_Init();

	while (1) {

	}
}

// The Interrupt Service Routine that will execute the Interrupt
ISR (INT0_vect) {
	LED_Toggle(PORT_C, PIN_0);
}

