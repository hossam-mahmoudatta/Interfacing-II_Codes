/******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: KEYPAD.c
 *
 * Description: Source file for the AVR KEYPAD Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#include "KEYPAD.h"

#include "avr/io.h" /* To use the IO Ports Registers */

#ifndef STANDARD_KEYPAD

	#if (KEYPAD_COL_NUM == 3)
	/*
	 * Function responsible for mapping the switch number in the keypad to
	 * its corresponding functional number in the proteus for 4x3 keypad
	 */
		static uint8 KEYPAD_4x3_adjustKeyNumber(uint8 button_number);
	#elif (KEYPAD_COL_NUM == 4)
	/*
	 * Function responsible for mapping the switch number in the keypad to
	 * its corresponding functional number in the proteus for 4x4 keypad
	 */
		static uint8 KEYPAD_4x4_adjustKeyNumber(uint8 button_number);
	#endif

#endif /* STANDARD_KEYPAD */


void KEYPAD_Init(void) {
		/* Setup PORT and PINS for for KEYPAD Rows*/
		GPIO_setupPinDirection(KEYPAD_ROW_PORT, KEYPAD_FIRSTROW_PIN, PIN_INPUT);
		GPIO_setupPinDirection(KEYPAD_ROW_PORT, KEYPAD_FIRSTROW_PIN+1, PIN_INPUT);
		GPIO_setupPinDirection(KEYPAD_ROW_PORT, KEYPAD_FIRSTROW_PIN+2, PIN_INPUT);
		GPIO_setupPinDirection(KEYPAD_ROW_PORT, KEYPAD_FIRSTROW_PIN+3, PIN_INPUT);

		/* Setup PORT and PINS for for KEYPAD Columns*/
		GPIO_setupPinDirection(KEYPAD_COL_PORT, KEYPAD_FIRSTCOL_PIN, PIN_INPUT);
		GPIO_setupPinDirection(KEYPAD_COL_PORT, KEYPAD_FIRSTCOL_PIN+1, PIN_INPUT);
		GPIO_setupPinDirection(KEYPAD_COL_PORT, KEYPAD_FIRSTCOL_PIN+2, PIN_INPUT);

		#if(KEYPAD_COL_NUM == 4)
			GPIO_setupPinDirection(KEYPAD_COL_PORT, KEYPAD_FIRSTCOL_PIN+3, PIN_INPUT);
		#endif
}



uint8 KEYPAD_getPressedKey(void) {

}



KEYPAD_Error_t SEGMENT_DISPLAY(uint8 port_num, uint8 value) {
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	uint8_t SEGMENT_Driver_Checker = NULL;

	if((port_num >= NUM_OF_PORTS)) {
		SEGMENT_Driver_Checker = SEGMENT_WRONG_PORT_NUMBER;
	}
	else if((value < 0 && value > 9)) {
		SEGMENT_Driver_Checker = SEGMENT_WRONG_VALUE;
	}
	else {
		switch(value) {
			case 0:
				GPIO_writePin(port_num, PIN_0, LOGIC_LOW);
				GPIO_writePin(port_num, PIN_1, LOGIC_LOW);
				GPIO_writePin(port_num, PIN_2, LOGIC_LOW);
				GPIO_writePin(port_num, PIN_3, LOGIC_LOW);
				break;
			case 1:
				GPIO_writePin(port_num, PIN_0, LOGIC_HIGH);
				GPIO_writePin(port_num, PIN_1, LOGIC_LOW);
				GPIO_writePin(port_num, PIN_2, LOGIC_LOW);
				GPIO_writePin(port_num, PIN_3, LOGIC_LOW);
				break;
			case 2:
				GPIO_writePin(port_num, PIN_0, LOGIC_LOW);
				GPIO_writePin(port_num, PIN_1, LOGIC_HIGH);
				GPIO_writePin(port_num, PIN_2, LOGIC_LOW);
				GPIO_writePin(port_num, PIN_3, LOGIC_LOW);
				break;
			case 3:
				GPIO_writePin(port_num, PIN_0, LOGIC_HIGH);
				GPIO_writePin(port_num, PIN_1, LOGIC_HIGH);
				GPIO_writePin(port_num, PIN_2, LOGIC_LOW);
				GPIO_writePin(port_num, PIN_3, LOGIC_LOW);
				break;
			case 4:
				GPIO_writePin(port_num, PIN_0, LOGIC_LOW);
				GPIO_writePin(port_num, PIN_1, LOGIC_LOW);
				GPIO_writePin(port_num, PIN_2, LOGIC_HIGH);
				GPIO_writePin(port_num, PIN_3, LOGIC_LOW);
				break;
			case 5:
				GPIO_writePin(port_num, PIN_0, LOGIC_HIGH);
				GPIO_writePin(port_num, PIN_1, LOGIC_LOW);
				GPIO_writePin(port_num, PIN_2, LOGIC_HIGH);
				GPIO_writePin(port_num, PIN_3, LOGIC_LOW);
				break;
			case 6:
				GPIO_writePin(port_num, PIN_0, LOGIC_LOW);
				GPIO_writePin(port_num, PIN_1, LOGIC_HIGH);
				GPIO_writePin(port_num, PIN_2, LOGIC_HIGH);
				GPIO_writePin(port_num, PIN_3, LOGIC_LOW);
				break;
			case 7:
				GPIO_writePin(port_num, PIN_0, LOGIC_HIGH);
				GPIO_writePin(port_num, PIN_1, LOGIC_HIGH);
				GPIO_writePin(port_num, PIN_2, LOGIC_HIGH);
				GPIO_writePin(port_num, PIN_3, LOGIC_LOW);
				break;
			case 8:
				GPIO_writePin(port_num, PIN_0, LOGIC_LOW);
				GPIO_writePin(port_num, PIN_1, LOGIC_LOW);
				GPIO_writePin(port_num, PIN_2, LOGIC_LOW);
				GPIO_writePin(port_num, PIN_3, LOGIC_HIGH);
				break;
			case 9:
				GPIO_writePin(port_num, PIN_0, LOGIC_HIGH);
				GPIO_writePin(port_num, PIN_1, LOGIC_LOW);
				GPIO_writePin(port_num, PIN_2, LOGIC_LOW);
				GPIO_writePin(port_num, PIN_3, LOGIC_HIGH);
				break;
		}
		SEGMENT_Driver_Checker = SEGMENT_OK;
	}
	return SEGMENT_Driver_Checker;
}
