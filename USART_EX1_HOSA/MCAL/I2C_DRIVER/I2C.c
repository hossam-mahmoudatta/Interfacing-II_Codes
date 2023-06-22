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

#include "I2C.h"

#include "avr/io.h" /* To use the IO Ports Registers */
#include <util/delay.h>

/* TWBR - TWI Bit Rate Register
  *  Bit 7..0 – TWBR: TWI Bit Rate Register
  */

/* TWCR - TWI Control Register
  *  Bit 7 – TWINT: TWI Interrupt Flag
  *  Bit 6 – TWEA: TWI Enable Acknowledge Bit
  *  Bit 5 – TWSTA: TWI Start Condition Bit
  *  Bit 4 – TWSTO: TWI Stop Condition Bit
  *  Bit 3 – TWWC: TWI Write Collision Flag
  *  Bit 2 – TWEN: TWI Enable Bit
  *  Bit 1 – RES: Reserved Bit
  *  Bit 0 – TWIE: TWI Interrupt Enable
  */

/* TWSR - TWI Status Register
  *  Bit 7..3 – TWS: TWI Status
  *  Bit 2 – Res: Reserved Bit
  *  Bit 1..0 – TWPS: TWI Prescaler Bits
  */

/* TWDR - TWI Data Register
  *  Bit 7..0 – TWDR: TWI Data Register
  */

/* TWAR - TWI (Slave) Address Register
  *  Bit 7..1 – TWA: TWI (Slave) Address Register
  *  Bit 0 – TWGCE: TWI General Call Recognition Enable Bit
  */


// Initializes and enables the Master mode for the TWI Module to start functionality
void I2C_init(void) {

	GPIO_setupPinDirection(PORT_B, SS, PIN_OUTPUT);
	GPIO_setupPinDirection(PORT_B, MOSI, PIN_OUTPUT);
	GPIO_setupPinDirection(PORT_B, MISO, PIN_INPUT);
	GPIO_setupPinDirection(PORT_B, SCK, PIN_OUTPUT);

	SET_BIT(SPCR, SPE); // Enabling the SPI Module
	SET_BIT(SPCR, MSTR); // Enabling the Master / Slave Mode; I will choose Master
	CLR_BIT(SPCR, SPR1); // Choosing the SCK rate, Fosc / 4
	CLR_BIT(SPCR, SPR0); // So SPR1, SPR0 = '00'

	CLR_BIT(SPSR, SPI2X); // Make SPI2X = '0' to support the Fosc / 4

}


// Initializes and enables the Slave mode for the SPI Module to start functionality
void SPI_initSlave(void) {
	/* Configure SPI Slave Pins
	 *	SS (PB4)   	--> 	Input
	 *	MOSI (PB5) --> 	Input
	 *	MISO (PB6) --> 	Output
	 *	SCK (PB7) 	--> 	Input
	 */
	GPIO_setupPinDirection(PORT_B, SS, PIN_INPUT);
	GPIO_setupPinDirection(PORT_B, MOSI, PIN_INPUT);
	GPIO_setupPinDirection(PORT_B, MISO, PIN_OUTPUT);
	GPIO_setupPinDirection(PORT_B, SCK, PIN_INPUT);

	/* SPCR - SPI Control Register
	  *  Bit 7 – SPIE: SPI Interrupt Enable
	  *  Bit 6 – SPE: SPI Enable
	  *  Bit 5 – DORD: Data Order
	  *  Bit 4 – MSTR: Master/Slave Select
	  *  Bit 3 – CPOL: Clock Polarity
	  *  Bit 2 – CPHA: Clock Phase
	  *  Bits 1, 0 – SPR1, SPR0: SPI Clock Rate Select 1 and 0
	  */
	SET_BIT(SPCR, SPE); // Enabling the SPI Module
	CLR_BIT(SPCR, MSTR); // Enabling the Master / Slave Mode; I will choose Master
	CLR_BIT(SPCR, SPR1); // Choosing the SCK rate, Fosc / 4
	CLR_BIT(SPCR, SPR0); // So SPR1, SPR0 = '00'

	/* SPSR - SPI Status Register
	  *  Bit 7 – SPIF: SPI Interrupt Flag
	  *  Bit 6 – WCOL: Write COLlision Flag
	  *  Bit 5..1 – Res: Reserved Bits
	  *  Bit 0 – SPI2X: Double SPI Speed Bit
	  */
	CLR_BIT(SPSR, SPI2X); // Make SPI2X = '0' to support the Fosc / 4

}


// Responsible for the SPI to send & receive a byte
uint8 SPI_sendReceiveByte(uint8 data) {

	SPDR = data;

	while(BIT_IS_CLR(SPSR, SPIF)) {
		// Polling (Busy Wait)
		/* Waiting for the flag is set, it is set when data transmission
		 * flag is set, Master will set SS to low to generate clock on SCK pin
		 */
	}

	// after SPIF is set, then I return the data
	return SPDR;
}

void SPI_sendString(const uint8 *str) {
	uint8 i = 0;
	uint8 receivedData = 0;

	while (str[i] != '\0') {
		// receivedData contains the data from the other device
		receivedData = SPI_sendReceiveByte(str[i]);
		i++;
	}

}


void SPI_receiveString(uint8 *str) {
	uint8 i = 0;
	// Receives and stores the first byte
	str[i] = SPI_sendReceiveByte(SPI_DEF_DATA_VAL);


	while (str[i] != '#') {
		i++; // why the incrementer above?
		str[i] = SPI_sendReceiveByte(SPI_DEF_DATA_VAL);
	}

	str[i] = '\0'; // replacing the '#' with '\0'

}
