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

#include "ADC.h"

#include "avr/io.h" /* To use the IO Ports Registers */
#include <util/delay.h>


// Initializes and enables the ADC Module to start functionality
void ADC_Init(void) {
	// Sets REFS1:0 to '01'
	CLR_BIT(ADMUX, ADMUX_REFS1);
	SET_BIT(ADMUX, ADMUX_REFS0);

	// Sets MUX4:0 to 0 for Channel 0 selection
	CLR_BIT(ADMUX, ADMUX_MUX4);
	CLR_BIT(ADMUX, ADMUX_MUX3);
	CLR_BIT(ADMUX, ADMUX_MUX2);
	CLR_BIT(ADMUX, ADMUX_MUX1);
	CLR_BIT(ADMUX, ADMUX_MUX0);

	// Enables ADC
	SET_BIT(ADCSRA, ADCSRA_ADEN);

	// Disables ADC Interrupt
	CLR_BIT(ADCSRA, ADCSRA_ADIE);

	// Choose prescaler 128



}


 // Reads the content written to the selected channel of the ADC
uint16 ADC_readChannel(uint8 channel_num);

