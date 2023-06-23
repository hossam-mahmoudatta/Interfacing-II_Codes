 /******************************************************************************
 *
 * Module: Timer
 *
 * File Name: TIMER.c
 *
 * Description: Source file for the AVR Timer Driver
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

/*******************************************************************************
 *                              					 Application Libraries                                				  *
 *******************************************************************************/

#include "TIMER.h"

#include "avr/io.h" /* To use the IO Ports Registers */
#include <util/delay.h>


/*******************************************************************************
 *                              					Module Implementation                           					  *
 *******************************************************************************/

// Initializes and enables the Master mode for the TWI Module to start functionality
#if (TIMER_SELECT == TIMER0)
	void Timer0_Init(void) {
		switch(PRESCALER_VALUE) {
			case PRESCALER_1024:
				SET_BIT(TCCR0, CS00);
				CLR_BIT(TCCR0, CS01);
				SET_BIT(TCCR0, CS02);
			break;

			case PRESCALER_256:
				CLR_BIT(TCCR0, CS00);
				CLR_BIT(TCCR0, CS01);
				SET_BIT(TCCR0, CS02);
			break;

			case PRESCALER_64:
				SET_BIT(TCCR0, CS00);
				SET_BIT(TCCR0, CS01);
				CLR_BIT(TCCR0, CS02);
			break;

			case PRESCALER_8:
				CLR_BIT(TCCR0, CS00);
				SET_BIT(TCCR0, CS01);
				CLR_BIT(TCCR0, CS02);
			break;

			case PRESCALER_0:
				SET_BIT(TCCR0, CS00);
				CLR_BIT(TCCR0, CS01);
				CLR_BIT(TCCR0, CS02);
			break;

			case NO_CLOCK:
				CLR_BIT(TCCR0, CS00);
				CLR_BIT(TCCR0, CS01);
				CLR_BIT(TCCR0, CS02);
			break;

			default:
				SET_BIT(TCCR0, CS00);
				CLR_BIT(TCCR0, CS01);
				CLR_BIT(TCCR0, CS02);
			break;
		}

		switch(TIMER_MODE) {
			case NORMAL_MODE:
				CLR_BIT(TCCR0, FOC0);
				CLR_BIT(TCCR0, WGM00);
				CLR_BIT(TCCR0, WGM01);
				CLR_BIT(TCCR0, COM01);
				CLR_BIT(TCCR0, COM00);
			break;

			case COMPARE_MODE:
				CLR_BIT(TCCR0, FOC0);
				CLR_BIT(TCCR0, WGM00);
				SET_BIT(TCCR0, WGM01);
	#if (CTC_MODE == CTC_NORMAL)
				CLR_BIT(TCCR0, COM01);
				CLR_BIT(TCCR0, COM00);
	#elif (CTC_MODE == CTC_TOGGLE)
				CLR_BIT(TCCR0, COM01);
				SET_BIT(TCCR0, COM00);
	#elif (CTC_MODE == CTC_CLEAR)
				SET_BIT(TCCR0, COM01);
				CLR_BIT(TCCR0, COM00);
	#elif (CTC_MODE == CTC_SET)
				SET_BIT(TCCR0, COM01);
				SET_BIT(TCCR0, COM00);
	#endif
			break;

			case PWM_MODE:
				CLR_BIT(TCCR0, FOC0);
				SET_BIT(TCCR0, WGM00);
				SET_BIT(TCCR0, WGM01);
	#if (FASTPWM_MODE == FASTPWM_NORMAL)
				CLR_BIT(TCCR0, COM01);
				CLR_BIT(TCCR0, COM00);
	#elif (FASTPWM_MODE == FASTPWM_NOINVERT)
				SET_BIT(TCCR0, COM01);
				CLR_BIT(TCCR0, COM00);
	#elif (FASTPWM_MODE == FASTPWM_INVERT)
				SET_BIT(TCCR0, COM01);
				SET_BIT(TCCR0, COM00);
	#endif
			break;

			default:
				CLR_BIT(TCCR0, FOC0);
				CLR_BIT(TCCR0, WGM00);
				CLR_BIT(TCCR0, WGM01);
				CLR_BIT(TCCR0, COM01);
				CLR_BIT(TCCR0, COM00);
			break;
		}
	}

#elif (TIMER_SELECT == TIMER1)
	void Timer1_Init(void) {
		switch(PRESCALER_VALUE) {
			case PRESCALER_1024:
				SET_BIT(TCCR1B, CS10);
				CLR_BIT(TCCR1B, CS11);
				SET_BIT(TCCR1B, CS12);
			break;

			case PRESCALER_256:
				CLR_BIT(TCCR1B, CS10);
				CLR_BIT(TCCR1B, CS11);
				SET_BIT(TCCR1B, CS12);
			break;

			case PRESCALER_64:
				SET_BIT(TCCR1B, CS10);
				SET_BIT(TCCR1B, CS11);
				CLR_BIT(TCCR1B, CS12);
			break;

			case PRESCALER_8:
				CLR_BIT(TCCR1B, CS10);
				SET_BIT(TCCR1B, CS11);
				CLR_BIT(TCCR1B, CS12);
			break;

			case PRESCALER_0:
				SET_BIT(TCCR1B, CS10);
				CLR_BIT(TCCR1B, CS11);
				CLR_BIT(TCCR1B, CS12);
			break;

			case NO_CLOCK:
				CLR_BIT(TCCR1B, CS10);
				CLR_BIT(TCCR1B, CS11);
				CLR_BIT(TCCR1B, CS12);
			break;

			default:
				SET_BIT(TCCR1B, CS10);
				CLR_BIT(TCCR1B, CS11);
				CLR_BIT(TCCR1B, CS12);
			break;
		}

		switch(TIMER_MODE) {
			case NORMAL_MODE:
				CLR_BIT(TCCR1A, COM1A1);
				CLR_BIT(TCCR1A, COM1A0);
				CLR_BIT(TCCR1A, COM1B1);
				CLR_BIT(TCCR1A, COM1B0);
				CLR_BIT(TCCR1B, WGM13);
				CLR_BIT(TCCR1B, WGM12);
				CLR_BIT(TCCR1A, WGM11);
				CLR_BIT(TCCR1A, WGM10);
			break;

			case COMPARE_MODE:
				CLR_BIT(TCCR1B, WGM13);
				SET_BIT(TCCR1B, WGM12);
				CLR_BIT(TCCR1A, WGM11);
				CLR_BIT(TCCR1A, WGM10);
	#if (CTC_MODE == CTC_NORMAL)
				CLR_BIT(TCCR1A, COM1A1);
				CLR_BIT(TCCR1A, COM1A0);
				CLR_BIT(TCCR1A, COM1B1);
				CLR_BIT(TCCR1A, COM1B0);
	#elif (CTC_MODE == CTC_TOGGLE)
				CLR_BIT(TCCR1A, COM1A1);
				SET_BIT(TCCR1A, COM1A0);
				CLR_BIT(TCCR1A, COM1B1);
				SET_BIT(TCCR1A, COM1B0);
	#elif (CTC_MODE == CTC_CLEAR)
				SET_BIT(TCCR1A, COM1A1);
				CLR_BIT(TCCR1A, COM1A0);
				SET_BIT(TCCR1A, COM1B1);
				CLR_BIT(TCCR1A, COM1B0);
	#elif (CTC_MODE == CTC_SET)
				SET_BIT(TCCR1A, COM1A1);
				SET_BIT(TCCR1A, COM1A0);
				SET_BIT(TCCR1A, COM1B1);
				SET_BIT(TCCR1A, COM1B0);
	#endif
			break;

			case PWM_MODE:
				SET_BIT(TCCR1B, WGM13);
				SET_BIT(TCCR1B, WGM12);
				SET_BIT(TCCR1A, WGM11);
				SET_BIT(TCCR1A, WGM10);
	#if (FASTPWM_MODE == FASTPWM_NORMAL)
				CLR_BIT(TCCR1A, COM1A1);
				CLR_BIT(TCCR1A, COM1A0);
				CLR_BIT(TCCR1A, COM1B1);
				CLR_BIT(TCCR1A, COM1B0);
	#elif (FASTPWM_MODE == FASTPWM_NOINVERT)
				SET_BIT(TCCR1A, COM1A1);
				CLR_BIT(TCCR1A, COM1A0);
				SET_BIT(TCCR1A, COM1B1);
				CLR_BIT(TCCR1A, COM1B0);
	#elif (FASTPWM_MODE == FASTPWM_INVERT)
				SET_BIT(TCCR1A, COM1A1);
				SET_BIT(TCCR1A, COM1A0);
				SET_BIT(TCCR1A, COM1B1);
				SET_BIT(TCCR1A, COM1B0);
	#endif
			break;

			default:
				CLR_BIT(TCCR1A, COM1A1);
				CLR_BIT(TCCR1A, COM1A0);
				CLR_BIT(TCCR1A, COM1B1);
				CLR_BIT(TCCR1A, COM1B0);
				CLR_BIT(TCCR1B, WGM13);
				CLR_BIT(TCCR1B, WGM12);
				CLR_BIT(TCCR1A, WGM11);
				CLR_BIT(TCCR1A, WGM10);
			break;
		}
	}

#elif (TIMER_SELECT == TIMER2)
	void Timer2_Init(void) {
		switch(PRESCALER_VALUE) {
			case PRESCALER_1024:
				SET_BIT(TCCR2, CS20);
				CLR_BIT(TCCR2, CS21);
				SET_BIT(TCCR2, CS22);
			break;

			case PRESCALER_256:
				CLR_BIT(TCCR2, CS20);
				CLR_BIT(TCCR2, CS21);
				SET_BIT(TCCR2, CS22);
			break;

			case PRESCALER_64:
				SET_BIT(TCCR2, CS20);
				SET_BIT(TCCR2, CS21);
				CLR_BIT(TCCR2, CS22);
			break;

			case PRESCALER_8:
				CLR_BIT(TCCR2, CS20);
				SET_BIT(TCCR2, CS21);
				CLR_BIT(TCCR2, CS22);
			break;

			case PRESCALER_0:
				SET_BIT(TCCR2, CS20);
				CLR_BIT(TCCR2, CS21);
				CLR_BIT(TCCR2, CS22);
			break;

			case NO_CLOCK:
				CLR_BIT(TCCR2, CS20);
				CLR_BIT(TCCR2, CS21);
				CLR_BIT(TCCR2, CS22);
			break;

			default:
				SET_BIT(TCCR2, CS20);
				CLR_BIT(TCCR2, CS21);
				CLR_BIT(TCCR2, CS22);
			break;
		}

		switch(TIMER_MODE) {
			case NORMAL_MODE:
				CLR_BIT(TCCR2, WGM20);
				CLR_BIT(TCCR2, WGM21);
				CLR_BIT(TCCR2, COM21);
				CLR_BIT(TCCR2, COM20);
			break;

			case COMPARE_MODE:
				CLR_BIT(TCCR2, WGM20);
				SET_BIT(TCCR2, WGM21);
	#if (CTC_MODE == CTC_NORMAL)
				CLR_BIT(TCCR2, COM21);
				CLR_BIT(TCCR2, COM20);
	#elif (CTC_MODE == CTC_TOGGLE)
				CLR_BIT(TCCR2, COM21);
				SET_BIT(TCCR2, COM20);
	#elif (CTC_MODE == CTC_CLEAR)
				SET_BIT(TCCR2, COM21);
				CLR_BIT(TCCR2, COM20);
	#elif (CTC_MODE == CTC_SET)
				SET_BIT(TCCR2, COM21);
				SET_BIT(TCCR2, COM20);
	#endif
			break;

			case PWM_MODE:
				SET_BIT(TCCR2, WGM20);
				SET_BIT(TCCR2, WGM21);
	#if (FASTPWM_MODE == FASTPWM_NORMAL)
				CLR_BIT(TCCR2, COM21);
				CLR_BIT(TCCR2, COM20);
	#elif (FASTPWM_MODE == FASTPWM_NOINVERT)
				SET_BIT(TCCR2, COM21);
				CLR_BIT(TCCR2, COM20);
	#elif (FASTPWM_MODE == FASTPWM_INVERT)
				SET_BIT(TCCR2, COM21);
				SET_BIT(TCCR2, COM20);
	#endif
			break;

			default:
				CLR_BIT(TCCR2, WGM20);
				CLR_BIT(TCCR2, WGM21);
				CLR_BIT(TCCR2, COM21);
				CLR_BIT(TCCR2, COM20);
			break;
		}
	}
#endif


void Timer_setDelay(float32 timeDelay) {
	// Sets the delay for Timer of your choice
	// Calculates the overflow amount
	// Sets TCNTx to 0
	// Sets overflow counter to 0
	// Compares overflow counter with overflow amount in a loop
	// Executes a busy wait function
	// Then clears the TIFR by setting it
	// Iterates Overflow Counter

	float32 Tick_Time = 0;
	float32 MaxDelay_Time = 0;
	float32 overflowAmount = 0;
	uint8 overFlowCounter = 0;
	Tick_Time = PRESCALER_VALUE / (float)F_CPU;
	MaxDelay_Time = Tick_Time * 8;
	overflowAmount = floor((timeDelay) / (MaxDelay_Time));

#if (TIMER_SELECT == TIMER0)
	TCNT0 = 0x00;
	while (overFlowCounter < overflowAmount) {
		while ((TIFR & (1 << 0)) == 0) {
			// This function is a Busy Wait
		}

		// Clear the overflow flag
		TIFR |= (1 << 0);

		overFlowCounter++;
	}
	overFlowCounter = 0;
	TCNT0 = 0x00;

#elif (TIMER_SELECT == TIMER1)


#elif (TIMER_SELECT == TIMER2)


#endif


}

// Responsible for the SPI to send an array of bytes, a string
void I2C_start(void) {
	// Again enabling the I2C Module, Set the Start Condition, Clearing the TWINT Flag
	/* But why I'm not using the normal set bit technique?
	 * Because I don't want to keep old data, & I want the information always set by me
	 */
	TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWSTA);

	while(BIT_IS_CLR(TWCR, TWINT)) {
		// Busy Wait for TWINT set in TWCR Register
		// to ensure that start bit is send successfully
	}
}

// Responsible for the SPI to receive an array of bytes, a string
void I2C_stop(void) {
	TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWSTO);
}

// Responsible for the SPI to receive an array of bytes, a string
void I2C_writeByte(uint8 data) {
	TWCR = (1 << TWEN) | (1 << TWINT);
	TWDR = data;

	while(BIT_IS_CLR(TWCR, TWINT)) {
		// Busy Wait for TWINT set in TWCR Register
		// to ensure that data is sent successfully
	}
}

// Responsible for the SPI to receive an array of bytes, a string
uint8 I2C_readByteWithACK(void) {
	TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWEA);

	while(BIT_IS_CLR(TWCR, TWINT)) {
		// Busy Wait for TWINT set in TWCR Register
		// to ensure that data is sent successfully
	}
	return TWDR;
}

// Responsible for the SPI to receive an array of bytes, a string
uint8 I2C_readByteWithNACK(void) {
	TWCR = (1 << TWEN) | (1 << TWINT);

	while(BIT_IS_CLR(TWCR, TWINT)) {
		// Busy Wait for TWINT set in TWCR Register
		// to ensure that data is sent successfully
	}
	return TWDR;
}

// Responsible for the SPI to receive an array of bytes, a string
uint8 I2C_getStatus(void) {
	uint8 I2CStatus;
	I2CStatus = TWSR & I2C_INITIALSTATUS;
	return I2CStatus;
}
