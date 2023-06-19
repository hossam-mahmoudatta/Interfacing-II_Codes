 /******************************************************************************
 *
 * Module: SPI (Serial Peripheral Interface)
 *
 * File Name: SPI.h
 *
 * Description: Source file for the AVR SPI Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#include "SPI.h"

#include "avr/io.h" /* To use the IO Ports Registers */
#include <util/delay.h>


// Initializes and enables the Master mode for the SPI Module to start functionality
void SPI_initMaster(void) {
	/* Configure SPI Master Pins
	 *	SS (PB4)   	--> 	Output
	 *	MOSI (PB5) --> 	Output
	 *	MISO (PB6) --> 	Input
	 *	SCK (PB7) 	--> 	Output
	 */
	GPIO_setupPinDirection(PORT_B, SS, PIN_OUTPUT);
	GPIO_setupPinDirection(PORT_B, MOSI, PIN_OUTPUT);
	GPIO_setupPinDirection(PORT_B, MISO, PIN_INPUT);
	GPIO_setupPinDirection(PORT_B, SCK, PIN_OUTPUT);

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
	SET_BIT(SPCR, MSTR); // Enabling the Master / Slave Mode; I will choose Master
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


// Responsible for the USART to send a byte
void USART_sendByte(const uint8 data) {
	/* UCSRA - USART Control and Status Register A
	  *  Bit 6 – TXC: USART Transmit Complete
	  *  Bit 5 – UDRE: USART Data Register Empty
	  *
	  *  UDRE flag is set when the TX Buffer (UDR) is empty and ready
	  *  for transmitting a new byte waiting untill this flag is set to '1'
	  */
	while(BIT_IS_CLR(UCSRA,UDRE)) {
		// Polling (Busy Wait)
	}

	/*
	 * Put the required data in the UDR register and also clear the UDRE flag as
	 * the UDR register is not empty now
	 */
	UDR = data;

	/************************* Another Method *************************
	UDR = data;
	while( BIT_IS_CLR(UCSRA, TXC) ){

	} // Wait until the transmission is complete TXC = 1
	SET_BIT(UCSRA,TXC); // Clear the TXC flag
	// This is waiting for the flag to be set to '0' to know that I received data
	*******************************************************************/
}


// Responsible for the USART to receive a byte
uint8 USART_receiveByte(void) {
	/* UCSRA - USART Control and Status Register A
	  *  Bit 7 – RXC: USART Receive Complete, when it receives data, the flag = 0
	  */

	while ( BIT_IS_CLR(UCSRA, RXC) );
	// This is waiting for the flag to be set to '0' to know that I received data

	// When reading
	return UDR;
}


// Responsible for the USART to send an array of bytes, a string
void USART_sendString(const uint8 *str) {
	uint8 i = 0;
	while (str[i] != '\0') {
		USART_sendByte(str[i]);
		i++;
	}
}


// Responsible for the USART to receive an array of bytes, a string
void USART_receiveString(uint8 *str) {
	uint8 i = 0;
	str[i] = USART_receiveByte();

	while (str[i] != '#') {
		i++;
		str[i] = USART_receiveByte();
	}
	str[i] = '\0'; // replacing the '#' with '\0'
}


