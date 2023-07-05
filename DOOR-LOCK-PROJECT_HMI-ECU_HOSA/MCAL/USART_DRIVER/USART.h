 /******************************************************************************
 *
 * Module: USART (Universal Synchronous Asynchronous Receiver Transmitter)
 *
 * File Name: USART.h
 *
 * Description: Header file for the AVR USART Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#ifndef USART_H_
#define USART_H_

#include "../GPIO_DRIVER/GPIO.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/COMMON_MACROS.h"


typedef enum {
    USART_5_BIT,
    USART_6_BIT,
    USART_7_BIT,
    USART_8_BIT,
	USART_9_BIT = 7,
} 	USART_BitData;

typedef enum {
    USART_PARITY_DISABLED,
    USART_PARITY_EVEN = 2,
    USART_PARITY_ODD = 3,
} 	USART_Parity;

typedef enum {
    USART_STOP_1_BIT,
    USART_STOP_2_BIT
} 	USART_StopBit;

typedef enum {
	USART_BAUDRATE_2400 = 2400,
	USART_BAUDRATE_4800 = 4800,
	USART_BAUDRATE_9600 = 9600,
	USART_BAUDRATE_14400 = 14400,
}	USART_BaudRate;

typedef struct {
	USART_BitData bitData;
	USART_Parity parity;
	USART_StopBit stopBit;
	USART_BaudRate baudRate;
}	USART_ConfigType;


/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/

// Initializes and enables the USART Module to start functionality
void USART_Init(const USART_ConfigType *USART_ConfigPtr);

// Responsible for the USART to send a byte
void USART_sendByte(const uint8 data);

// Responsible for the USART to receive a byte
uint8 USART_receiveByte(void);

// Responsible for the USART to send an array of bytes, a string
void USART_sendString(const uint8 *str);

// Responsible for the USART to receive an array of bytes, a string
void USART_receiveString(uint8 *str);

#endif /* USART_H_ */
