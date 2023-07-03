/******************************************************************************
 *
 * Module: Buzzer
 *
 * File Name: BUZZER.c
 *
 * Description: Source file for the AVR Buzzer Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              					 Application Libraries                                				  *
 *******************************************************************************/

#include "BUZZER.h"

#include "avr/io.h" /* To use the IO Ports Registers */

/*******************************************************************************
 *                              					Module Implementation                           					  	  *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction of the required pin input/output.
 */
void Buzzer_Init(uint8 port_num, uint8 pin_num) {
	/* Setup the pin direction as required */
	GPIO_setupPinDirection(port_num, pin_num, PIN_OUTPUT);
	GPIO_writePin(port_num, pin_num, LOGIC_LOW);
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 */
void Buzzer_On(uint8 port_num, uint8 pin_num) {
	/* Setup the pin direction as required */
	GPIO_writePin(port_num, pin_num, LOGIC_HIGH);
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 */
void Buzzer_Off(uint8 port_num, uint8 pin_num) {
	/* Setup the pin direction as required */
	GPIO_writePin(port_num, pin_num, LOGIC_LOW);
}
