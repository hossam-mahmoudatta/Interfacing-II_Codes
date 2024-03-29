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

#include "GPIO.h"

#include "avr/io.h" /* To use the IO Ports Registers */


/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
GPIO_Error_t GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction) {
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	uint8_t GPIO_Driver_Checker = NULL;

	if((pin_num >= NUM_OF_PINS_PER_PORT)) {
		GPIO_Driver_Checker = GPIO_WRONG_PIN_NUMBER;
	}
	else if((port_num >= NUM_OF_PORTS)) {
		GPIO_Driver_Checker = GPIO_WRONG_PORT_NUMBER;
	}
	else if((direction != PIN_INPUT) && (direction != PIN_OUTPUT)) {
		GPIO_Driver_Checker = GPIO_WRONG_DIRECTION;
	}
	else {
		/* Setup the pin direction as required */
		switch(port_num) {
		case PORT_A:
			if(direction == PIN_OUTPUT) {
				SET_BIT(DDRA, pin_num);
			}
			else {
				CLR_BIT(DDRA, pin_num);
			}
			break;
		case PORT_B:
			if(direction == PIN_OUTPUT) {
				SET_BIT(DDRB,pin_num);
			}
			else {
				CLR_BIT(DDRB,pin_num);
			}
			break;
		case PORT_C:
			if(direction == PIN_OUTPUT) {
				SET_BIT(DDRC,pin_num);
			}
			else {
				CLR_BIT(DDRC,pin_num);
			}
			break;
		case PORT_D:
			if(direction == PIN_OUTPUT) {
				SET_BIT(DDRD,pin_num);
			}
			else {
				CLR_BIT(DDRD,pin_num);
			}
			break;
		}
		GPIO_Driver_Checker = GPIO_OK;
	}
	return GPIO_Driver_Checker;
}

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
GPIO_Error_t GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value) {
	uint8_t GPIO_Driver_Checker = NULL;

	if((pin_num >= NUM_OF_PINS_PER_PORT)) {
		GPIO_Driver_Checker = GPIO_WRONG_PIN_NUMBER;
	}
	else if((port_num >= NUM_OF_PORTS)) {
		GPIO_Driver_Checker = GPIO_WRONG_PORT_NUMBER;
	}
	else if((value != LOGIC_HIGH) && (value != LOGIC_LOW)) {
		GPIO_Driver_Checker = GPIO_WRONG_DIRECTION;
	}
	else {
		switch(port_num) {
		case PORT_A:
			if(value == LOGIC_HIGH) {
				SET_BIT(PORTA,pin_num);
			}
			else {
				CLR_BIT(PORTA,pin_num);
			}
			break;
		case PORT_B:
			if(value == LOGIC_HIGH) {
				SET_BIT(PORTB,pin_num);
			}
			else {
				CLR_BIT(PORTB,pin_num);
			}
			break;
		case PORT_C:
			if(value == LOGIC_HIGH) {
				SET_BIT(PORTC,pin_num);
			}
			else {
				CLR_BIT(PORTC,pin_num);
			}
			break;
		case PORT_D:
			if(value == LOGIC_HIGH) {
				SET_BIT(PORTD,pin_num);
			}
			else {
				CLR_BIT(PORTD,pin_num);
			}
			break;
		}
		GPIO_Driver_Checker = GPIO_OK;
	}
	return GPIO_Driver_Checker;
}


GPIO_Error_t GPIO_togglePin(uint8 port_num, uint8 pin_num) {
	uint8_t GPIO_Driver_Checker = NULL;

	if((pin_num >= NUM_OF_PINS_PER_PORT)) {
		GPIO_Driver_Checker = GPIO_WRONG_PIN_NUMBER;
	}
	else if((port_num >= NUM_OF_PORTS)) {
		GPIO_Driver_Checker = GPIO_WRONG_PORT_NUMBER;
	}
	else {
		switch(port_num) {
		case PORT_A:
			TOG_BIT(PORTA,pin_num);
			break;
		case PORT_B:
			TOG_BIT(PORTB,pin_num);
			break;
		case PORT_C:
			TOG_BIT(PORTC,pin_num);
			break;
		case PORT_D:
			TOG_BIT(PORTD,pin_num);
			break;
		}
		GPIO_Driver_Checker = GPIO_OK;
	}
	return GPIO_Driver_Checker;
}



/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num) {
	uint8 pin_value = LOGIC_LOW;

	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	uint8_t GPIO_Driver_Checker = NULL;

	if((pin_num >= NUM_OF_PINS_PER_PORT)) {
		GPIO_Driver_Checker = GPIO_WRONG_PIN_NUMBER;
	}
	else if((port_num >= NUM_OF_PORTS)) {
		GPIO_Driver_Checker = GPIO_WRONG_PORT_NUMBER;
	}
	else {
		/* Read the pin value as required */
		switch(port_num) {
		case PORT_A:
			if(BIT_IS_SET(PINA,pin_num)) {
				pin_value = LOGIC_HIGH;
			}
			else {
				pin_value = LOGIC_LOW;
			}
			break;
		case PORT_B:
			if(BIT_IS_SET(PINB,pin_num)) {
				pin_value = LOGIC_HIGH;
			}
			else {
				pin_value = LOGIC_LOW;
			}
			break;
		case PORT_C:
			if(BIT_IS_SET(PINC,pin_num)) {
				pin_value = LOGIC_HIGH;
			}
			else {
				pin_value = LOGIC_LOW;
			}
			break;
		case PORT_D:
			if(BIT_IS_SET(PIND,pin_num)) {
				pin_value = LOGIC_HIGH;
			}
			else {
				pin_value = LOGIC_LOW;
			}
			break;
		}
		GPIO_Driver_Checker = GPIO_OK;
	}
	return pin_value;
}


/*
 * Description :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 */
GPIO_Error_t GPIO_setupPortDirection(uint8 port_num, GPIO_PortDirectionType direction) {
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	uint8_t GPIO_Driver_Checker = NULL;

	if((port_num >= NUM_OF_PORTS)) {
		GPIO_Driver_Checker = GPIO_WRONG_PORT_NUMBER;
	}
	else if((direction != PORT_INPUT) && (direction != PORT_OUTPUT)) {
		GPIO_Driver_Checker = GPIO_WRONG_DIRECTION;
	}
	else {
		/* Setup the port direction as required */
		switch(port_num) {
		case PORT_A:
			DDRA = direction;
			break;
		case PORT_B:
			DDRB = direction;
			break;
		case PORT_C:
			DDRC = direction;
			break;
		case PORT_D:
			DDRD = direction;
			break;
		}
		GPIO_Driver_Checker = GPIO_OK;
	}
	return GPIO_Driver_Checker;
}

/*
 * Description :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 */
GPIO_Error_t GPIO_writePort(uint8 port_num, uint8 value) {

	uint8_t GPIO_Driver_Checker = NULL;
	if((port_num >= NUM_OF_PORTS)) {
		GPIO_Driver_Checker = GPIO_WRONG_PORT_NUMBER;
	}
	else if((value != LOGIC_HIGH) && (value != LOGIC_LOW)) {
		GPIO_Driver_Checker = GPIO_WRONG_DIRECTION;
	}
	else {
		/* Setup the port direction as required */
		switch(port_num) {
		case PORT_A:
			PORTA = value;
			break;
		case PORT_B:
			PORTB = value;
			break;
		case PORT_C:
			PORTC = value;
			break;
		case PORT_D:
			PORTD = value;
			break;
		}
		GPIO_Driver_Checker = GPIO_OK;
	}
	return GPIO_Driver_Checker;
}

/*
 * Description :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 */
uint8 GPIO_readPort(uint8 port_num) {
	uint8 value = LOGIC_LOW;
	uint8_t GPIO_Driver_Checker = NULL;

	if((port_num >= NUM_OF_PORTS)) {
		GPIO_Driver_Checker = GPIO_WRONG_PORT_NUMBER;
	}
	else {
		switch(port_num) {
		case PORT_A:
			value = PINA;
			break;
		case PORT_B:
			value = PINB;
			break;
		case PORT_C:
			value = PINC;
			break;
		case PORT_D:
			value = PIND;
			break;
		}
	}
	return value;
}
