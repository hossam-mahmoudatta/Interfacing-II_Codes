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
#define F_CPU 1000000

int main(void) {
	// Initializes the screen
	LCD_Init();

	// Displays messages
	//LCD_displayString("ENG Mohd Tarek");
	LCD_displayStringRowColumn(0, 2, "kdjflksdjfslakdj");
	LCD_displayStringRowColumn(1, 6, "Hehe");
	_delay_ms(4000);
	LCD_clearScreen();
	LCD_displayStringRowColumn(0, 1, "Hosa is great");
		LCD_displayStringRowColumn(1, 6, "Hehe");
	while (1) {

	}
}



