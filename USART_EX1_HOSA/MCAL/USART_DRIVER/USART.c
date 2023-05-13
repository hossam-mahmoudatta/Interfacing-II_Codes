 /******************************************************************************
 *
 * Module: ADC (Analog to Digital Converter)
 *
 * File Name: ADC.c
 *
 * Description: Source file for the AVR ADC Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#include "USART.h"

#include "avr/io.h" /* To use the IO Ports Registers */
#include <util/delay.h>


// Initializes and enables the USART Module to start functionality
void USART_Init(void) {
	// why uint32? to support the largest baud rate
	// to create a UART driver, I have 4 main parameters
	// Parity, Stop Bit, Data size, Baud Rate

	/* UDR: USART I/O Data Register
	  * BITS 7:0: RXB7:0, UDR (Read)
	  * BITS 7:0: TXB7:0, UDR (Write)
	  */
	// Why same bits, because they are mapped into the same place in mEMORY, but they are 2 different registers

	/* USART Control and Status Register A – UCSRA
	  *  Bit 7 – RXC: USART Receive Complete, when it receives data, the flag = 0
	  *  Bit 6 – TXC: USART Transmit Complete
	  *  Bit 5 – UDRE: USART Data Register Empty, when the register is empty, the flag will be set to '1'
	  *  Bit 4 – FE: Frame Error
	  *  Bit 3 – DOR: Data OverRun
	  *  Bit 2 – PE: Parity Error
	  *  Bit 1 – U2X: Double the USART Transmission Speed
	  *  Bit 0 – MPCM: Multi-processor Communication Mode
	  */

	/* USART Control and Status Register B – UCSRB
	  *  Bit 7 – RXCIE: RX Complete Interrupt Enable, how to make using interrupt?
	  *  Bit 6 – TXCIE: TX Complete Interrupt Enable
	  *  Bit 5 – UDRIE: USART Data Register Empty Interrupt Enable, when the register is empty, the flag will be set to '1'
	  *  Bit 4 – RXEN: Receiver Enable, set to 1
	  *  Bit 3 – TXEN: Transmitter Enable, set to 1
	  *  Bit 2 – UCSZ2: Character Size, it controls the data size of the data frame
	  *  Bit 1 – RXB8: Receive Data Bit 8, Enables the ninth bit of data, but remember that the UDR is 8 bits
	  *  Bit 0 – TXB8: Transmit Data Bit 8, Enables the ninth bit of data, but remember that the UDR is 8 bits
	  */

	// USART Control and Status Register C – UCSRC
	// Bit 7 – URSEL: Register Select, i must set it to '1'
	// Bit 6 – UMSEL: USART Mode Select, '0' for Asynchronous
	// BIT 5:4: UPM1:0, Parity Mode, I will use it as disable parity, so '00'
	// BIT 3: TXEN, Trans Enable, set to 1
	// BIT 2:1: UCSZ1:0, Character Size, I will choose '011' to be 8 bits
	// BIT 0: UCPOL, clock polarity, chooses if I choose on rising or falling edge, but since
	// Im using asynchronous mode, so i dont need this bit


	// UBRRL & UBRRH, BaudRate Registers
	// From the datasheet, I need to calculate the UBBR by using this equation:
	// UBBR = ( ((Fcpu) / (8 * Baud)) - 1 )
	// When will this eqn be in -Ve? if the Fcpu is less than '1'
	// What does the -Ve UBBR mean? it means i can't use this baud rate @ this Fcpu
	// The Fcpu must be atleast 8 times larger than the Baud Rate!!!
	// So if my Fcpu = 16Mhz & Baud = 9600, then the UBBR = 207.

	// UBBRH = 0;
	// UBBRL = 207;
	// (0000) (1100 1111) 12 bits, (0000) is for UBBRH, (1100 1111) if for UBBRL
	// BITS 7: URSEL, If i want to use this register, i must set it to '1'
	// BIT 6: UMSEL, Mode Select, '0' for Asynchronous
	// BIT 5:4: UPM1:0, Parity Mode, I will use it as disable parity, so '00'
	// BIT 3: TXEN, Trans Enable, set to 1
	// BIT 2:1: UCSZ1:0, Character Size, I will choose '011' to be 8 bits
	// BIT 0: UCPOL, clock polarity, chooses if I choose on rising or falling edge, but since
	// Im using asynchronous mode, so i dont need this bit
	// All serial peripherals are very slow compared to the processor,
	// for ex. we will use the baudrate 9600, which is approx 9.6 KHz
	// while the processor is 16 MHz, so the risk is that while im looping on the data
	// the looping of the processor will eventually outrace the uart sending time,
	// so u might overwrite on nits inside the UART
	// so we must make polling functions and then set flags to know if i received or sent the data successfully on the uart

	// To initialize this Init Function, i need to:
	// Tweak the Frame
	// Set the baud rate


}


// Reads the content written to the selected channel of the ADC
uint16 ADC_readChannel(uint8 channel_num) {

	// Insert Channel Number in ADMUX Procedure

	// Clears first 5 bits to zero
	ADMUX &= 0xE0; // 0b1110 0000

	// Mask the Channel No. Input with max channel No.
	channel_num &= 0x07; // 0b0000 0111

	// Insert Channel no. into ADMUX Register
	ADMUX |= channel_num;

	// Starts ADC Conversion
	SET_BIT(ADCSRA, ADSC);

	// Busy wait (Polling) untill ADIF = 1
	while ( BIT_IS_CLR(ADCSRA, ADIF) );

	// sET FLAG BY 1 TO CLEAR
	SET_BIT(ADCSRA, ADIF);

	// Read Data
	return ADC;
}
