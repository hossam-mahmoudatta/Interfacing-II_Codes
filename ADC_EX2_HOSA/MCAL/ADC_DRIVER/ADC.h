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

#ifndef ADC_H_
#define ADC_H_

#include "../GPIO_DRIVER/GPIO.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/COMMON_MACROS.h"


/*******************************************************************************
 *                                								Definitions                                  					      *
 *******************************************************************************/

#define ADC_MAX_VALUE 								1023
#define ADC_AREF    										5

#define ADC_REF_MODE									0
#if ( (ADC_REF_MODE != 0) && (ADC_REF_MODE != 1) && (ADC_REF_MODE != 3) )
	#error "Reference Selection Bit is wrong"
#endif

#define ADC_INTERRUPT_MODE					0
#if ( (ADC_INTERRUPT_MODE != 0) && (ADC_INTERRUPT_MODE != 1) )
	#error "INTERRUPT CONFIG Bit is wrong"
#endif

#define ADC_PRESCALER_MODE					6
#if ( (ADC_PRESCALER_MODE < 3) || (ADC_PRESCALER_MODE > 7) )
	#error "Prescaler Config Bits are wrong"
#endif


/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/

// Initializes and enables the ADC Module to start functionality
void ADC_Init(void);


 // Reads the content written to the selected channel of the ADC
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */

