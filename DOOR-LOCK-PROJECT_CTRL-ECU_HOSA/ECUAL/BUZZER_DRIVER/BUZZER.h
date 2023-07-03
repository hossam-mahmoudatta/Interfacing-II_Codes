 /******************************************************************************
 *
 * Module: Buzzer
 *
 * File Name: BUZZER.h
 *
 * Description: Header file for the AVR Buzzer Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              					 Application Libraries                                				  *
 *******************************************************************************/

#ifndef BUZZER_H_
#define BUZZER_H_

#include "../../MCAL/GPIO_DRIVER/GPIO.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/COMMON_MACROS.h"

/*******************************************************************************
 *                                									Definitions                     					           		  *
 *******************************************************************************/

#define LED_NEGATIVE_LOGIC				0
#define LED_POSITIVE_LOGIC				1

#define LED_MODE									LED_POSITIVE_LOGIC

/*******************************************************************************
 *                             							 Functions Prototypes                       	    			      *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction of the required pin input/output.
 */
void Buzzer_Init(uint8 port_num, uint8 pin_num);

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 */
void Buzzer_On(uint8 port_num, uint8 pin_num);


/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 */
void Buzzer_Off(uint8 port_num, uint8 pin_num);


#endif /* BUZZER_H_ */
