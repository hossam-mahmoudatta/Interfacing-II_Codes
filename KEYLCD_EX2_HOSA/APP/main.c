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
#include "../MCAL/SEVEN-SEGMENT_DRIVER/SEGMENT.h"
#include "../MCAL/KEYPAD_DRIVER/KEYPAD.h"

int main(void) {

	// Initializes the Buttons

	SEGMENT_Init(PORT_C);
	KEYPAD_Init();

	uint8 key = 0;

	while (1) {
		key = KEYPAD_getPressedKey();

		if ( (key >= 0) && (key <= 9) ) {
			SEGMENT_DISPLAY(PORT_C, key);
		}
	}
}



