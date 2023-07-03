 /******************************************************************************
 *
 * Module: MOTORS
 *
 * File Name: MOTOR.h
 *
 * Description: Header file for the External Motor Drivers
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              					 Application Libraries                                				  	  *
 *******************************************************************************/

#ifndef MOTOR_H_
#define MOTOR_H_

#include "../../MCAL/GPIO_DRIVER/GPIO.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/COMMON_MACROS.h"

/*******************************************************************************
 *                                								Definitions                                  					      *
 *******************************************************************************/

#define DCMOTOR_INPUT_PORT				PORTA
#define DCMOTOR_CLOCKWISE				PIN_0
#define DCMOTOR_ANTICLOCKWISE		PIN_1
#define DCMOTOR_OFF								PIN_2

#define DCMOTOR_OUTPUT_PORT			PORTC
#define DCMOTOR_OUTPUT_PIN				PIN_0

/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/

// Initializes and enables the Motors Module to start functionality

void MOTOR_dcMotorInit(void);
void MOTOR_dcMotorControl(void);

//void MOTOR_stepperInit(void);

//void MOTOR_servoInit(void);


#endif /* MOTOR_H_ */
