 /******************************************************************************
 *
 * Module: MOTORS
 *
 * File Name: MOTOR.h
 *
 * Description: Source file for the External Motor Drivers
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              					 Application Libraries                                				  	  *
 *******************************************************************************/

#include "MOTOR.h"
#include "avr/io.h" /* To use the IO Ports Registers */
#include <util/delay.h>

/*******************************************************************************
 *                              					Module Implementation                           					  	  *
 *******************************************************************************/

// Initializes and enables the ADC Module to start functionality

void MOTOR_dcMotorInit() {
	// Configuring the Input pins to control the Motor
	GPIO_setupPinDirection(DCMOTOR_INPUT_PORT, DCMOTOR_CLOCKWISE, PIN_INPUT);
	GPIO_setupPinDirection(DCMOTOR_INPUT_PORT, DCMOTOR_ANTICLOCKWISE, PIN_INPUT);
	GPIO_setupPinDirection(DCMOTOR_INPUT_PORT, DCMOTOR_OFF, PIN_INPUT);

	GPIO_setupPinDirection(DCMOTOR_OUTPUT_PORT, DCMOTOR_OUTPUT_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(DCMOTOR_OUTPUT_PORT, DCMOTOR_OUTPUT_PIN + 1, PIN_OUTPUT);
}

void MOTOR_dcMotorControl(void) {
	// Configuring the Input pins to control the Motor
	MOTOR_dcMotorInit();

	// SETTING THE BITS OF THE L293D CHIP CONTROLLING THE MOTORS
	if (BIT_IS_SET(DCMOTOR_INPUT_PORT, DCMOTOR_CLOCKWISE)) {
		CLR_BIT(DCMOTOR_OUTPUT_PORT, DCMOTOR_OUTPUT_PIN);
		SET_BIT(DCMOTOR_OUTPUT_PORT, (DCMOTOR_OUTPUT_PIN + 1));
	}

	else if (BIT_IS_SET(DCMOTOR_INPUT_PORT, DCMOTOR_ANTICLOCKWISE)) {
		SET_BIT(DCMOTOR_OUTPUT_PORT, DCMOTOR_OUTPUT_PIN);
		CLR_BIT(DCMOTOR_OUTPUT_PORT, (DCMOTOR_OUTPUT_PIN + 1));
	}

	else if (BIT_IS_SET(DCMOTOR_INPUT_PORT, DCMOTOR_OFF)) {
		CLR_BIT(DCMOTOR_OUTPUT_PORT, DCMOTOR_OUTPUT_PIN);
		CLR_BIT(DCMOTOR_OUTPUT_PORT, (DCMOTOR_OUTPUT_PIN + 1));
	}
}

//void MOTOR_stepperInit(void);

//void MOTOR_servoInit(void);
