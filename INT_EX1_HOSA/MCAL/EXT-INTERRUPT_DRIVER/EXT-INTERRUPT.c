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

#include "EXT-INTERRUPT.h"

#include "avr/io.h" /* To use the IO Ports Registers */
#include <util/delay.h>

// Initialize External Interrupt
void EXT_INTERRUPT0_Init(void) {

	// Setup Pin PD2 "INT0" to Input
	GPIO_setupPinDirection(PORT_D, PIN_2, PIN_INPUT);

	/* MCU Control Register – MCUCR  Register Bits Description:
	 * Bit 3, 2 – ISC11, ISC10: Interrupt Sense Control 1 Bit 1 and Bit 0
	 * Bit 1, 0 – ISC01, ISC00: Interrupt Sense Control 0 Bit 1 and Bit 0
	 */
	// Initializing the ISC0X bits
	#if (EXT_INTERRUPT_0_MODE == EXT_INTERRUPT_Low_Level)
		CLR_BIT(MCUCR, ISC01);
		CLR_BIT(MCUCR, ISC00);
	#elif (EXT_INTERRUPT_0_MODE == EXT_INTERRUPT_Logical_Change)
		CLR_BIT(MCUCR, ISC01);
		SET_BIT(MCUCR, ISC00);
	#elif (EXT_INTERRUPT_0_MODE == EXT_INTERRUPT_Falling_Edge)
		SET_BIT(MCUCR, ISC01);
		CLR_BIT(MCUCR, ISC00);
	#elif (EXT_INTERRUPT_0_MODE == EXT_INTERRUPT_Rising_Edge)
		SET_BIT(MCUCR, ISC01);
		SET_BIT(MCUCR, ISC00);
	#endif

	/* General Interrupt Control Register – GICR Register Bits Description:
	 * Bit 7 – INT1: External Interrupt Request 1 Enable
	 * Bit 6 – INT0: External Interrupt Request 0 Enable
	 * Bit 5 – INT2: External Interrupt Request 2 Enable
	 */
	// Enabling the INT0 bit inside GICR
	SET_BIT(GICR, INT0);

	/* Status Register – SREG Register Bits Description:
	 * Bit 7 – I: Global Interrupt Enable
	 */
	SET_BIT(SREG, SREG_I_BIT);


}
