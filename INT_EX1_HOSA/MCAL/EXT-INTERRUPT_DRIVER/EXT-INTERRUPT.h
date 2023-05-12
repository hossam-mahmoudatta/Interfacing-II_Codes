 /******************************************************************************
 *
 * Module: ADC (Analog to Digital Converter)
 *
 * File Name: ADC.h
 *
 * Description: Header file for the AVR ADC Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#ifndef EXT-INTERRUPT_H_
#define EXT-INTERRUPT_H_

#include "../GPIO_DRIVER/GPIO.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/COMMON_MACROS.h"


/*******************************************************************************
 *                                								Definitions                                  					      *
 *******************************************************************************/

#define SREG_I_BIT												7

// Defining the ISCXX Bits 0-3 in INT0, INT1 for the MCUCR
#define EXT_INTERRUPT_Low_Level					0
#define EXT_INTERRUPT_Logical_Change		1
#define EXT_INTERRUPT_Falling_Edge				2
#define EXT_INTERRUPT_Rising_Edge				3

// Defining the ISC2 Bit6 in INT2 for the MCUCSR
#define EXT_INTERRUPT_INT2_Falling_Edge		0
#define EXT_INTERRUPT_INT2_Rising_Edge		1

// Initializing the mode for the interrupts
#define EXT_INTERRUPT_0_MODE						EXT_INTERRUPT_Rising_Edge
#define EXT_INTERRUPT_1_MODE						EXT_INTERRUPT_Falling_Edge
#define EXT_INTERRUPT_2_MODE						EXT_INTERRUPT_Falling_Edge


/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/

// Initialize External Interrupt
void EXT_INTERRUPT_Init(void);

// Enable External Interrupt 0 ISR
void EXT_INTERRUPT_Enable_INT0(void);

// Disable External Interrupt 0 ISR
void EXT_INTERRUPT_Disable_INT0(void);

// Enable External Global Interrupt
void EXT_INTERRUPT_EnableGlobalInterrupt(void);

// Disable External Global Interrupt
void EXT_INTERRUPT_DisableGlobalInterrupt(void);

// We'll add for the other INTs but later


//The function that will be called in the EXT INT
void (*CallBackPtr) (void);

// External Interrupt Call Back Function
void EXT_INTERRUPT_SetCallBack(void (*CopyFuncPtr) (void));

//
void __vector_1(void);


//void vector (void) __attribute__ ((signal, __INTR_ATTRS)) __VA_ARGS__;
//void INT0_vect (void) {}



#endif /* EXT-INTERRUPT_H_ */


