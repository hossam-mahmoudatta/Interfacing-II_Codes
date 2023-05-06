/*
 * main.c
 *
 *  Created on: May 2, 2023
 *      Author: Administrator
 */
#include <util/delay.h>
#include <avr/io.h>
//#include "../MCAL/LED_DRIVER/LED.h"
//#include "../MCAL/BUTTON_DRIVER/BUTTON.h"
//#include "../MCAL/SEVEN-SEGMENT_DRIVER/SEGMENT.h"
//#include "../MCAL/KEYPAD_DRIVER/KEYPAD.h"
#include "../MCAL/LCD_DRIVER/LCD.h"

int main(void) {
	// Initializes the screen
	LCD_Init();

	// Displays messages
	LCD_displayString("ENG Mohd Tarek");
	//LCD_displayStringRowColumn(0, 2, "Testing LCD");
	//LCD_displayStringRowColumn(1, 2, "Nice");

	while (1) {

	}
}



