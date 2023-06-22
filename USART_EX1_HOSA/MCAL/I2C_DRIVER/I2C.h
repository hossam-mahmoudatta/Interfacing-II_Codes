 /******************************************************************************
 *
 * Module: I2C (Inter Integrated Circuit)
 *
 * File Name: I2C.h
 *
 * Description: Header file for the AVR I2C Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#ifndef I2C_H_
#define I2C_H_

#include "../GPIO_DRIVER/GPIO.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/COMMON_MACROS.h"

// A better naming for the I2C Connection pins
#define SCL 		PIN_0
#define SDA 		PIN_1
#define SPI_DEF_DATA_VAL 0xFF // The default data value in the SPDR

/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/

// Initializes and enables the SPI Module to start functionality
void I2C_init(void);
void I2C_start(void);
void I2C_stop(void);
void I2C_writeByte(void);
void I2C_readByteWithACK(void);
void I2C_readByteWithNACK(void);
void I2C_getStatus(void);


// Responsible for the SPI to send & receive a byte
void SPI_sendReceiveByte(const uint8 data);

// Responsible for the SPI to send an array of bytes, a string
void SPI_sendString(const uint8 *str);

// Responsible for the SPI to receive an array of bytes, a string
void SPI_receiveString(uint8 *str);

#endif /* USART_H_ */
