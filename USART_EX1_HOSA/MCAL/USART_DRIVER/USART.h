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

#ifndef USART_H_
#define USART_H_

#include "../GPIO_DRIVER/GPIO.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/COMMON_MACROS.h"


/*******************************************************************************
 *                                								Definitions                                  					      *
 *******************************************************************************/

#define ADC_MAX_VALUE 								1023
#define ADC_REFERENCE_VOLT_VALUE 	5


/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/

// Initializes and enables the ADC Module to start functionality
void USART_Init(uint32 baudRate);

uint8 USART_sendByte1(const uint8 data);

uint8 USART_sendByte2(const uint8 data);

uint8 USART_receiveByte(void);

void USART_sendString(const uint8 *str);

void USART_receiveString(uint8 *str);

#endif /* USART_H_ */
