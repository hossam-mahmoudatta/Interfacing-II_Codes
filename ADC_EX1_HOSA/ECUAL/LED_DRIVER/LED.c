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

#include "LED.h"
#include "avr/io.h" /* To use the IO Ports Registers */

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
LED_Error_t LED_Init(uint8 port_num, uint8 pin_num) {
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	uint8_t LED_Driver_Checker = NULL;
	if((pin_num >= NUM_OF_PINS_PER_PORT)) {
		LED_Driver_Checker = LED_WRONG_PIN_NUMBER;
	}
	else if((port_num >= NUM_OF_PORTS)) {
		LED_Driver_Checker = LED_WRONG_PORT_NUMBER;
	}
	else {
		/* Setup the pin direction as required */
		GPIO_setupPinDirection(port_num, pin_num, PIN_OUTPUT);
		LED_Driver_Checker = LED_OK;
	}
	return LED_Driver_Checker;
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
LED_Error_t LED_On(uint8 port_num, uint8 pin_num) {

	uint8_t LED_Driver_Checker = NULL;
		if((pin_num >= NUM_OF_PINS_PER_PORT)) {
			LED_Driver_Checker = LED_WRONG_PIN_NUMBER;
		}
		else if((port_num >= NUM_OF_PORTS)) {
			LED_Driver_Checker = LED_WRONG_PORT_NUMBER;
		}
		else {
			/* Setup the pin direction as required */
			#if (LED_MODE == LED_NEGATIVE_LOGIC)
				GPIO_writePin(port_num, pin_num, LOGIC_LOW);
				LED_Driver_Checker = LED_OK;
			#elif (LED_MODE == LED_POSITIVE_LOGIC)
				GPIO_writePin(port_num, pin_num, LOGIC_HIGH);
				LED_Driver_Checker = LED_OK;
			#endif
		}
		return LED_Driver_Checker;
}

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
LED_Error_t LED_Off(uint8 port_num, uint8 pin_num) {

	uint8_t LED_Driver_Checker = NULL;
		if((pin_num >= NUM_OF_PINS_PER_PORT)) {
			LED_Driver_Checker = LED_WRONG_PIN_NUMBER;
		}
		else if((port_num >= NUM_OF_PORTS)) {
			LED_Driver_Checker = LED_WRONG_PORT_NUMBER;
		}
		else {
			/* Setup the pin direction as required */
			#if (LED_MODE == LED_NEGATIVE_LOGIC)
				GPIO_writePin(port_num, pin_num, LOGIC_HIGH);
				LED_Driver_Checker = LED_OK;
			#elif (LED_MODE == LED_POSITIVE_LOGIC)
				GPIO_writePin(port_num, pin_num, LOGIC_LOW);
				LED_Driver_Checker = LED_OK;
			#endif
		}
		return LED_Driver_Checker;
}

LED_Error_t LED_Toggle(uint8 port_num, uint8 pin_num) {

	uint8_t LED_Driver_Checker = NULL;
		if((pin_num >= NUM_OF_PINS_PER_PORT)) {
			LED_Driver_Checker = LED_WRONG_PIN_NUMBER;
		}
		else if((port_num >= NUM_OF_PORTS)) {
			LED_Driver_Checker = LED_WRONG_PORT_NUMBER;
		}
		else {
			/* Setup the pin direction as required */
			GPIO_togglePin(port_num, pin_num);
			LED_Driver_Checker = LED_OK;
		}
		return LED_Driver_Checker;
}
