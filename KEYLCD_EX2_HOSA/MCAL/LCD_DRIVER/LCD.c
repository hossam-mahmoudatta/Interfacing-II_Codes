/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: GPIO.c
 *
 * Description: Source file for the AVR GPIO driver
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
		// Setup the port and pins for the data pins inside the LCD
		GPIO_setupPortDirection(LCD_DATA_PORT, PORT_OUTPUT);

		// Initialize RS Pin
		GPIO_setupPinDirection(LCD_INIT_PORT, LCD_RS, PIN_OUTPUT);

		// Initialize Enable Pin
		GPIO_setupPinDirection(LCD_INIT_PORT, LCD_ENABLE, PIN_OUTPUT);

		// LCD Power On Internal Delay is 15 mS
		_delay_ms(20);

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













