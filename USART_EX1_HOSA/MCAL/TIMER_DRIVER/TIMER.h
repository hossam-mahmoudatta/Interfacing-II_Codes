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

/*******************************************************************************
 *                              					 Application Libraries                              					  *
 *******************************************************************************/

#ifndef TIMER_H_
#define TIMER_H_

#include "../GPIO_DRIVER/GPIO.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/COMMON_MACROS.h"

/*******************************************************************************
 *                              					Predecessor Macros                           					  *
 *******************************************************************************/

// A better naming for the I2C Connection pins
#define SCL 								PIN_0
#define SDA 								PIN_1
#define I2C_SLAVE_ADDR 		0x02	// Slave Address = 0b00000010
#define I2C_INITIALSTATUS 	0xF8	// Masking to eliminate 1st 3 bits & get last 5 bits 0b11111000

// I2C Status Bits in the TWSR Register, found in tables 74 & 75 in the Data sheet
#define I2C_START         				0x08 	// start has been sent
#define I2C_REP_START     			0x10 	// repeated start
#define I2C_MT_SLA_W_ACK 	0x18 	// Master transmit ( slave address + Write request ) to slave + ACK received from slave.
#define I2C_MT_SLA_W_NACK 	0x20 	// Master transmit ( slave address + Write request ) to slave + Not ACK received from slave.
#define I2C_MT_DATA_ACK		0x28 	// Master transmit data + ACK has been received from Slave.
#define I2C_MT_DATA_NACK   	0x30 	// Master transmit data + Not ACK has been received from Slave.
#define I2C_ARBIT_LOST   			0x38 	// Arbitration lost in (Slave + Write) or Data bytes
#define I2C_MT_SLA_R_ACK  	0x40 	// Master transmit ( slave address + Read request ) to slave + ACK received from slave.
#define I2C_MT_SLA_R_NACK  	0x48 	// Master transmit ( slave address + Read request ) to slave + Not ACK received from slave.
#define I2C_MR_DATA_ACK   		0x50 	// Master received data + received ACK from slave.
#define I2C_MR_DATA_NACK 	0x58 	// Master received data + received Not ACK from slave.


/* TCCR0 - Timer0 Control Register
  *  Bit 7 – FOC0: Force O/P Compare
  *  Bit 6, 3 - WGM01:0: Waveform Generation Mode
  *  Bit 5:4 – COM01:0: Compare Match O/P Mode
  *  Bit 2:0 – CS02:0: Clock Select
  */

/* TCCR1A - Timer1 Control Register A
  *  Bit 7:6 – COM1A1:0: Compare Output Mode for Compare unit A
  *  Bit 5:4 – COM1B1:0: Compare Output Mode for Compare unit B
  *  Bit 3 – FOC1A: Force Output Compare for Compare unit A
  *  Bit 2 – FOC1B: Force Output Compare for Compare unit B
  *  Bit 1:0 – WGM11:0: Waveform Generation Mode
  */

/* TCCR1B - Timer1 Control Register B
  *  Bit 7 – ICNC1: Input Capture Noise Canceler
  *  Bit 6 – ICES1: Input Capture Edge Select
  *  Bit 5 – Reserved Bit
  *  Bit 4:3 – WGM13:2: Waveform Generation Mode
  *  Bit 2:0 – CS12:0: Clock Select
  */

/* TIMSK - Timer Interrupt Mask Register
  *  Bit 1 – OCIE0: Output Compare Match Interrupt Enable
  *  Bit 0 – TOIE0: Timer Overflow Interrupt Enable
  */

/* TIFR - Timer Interrupt Flag Register
  *  Bit 1 – OCF0: Output Compare Flag 0
  *  Bit 0 – TOV0: Timer Overflow Flag
  */

/* TCNT0 - Timer Register
  *  Bit 7..0 – TCNT0: Timer Register
  */

/* TCNT1 - Timer Register
  *  Bit 15..8 – TCNT1H: Timer Register
  *  Bit 7..0 – TCNT1L: Timer Register
  */

/* TCNT0 - Timer Register
  *  Bit 7..0 – TCNT0: Timer Register
  */

/* OCR0 - Output Compare Register
  *	  Bit 7..0 – OCR0: Output Compare Register
  */

/* SFIOR - Special Function IO Register
  *	  Bit 0 – PSR10: Prescaler Reset Timer1 and Timer0
  */



/*******************************************************************************
 *                              						Functions Prototypes                           					  *
 *******************************************************************************/

// Initializes and enables the SPI Module to start functionality
void I2C_init(void);

// Responsible for the SPI to send an array of bytes, a string
void I2C_start(void);

// Responsible for the SPI to receive an array of bytes, a string
void I2C_stop(void);

// Responsible for the SPI to receive an array of bytes, a string
void I2C_writeByte(uint8 data);

// Responsible for the SPI to receive an array of bytes, a string
uint8 I2C_readByteWithACK(void);

// Responsible for the SPI to receive an array of bytes, a string
uint8 I2C_readByteWithNACK(void);

// Responsible for the SPI to receive an array of bytes, a string
uint8 I2C_getStatus(void);

#endif /* TIMER_H_ */
