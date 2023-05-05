 /******************************************************************************
 *
 * Module: LCD Display
 *
 * File Name: LCD.h
 *
 * Description: Header file for the AVR LCD Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#include "LCD.h"

#include "avr/io.h" /* To use the IO Ports Registers */
#include <util/delay.h>

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void LCD_Init(void) {
		// Initialize RS Pin
		GPIO_setupPinDirection(LCD_INIT_PORT, LCD_RS, PIN_OUTPUT);

		// Initialize Enable Pin
		GPIO_setupPinDirection(LCD_INIT_PORT, LCD_ENABLE, PIN_OUTPUT);

		// Setup the port and pins for the data pins inside the LCD
		GPIO_setupPortDirection(LCD_DATA_PORT, PORT_OUTPUT);
		GPIO_setupPinDirection(LCD_DATA_PORT, PIN_0, PIN_OUTPUT);
		GPIO_setupPinDirection(LCD_DATA_PORT, PIN_1, PIN_OUTPUT);
		GPIO_setupPinDirection(LCD_DATA_PORT, PIN_2, PIN_OUTPUT);
		GPIO_setupPinDirection(LCD_DATA_PORT, PIN_3, PIN_OUTPUT);
		GPIO_setupPinDirection(LCD_DATA_PORT, PIN_4, PIN_OUTPUT);
		GPIO_setupPinDirection(LCD_DATA_PORT, PIN_5, PIN_OUTPUT);
		GPIO_setupPinDirection(LCD_DATA_PORT, PIN_6, PIN_OUTPUT);
		GPIO_setupPinDirection(LCD_DATA_PORT, PIN_7, PIN_OUTPUT);

		// LCD Power On Internal Delay is 15 mS
		_delay_ms(25);

		//Initializing Sending Commands
		LCD_sendCommand(LCD_TWO_LINE_EIGHT_BIT);
		LCD_sendCommand(LCD_CURSOR_OFF);
		LCD_sendCommand(LCD_CLEAR_DISPLAY);
}


void LCD_sendCommand(uint8 command) {
	// Set RS Pin to '0'
	GPIO_writePin(LCD_INIT_PORT, LCD_RS, LOGIC_LOW);
	_delay_ms(1);

	// Set Enable Pin to '1'
	GPIO_writePin(LCD_INIT_PORT, LCD_ENABLE, LOGIC_HIGH);
	_delay_ms(1);

	// Send command
	GPIO_writePort(LCD_DATA_PORT, command);
	_delay_ms(1);

	// Set Enable Pin to '0'
	GPIO_writePin(LCD_INIT_PORT, LCD_ENABLE, LOGIC_LOW);
	_delay_ms(1);
}


void LCD_displayCharacters(uint8 data) {
	// Set RS Pin to '1'
	GPIO_writePin(LCD_INIT_PORT, LCD_RS, LOGIC_HIGH);
	_delay_ms(1);

	// Set Enable Pin to '1'
	GPIO_writePin(LCD_INIT_PORT, LCD_ENABLE, LOGIC_HIGH);
	_delay_ms(1);

	// Send command
	GPIO_writePort(LCD_DATA_PORT, data);
	_delay_ms(1);

	// Set Enable Pin to '0'
	GPIO_writePin(LCD_INIT_PORT, LCD_ENABLE, LOGIC_LOW);
	_delay_ms(1);
}


void LCD_displayString(const char *str) {
	uint8 i = 0;
	while(str[i] != '\0') {
		LCD_displayCharacters(str[i]);
		i++;
	}
	/*
	for (int i = 0 ; i < strlen(str) ; i++) {
		LCD_displayCharacters(str[i]);
	}*/
}


void LCD_moveCursor(uint8 row, uint8 col) {

	uint8 LCD_MEMORY_ADDRESS;

	// Calculate the required address in the LCD DDRAM checking
	// The location of the cursor originally on which line
	switch(row) {
		case 0:
			LCD_MEMORY_ADDRESS = col;
				break;
		case 1:
			LCD_MEMORY_ADDRESS = col + 0x40;
				break;
		case 2:
			LCD_MEMORY_ADDRESS = col + 0x10;
				break;
		case 3:
			LCD_MEMORY_ADDRESS = col + 0x50;
				break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(LCD_MEMORY_ADDRESS | LCD_CURSOR_LOCATION);
}


void LCD_displayStringRowColumn(uint8 row, uint8 col, const char *Str) {
	// Go to to the required LCD position
	LCD_moveCursor(row, col);

	// Display the string from the cursor
	LCD_displayString(Str);
}

void LCD_intgerToString(int data) {
	// A string to hold the ASCII values
	char buffer[16];

	// Converts data to its ASCII
	itoa(data, buffer, 10);

	// Display string with the results in the buffer
	LCD_displayString(buffer);
}

void LCD_clearScreen(void) {
	// Clears the LCD Display
	LCD_sendCommand(LCD_CLEAR_DISPLAY);
}

