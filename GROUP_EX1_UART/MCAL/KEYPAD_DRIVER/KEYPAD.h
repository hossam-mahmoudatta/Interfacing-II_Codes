 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: KEYPAD.h
 *
 * Description: Header file for the AVR KEYPAD Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../GPIO_DRIVER/GPIO.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/COMMON_MACROS.h"


/*******************************************************************************
 *                                									Definitions                                  					  *
 *******************************************************************************/


/*******************************************************************************
 *                               							Types Declaration                            	 					  *
 *******************************************************************************/

#define KEYPAD_COL_NUM			4
#define KEYPAD_ROW_NUM			4

#define KEYPAD_COL_PORT			PORT_B
#define KEYPAD_ROW_PORT			PORT_B

#define KEYPAD_FIRSTCOL_PIN		PIN_0
#define KEYPAD_FIRSTROW_PIN		PIN_4

#define KEYPAD_BUTTON_PRESSED				LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED			LOGIC_HIGH


/*******************************************************************************
 *                              						Functions Prototypes                          						  *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void KEYPAD_Init(void);

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
uint8 KEYPAD_getPressedKey(void);

#endif /* SEVEN-SEGMENT_H_ */
