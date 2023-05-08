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

	/* ADMUX Register Bits Description:
	 * 7:6, REFS1:0 = 01 to choose AVCC = 5v as reference voltage
	 * 5, ADLAR   = 0 right adjusted
	 * 4:0, MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	#if (ADC_REF_MODE == 0)
		CLR_BIT(ADMUX, REFS1);
		CLR_BIT(ADMUX, REFS0);
	#elif (ADC_REF_MODE == 1)
		CLR_BIT(ADMUX, REFS1);
		SET_BIT(ADMUX, REFS0);
	#elif (ADC_REF_MODE == 3)
		SET_BIT(ADMUX, REFS1);
		SET_BIT(ADMUX, REFS0);
	#endif

	CLR_BIT(ADMUX, ADLAR);

	CLR_BIT(ADMUX, MUX4);
	CLR_BIT(ADMUX, MUX3);
	CLR_BIT(ADMUX, MUX2);
	CLR_BIT(ADMUX, MUX1);
	CLR_BIT(ADMUX, MUX0);

	/* ADCSRA Register Bits Description:
	 * ADEN = 1 Enable ADC
	 * ADIE = 0 Disable ADC Interrupt
	 * ADATE = 0 Disable Auto Trigger
	 * ADPS2:0 = 111 to choose ADC_Clock = F_CPU/128 = 16Mhz/128 = 125Khz --> ADC must operate in range 50-200Khz
	 */
	SET_BIT(ADCSRA, ADEN);

	#if (ADC_INTERRUPT_MODE == 0)
		CLR_BIT(ADCSRA, ADIE);
	#elif (ADC_INTERRUPT_MODE == 1)
		SET_BIT(ADCSRA, ADIE);
	#endif

	CLR_BIT(ADCSRA, ADATE);
	SET_BIT(ADCSRA, ADPS2);
	SET_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS0);
}


// Reads the content written to the selected channel of the ADC
uint16 ADC_readChannel(uint8 channel_num) {

	// Insert Channel Number in ADMUX Procedure

	// Mask the Channel No. Input with max channel No.
	channel_num &= 0x07; // 0b0000 0111

	// Clears first 5 bits to zero
	ADMUX &= 0xE0; // 0b1110 0000

	// Insert Channel no. into ADMUX Register
	ADMUX = ADMUX | channel_num;

	// Starts ADC Conversion
	SET_BIT(ADCSRA, ADSC);

	// Busy wait (Polling) untill ADIF = 1
	while ( BIT_IS_CLR(ADCSRA, ADIF) );

	// sET FLAG BY 1 TO CLEAR
	SET_BIT(ADCSRA, ADIF);

	// Read Data
	return ADC;
}

