 /******************************************************************************
 *
 * Module: UART Module
 *
 * File Name: LCD.h
 *
 * Description: Header file for the AVR LCD Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#include "UART.h"

#include "avr/io.h" /* To use the IO Ports Registers */
#include <util/delay.h>

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void UART_Init(uint32 BAUD_RATE) {
	// why uint32? to support the largest baud rate
	// to create a UART driver, I have 4 main parameters
	// Parity, Stop Bit, Data size, Baud Rate

	// UDR: UART Data Register
	// BITS 7:0: RXB7:0, UDR (Read)
	// BITS 7:0: TXB7:0, UDR (Write)
	// Why same bits, because they are mapped into the same place in RAM, but they are 2 different registers

	// UCSRA:
	// BITS 7: RXC, USART Receive COmplete, when it receives data, the flag = 0
	// BIT 6: TXC, USART Transmit Complete,
	// BIT 5: UDRE, Data Register Empty, when the register is empty, the flag will be set to '1'
	// BIT 4: FE, Frame Error,
	// BIT 3: DOR, Data Overrun,
	// BIT 2: PE, Parity Error,
	// BIT 1: U2X, Double the Transmission Speed,


	// UCSRB:
	// BITS 7: RXCIE, USART COmplete Interrrupt Enable, how to make using interrupt?
	// BIT 6: TXCIE, USART Transmit Complete,
	// BIT 5: UDRIE, Data Register Empty, when the register is empty, the flag will be set to '1'
	// BIT 4: RXEN, Receive Enable, set to 1
	// BIT 3: TXEN, Trans Enable, set to 1
	// BIT 2: UCSZ2, Character Size, it controls the data size of the data frame
	// BIT 1: RXB8, Enables the ninth bit of data, but remember that the UDR is 8 bits,
	// BIT 0: TXB8, Enables the ninth bit of data, but remember that the UDR is 8 bits,

	//UCSRC:
	// BITS 7: URSEL, If i want to use this register, i must set it to '1'
	// BIT 6: UMSEL, Mode Select, '0' for Asynchronous
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

uint8 UART_receiveByte(void) {
	// UDR: UART Data Register
	// BITS 7:0: RXB7:0, UDR (Read)
	// BITS 7:0: TXB7:0, UDR (Write)
	// Why same bits, because they are mapped into the same place in RAM, but they are 2 different registers
	//
	while ( BIT_IS_CLEAR(UCSRA, RXC) );
	// This is waiting for the flag to be set to '0' to know that I received data

	// When reading
	return UDR;
	//



}

void UART_sendByte_Method1(uint8 data) {
	// Sends the data
	UDR = data;


	while ( BIT_IS_CLEAR(UCSRA, TXC) );

	// Clears the flag
	SET_BIT(UCSRA, TXC);




}


void UART_sendByte_Method2(uint8 data) {
	// Sends the data

	// WHEN THE UDRE flag is set to 1, the loop will exit
	while ( BIT_IS_CLEAR(UCSRA, UDRE) );

	// When the UDRE Flag is '1', data will be saved into UDR
	UDR = data;

	// This function is preferable, why?
	// Because this method, lets say i have two bytes to send, when i first call the function
	// i won't wait for the polling function, and then I will send the byte in UDR, and the function ends

	// Clears the flag
	SET_BIT(UCSRA, TXC);




}

void UART_Init(void) {
	// UDR: UART Data Register
	// BITS 7:0: RXB7:0, UDR (Read)
	// BITS 7:0: TXB7:0, UDR (Write)
	// Why same bits, because they are mapped into the same place in RAM, but they are 2 different registers
	//




}
void LCD_sendCommand(uint8 command) {
	// Set RS Pin to '0'
	GPIO_writePin(LCD_INIT_PORT, LCD_RS, LOGIC_LOW);
	_delay_ms(1);

	// Set Enable Pin to '1'
	GPIO_writePin(LCD_INIT_PORT, LCD_ENABLE, LOGIC_HIGH);
	_delay_ms(1);

	// Send command
	GPIO_writePort(LCD_DATA_PORT, command);
	_delay_ms(1);

	// Set Enable Pin to '0'
	GPIO_writePin(LCD_INIT_PORT, LCD_ENABLE, LOGIC_LOW);
	_delay_ms(1);
}


void LCD_displayCharacters(uint8 data) {
	// Set RS Pin to '1'
	GPIO_writePin(LCD_INIT_PORT, LCD_RS, LOGIC_HIGH);
	_delay_ms(1);

	// Set Enable Pin to '1'
	GPIO_writePin(LCD_INIT_PORT, LCD_ENABLE, LOGIC_HIGH);
	_delay_ms(1);

	// Send command
	GPIO_writePort(LCD_DATA_PORT, data);
	_delay_ms(1);

	// Set Enable Pin to '0'
	GPIO_writePin(LCD_INIT_PORT, LCD_ENABLE, LOGIC_LOW);
	_delay_ms(1);
}


void LCD_displayString(const char *str) {
	uint8 i = 0;
	while(str[i] != '\0') {
		LCD_displayCharacters(str[i]);
		i++;
	}
	/*
	for (int i = 0 ; i < strlen(str) ; i++) {
		LCD_displayCharacters(str[i]);
	}*/
}


void LCD_moveCursor(uint8 row, uint8 col) {

	uint8 LCD_MEMORY_ADDRESS;

	// Calculate the required address in the LCD DDRAM checking
	// The location of the cursor originally on which line
	switch(row) {
		case 0:
			LCD_MEMORY_ADDRESS = col;
				break;
		case 1:
			LCD_MEMORY_ADDRESS = col + 0x40;
				break;
		case 2:
			LCD_MEMORY_ADDRESS = col + 0x10;
				break;
		case 3:
			LCD_MEMORY_ADDRESS = col + 0x50;
				break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(LCD_MEMORY_ADDRESS | LCD_CURSOR_LOCATION);
}


void LCD_displayStringRowColumn(uint8 row, uint8 col, const char *Str) {
	// Go to to the required LCD position
	LCD_moveCursor(row, col);

	// Display the string from the cursor
	LCD_displayString(Str);
}

void LCD_intgerToString(int data) {
	// A string to hold the ASCII values
	char buffer[16];

	// Converts data to its ASCII
	itoa(data, buffer, 10);

	// Display string with the results in the buffer
	LCD_displayString(buffer);
}

void LCD_clearScreen(void) {
	// Clears the LCD Display
	LCD_sendCommand(LCD_CLEAR_DISPLAY);
}

