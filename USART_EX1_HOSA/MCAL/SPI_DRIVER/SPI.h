 /******************************************************************************
 *
 * Module: SPI (Serial Peripheral Interface)
 *
 * File Name: SPI.h
 *
 * Description: Header file for the AVR SPI Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#ifndef SPI_H_
#define SPI_H_

#include "../GPIO_DRIVER/GPIO.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/COMMON_MACROS.h"

#define SS 		PIN_4
#define MOSI 	PIN_5
#define MISO 	PIN_6
#define SCK 		PIN_7

/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/

// Initializes and enables the SPI Module to start functionality
void SPI_Init(void);

// Responsible for the USART to send a byte
void USART_sendByte(const uint8 data);

// Responsible for the USART to receive a byte
uint8 USART_receiveByte(void);

// Responsible for the USART to send an array of bytes, a string
void USART_sendString(const uint8 *str);

// Responsible for the USART to receive an array of bytes, a string
void USART_receiveString(uint8 *str);

#endif /* USART_H_ */
