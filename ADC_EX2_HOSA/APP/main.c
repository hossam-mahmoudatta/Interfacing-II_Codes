/*
 * main.c
 *
 *  Created on: May 2, 2023
 *      Author: Administrator
 */
#include <util/delay.h>
#include <avr/io.h>
//#include "../ECUAL/LED_DRIVER/LED.h"
//#include "../ECUAL/BUTTON_DRIVER/BUTTON.h"
//#include "../ECUAL/SEVEN-SEGMENT_DRIVER/SEGMENT.h"
//#include "../ECUAL/KEYPAD_DRIVER/KEYPAD.h"
#include "../ECUAL/LCD_DRIVER/LCD.h"
#include "../MCAL/ADC_DRIVER/ADC.h"
#define F_CPU 1000000
int main(void) {
	// Initializes the screen
	LCD_Init();

	// Initializes the ADC Module
	ADC_Init();

	// Displays messages
	LCD_displayString("ADC Value = ");

	while (1) {
		uint16 RESULT_VALUE = 0;
		LCD_moveCursor(0, 12);
		//LCD_displayString("Hosa");
		//_delay_ms(6000);
		//LCD_clearScreen();
		RESULT_VALUE = ADC_readChannel(2);
		//LCD_moveCursor(0, 12);
		//LCD_displayString("Nona");
		//LCD_clearScreen();
		if (RESULT_VALUE >= 1000) {
			LCD_intgerToString(RESULT_VALUE);
		}
		else {
			LCD_intgerToString(RESULT_VALUE);
			LCD_displayCharacter(' ');
		}
	}
}
