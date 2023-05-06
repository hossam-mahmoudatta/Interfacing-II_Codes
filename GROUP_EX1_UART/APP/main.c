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
#include "../MCAL/KEYPAD_DRIVER/KEYPAD.h"
// #include "../MCAL/LCD_DRIVER/LCD.h"
#include "../MCAL/UART_DRIVER/uart.h"

int main(void) {
	// Initializes the UART
	UART_init(9600);

	// Initializes the UART
	KEYPAD_Init();

	//uint8 data;

	while (1) {
		uint8 key = KEYPAD_getPressedKey();
		UART_sendByte(key);
	}
}



