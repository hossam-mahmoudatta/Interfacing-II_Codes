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
//#include <util/delay.h>
#include <math.h>


/*******************************************************************************
 *                              					Module Implementation                           					  	  *
 *******************************************************************************/

void Timer0_Init(const Timer_ConfigType* TIMER0_ConfigPtr) {
	TCCR0 = 0x00;
	TCNT0 = 0x00;

	switch (TIMER0_ConfigPtr -> prescaler) {
		case	TIMER_PRESCALER_1024:
			TCCR0 |= (1 << CS00) | (1 << CS02);
		break;
		case	TIMER_PRESCALER_256:
			TCCR0 |= (1 << CS02);
		break;
		case	TIMER_PRESCALER_64:
			TCCR0 |= (1 << CS00) | (1 << CS01);
		break;
		case	TIMER_PRESCALER_8:
			TCCR0 |= (1 << CS01);
		break;
		case	TIMER_PRESCALER_1:
			TCCR0 |= (1 << CS00);
		break;
		default:
			TCCR0 |= (1 << CS00) | (1 << CS02);
		break;
	}

	switch (TIMER0_ConfigPtr -> mode) {
		case	TIMER_NORMAL_MODE:
			TCCR0 |= (1 << FOC0);
			#if (INTERRUPT_MODE == INTERRUPT_ENABLE)
				SET_BIT(TIMSK, TOIE0);
				SET_BIT(SREG, 7); // Bit 7 – i bit: Global Interrupt Enable
			#elif (INTERRUPT_MODE == INTERRUPT_DISABLE)
				CLR_BIT(TIMSK, TOIE0);
			#endif
		break;
		case	TIMER_COMPARE_MODE:
			TCCR0 |= (1 << FOC0) | (1 << WGM01);
			#if (INTERRUPT_MODE == INTERRUPT_ENABLE)
				SET_BIT(TIMSK, OCIE0);
				SET_BIT(SREG, 7); // Bit 7 – i bit: Global Interrupt Enable
			#elif (INTERRUPT_MODE == INTERRUPT_DISABLE)
				CLR_BIT(TIMSK, OCIE0);
			#endif

			#if (CTC_MODE == CTC_TOGGLE)
				TCCR0 |= (1 << COM00);
			#elif (CTC_MODE == CTC_CLEAR)
				TCCR0 |= (1 << COM01);
			#elif (CTC_MODE == CTC_SET)
				TCCR0 |= (1 << COM00) | (1 << COM01);
			#endif
		break;
		case	TIMER_FASTPWM_MODE:
			TCCR0 |= (1 << WGM00) | (1 << WGM01);

			#if (FASTPWM_MODE == FASTPWM_NOINVERT)
				TCCR0 |= (1 << COM01);
			#elif (FASTPWM_MODE == FASTPWM_INVERT)
				TCCR0 |= (1 << COM00) | (1 << COM01);
			#endif
		break;
		default:
			TCCR0 |= (1 << FOC0);
			#if (INTERRUPT_MODE == INTERRUPT_ENABLE)
				SET_BIT(TIMSK, TOIE0);
				SET_BIT(SREG, 7); // Bit 7 – i bit: Global Interrupt Enable
			#elif (INTERRUPT_MODE == INTERRUPT_DISABLE)
				CLR_BIT(TIMSK, TOIE0);
			#endif
		break;
	}
}


void Timer0_deInit(void) {
	TCCR0 = 0x00;
	TCNT0 = 0x00;
	OCR0   = 0x00;
}

void Timer1_Init(const Timer_ConfigType* TIMER1_ConfigPtr) {
	TCCR1A = 0x00;
	TCCR1B = 0x00;
	TCNT1 = 0x00;

	switch (TIMER1_ConfigPtr -> prescaler) {
		case	TIMER_PRESCALER_1024:
			TCCR1B |= (1 << CS10) | (1 << CS12);
		break;
		case	TIMER_PRESCALER_256:
			TCCR1B |= (1 << CS12);
		break;
		case	TIMER_PRESCALER_64:
			TCCR1B |= (1 << CS10) | (1 << CS11);
		break;
		case	TIMER_PRESCALER_8:
			TCCR1B |= (1 << CS11);
		break;
		case	TIMER_PRESCALER_1:
			TCCR1B |= (1 << CS10);
		break;
		default:
			TCCR1B |= (1 << CS10) | (1 << CS12);
		break;
	}

	switch (TIMER1_ConfigPtr -> mode) {
		case	TIMER_NORMAL_MODE:
			TCCR1A |= (1 << FOC1A) | (1 << FOC1B);
		break;
		case	TIMER_COMPARE_MODE:
			TCCR1A |= (1 << FOC1A) | (1 << FOC1B) | (1 << WGM12);
			#if (CTC_MODE == CTC_TOGGLE)
				TCCR1A |= (1 << COM1A0) | (1 << COM1B0);
			#elif (CTC_MODE == CTC_CLEAR)
				TCCR1A |= (1 << COM1A1) | (1 << COM1B1);
			#elif (CTC_MODE == CTC_SET)
				TCCR1A |= (1 << COM1A0) | (1 << COM1B0) | (1 << COM1A1) | (1 << COM1B1);
			#endif
		break;
		case	TIMER_FASTPWM_MODE:
			TCCR1A |= (1 << WGM10) | (1 << WGM11);
			TCCR1B |= (1 << WGM12) | (1 << WGM13);
			#if (FASTPWM_MODE == FASTPWM_NOINVERT)
				TCCR1A |= (1 << COM1A1) | (1 << COM1B1);
			#elif (FASTPWM_MODE == FASTPWM_INVERT)
				TCCR1A |= (1 << COM1A0) | (1 << COM1B0) | (1 << COM1A1) | (1 << COM1B1);
			#endif
		break;
		default:
			TCCR1A |= (1 << FOC1A) | (1 << FOC1B);
		break;
	}
}

void Timer1_deInit(void) {
	TCCR1A	= 0x00;
	TCCR1B	= 0x00;
	TCNT1		= 0x00;
	OCR1A  	= 0x00;
	OCR1B   	= 0x00;
}


void Timer2_Init(const Timer_ConfigType* TIMER2_ConfigPtr) {
	TCCR2 = 0x00;
	TCNT2 = 0x00;

	switch (TIMER2_ConfigPtr -> prescaler) {
		case	TIMER_PRESCALER_1024:
			TCCR2 |= (1 << CS20) | (1 << CS22);
		break;
		case	TIMER_PRESCALER_256:
			TCCR2 |= (1 << CS22);
		break;
		case	TIMER_PRESCALER_64:
			TCCR2 |= (1 << CS20) | (1 << CS21);
		break;
		case	TIMER_PRESCALER_8:
			TCCR2 |= (1 << CS21);
		break;
		case	TIMER_PRESCALER_1:
			TCCR2 |= (1 << CS20);
		break;
		default:
			TCCR2 |= (1 << CS20) | (1 << CS22);
		break;
	}

	switch (TIMER2_ConfigPtr -> mode) {
		case	TIMER_NORMAL_MODE:
			TCCR2 |= (1 << FOC2);
			#if (INTERRUPT_MODE == INTERRUPT_ENABLE)
				SET_BIT(TIMSK, TOIE2);
				SET_BIT(SREG, 7); // Bit 7 – i bit: Global Interrupt Enable
			#elif (INTERRUPT_MODE == INTERRUPT_DISABLE)
				CLR_BIT(TIMSK, TOIE2);
			#endif
		break;
		case	TIMER_COMPARE_MODE:
			TCCR2 |= (1 << FOC2) | (1 << WGM21);
			#if (INTERRUPT_MODE == INTERRUPT_ENABLE)
				SET_BIT(TIMSK, OCIE2);
				SET_BIT(SREG, 7); // Bit 7 – i bit: Global Interrupt Enable
			#elif (INTERRUPT_MODE == INTERRUPT_DISABLE)
				CLR_BIT(TIMSK, OCIE2);
			#endif

			#if (CTC_MODE == CTC_TOGGLE)
				TCCR2 |= (1 << COM20);
			#elif (CTC_MODE == CTC_CLEAR)
				TCCR2 |= (1 << COM21);
			#elif (CTC_MODE == CTC_SET)
				TCCR2 |= (1 << COM20) | (1 << COM21);
			#endif
		break;
		case	TIMER_FASTPWM_MODE:
			TCCR2 |= (1 << WGM20) | (1 << WGM21);
			#if (FASTPWM_MODE == FASTPWM_NOINVERT)
				TCCR2 |= (1 << COM21);
			#elif (FASTPWM_MODE == FASTPWM_INVERT)
				TCCR2 |= (1 << COM20) | (1 << COM21);
			#endif
		break;
		default:
			TCCR2 |= (1 << FOC2);
			#if (INTERRUPT_MODE == INTERRUPT_ENABLE)
				SET_BIT(TIMSK, TOIE2);
				SET_BIT(SREG, 7); // Bit 7 – i bit: Global Interrupt Enable
			#elif (INTERRUPT_MODE == INTERRUPT_DISABLE)
				CLR_BIT(TIMSK, TOIE2);
			#endif
		break;
	}
}

void Timer2_deInit(void) {
	TCCR2 = 0x00;
	TCNT2 = 0x00;
	OCR2   = 0x00;
}


void Timer0_normalDelaySec(float32 timeDelay) {
	// Sets the delay for Timer of your choice
	// Calculates the overflow amount
	// Sets TCNTx to 0
	// Sets overflow counter to 0
	// Compares overflow counter with overflow amount in a loop
	// Executes a busy wait function
	// Then clears the TIFR by setting it
	// Iterates Overflow Counter

	float32 	tickTime 					= 0;
	float32 	maxDelayTime 		= 0;
	float32 	overflowAmount 	= 0;
	uint8 		overFlowCounter 	= 0;

	tickTime = PRESCALER_VALUE / (float)F_CPU;
	maxDelayTime = tickTime * 256; 		// 2^n = 256
	overflowAmount = ceil((timeDelay) / (maxDelayTime));

	// Using the Timer Overflow Flag TOV
	//Timer0_Init();
	while (overFlowCounter < overflowAmount) {
		while (BIT_IS_CLR(TIFR, TOV0)) {
			// This function is a Busy Wait
		}
		overFlowCounter++;
		SET_BIT(TIFR, TOV0);
	}
	overFlowCounter = 0;
	//Timer0_Init();
	//TCCR0 = 0;

// Using the Timer Output Compare Flag OCF0
//	TCNT0 = 0x00;
//	while (overFlowCounter < overflowAmount) {
//		while (BIT_IS_CLR(TIFR, OCF0)) {
//			// This function is a Busy Wait
//		}
//		// Clear the overflow flag
//		CLR_BIT(TIFR, OCF0);
//		overFlowCounter++;
//	}
//	overFlowCounter = 0;
//	TCNT0 = 0x00;
}



void Timer1_normalDelaySec(float32 timeDelay) {
	// Sets the delay for Timer of your choice
	// Calculates the overflow amount
	// Sets TCNTx to 0
	// Sets overflow counter to 0
	// Compares overflow counter with overflow amount in a loop
	// Executes a busy wait function
	// Then clears the TIFR by setting it
	// Iterates Overflow Counter

	float32 	tickTime 					= 0;
	float32 	maxDelayTime 		= 0;
	float32 	overflowAmount 	= 0;
	uint8 		overFlowCounter 	= 0;

	tickTime = PRESCALER_VALUE / (float)F_CPU;
	maxDelayTime = tickTime * 256; 		// 2^n = 256
	overflowAmount = ceil((timeDelay) / (maxDelayTime));

	// Using the Timer Overflow Flag TOV
	//Timer1_Init();
	while (overFlowCounter < overflowAmount) {
		while (BIT_IS_CLR(TIFR, TOV1)) {
			// This function is a Busy Wait
		}
		overFlowCounter++;
		SET_BIT(TIFR, TOV1);
	}
	overFlowCounter = 0;
	//Timer1_Init();
	//TCCR0 = 0;
}










void Timer_setCTCMode_normalFreq(float freqKHZ, uint8 port_num, uint8 pin_num) {
	// CTC: Clear Timer on Compare Match
	// Our equation for the CTC Mode
	// Focn = F_CPU / (2N*(1 + OCRn))
	// For i.e: Focn = 2 KHz, what are my knowns?
	// Focn, FCPU, N,,, so i will calculate the OCRn
	// Thus solving my problem.

	GPIO_setupPinDirection(port_num, pin_num, PIN_OUTPUT);
	GPIO_writePin(port_num, pin_num, LOGIC_LOW);

	// Using the Timer CTC Mode
	TCNT0 	= 0;
	OCR0 		= 0;
	OCR0 		= ceil( (float32)F_CPU / (2 * PRESCALER_VALUE * freqKHZ * 1000) ) - 1;

	if (BIT_IS_SET(TIFR, OCF0)) {
		GPIO_togglePin(port_num, pin_num);
		SET_BIT(TIFR, OCF0);
	}


}


uint8 Timer_setCTCMode_interruptFreq(float freqKHZ) {
	// CTC: Clear Timer on Compare Match
	// Our equation for the CTC Mode
	// Focn = F_CPU / (2N*(1 + OCRn))
	// For i.e: Focn = 2 KHz, what are my knowns?
	// Focn, FCPU, N,,, so i will calculate the OCRn
	// Thus solving my problem.

	// Using the Timer CTC Mode
	//Timer0_Init();
	TCNT0 	= 0;
	OCR0 		= 0;
	OCR0 		= ceil( (float32)F_CPU / (2 * PRESCALER_VALUE * freqKHZ * 1000) ) - 1;

	return OCR0;
}


/*
void Timer_setCTCMode_interruptFreq(float freqKHZ, uint8 port_num, uint8 pin_num) {
	// CTC: Clear Timer on Compare Match
	// Our equation for the CTC Mode
	// Focn = F_CPU / (2N*(1 + OCRn))
	// For i.e: Focn = 2 KHz, what are my knowns?
	// Focn, FCPU, N,,, so i will calculate the OCRn
	// Thus solving my problem.

	GPIO_setupPinDirection(port_num, pin_num, PIN_OUTPUT);
	GPIO_writePin(port_num, pin_num, LOGIC_LOW);

#if (TIMER_SELECT == TIMER0)
	// Using the Timer CTC Mode
	Timer0_Init();
	TCNT0 	= 0;
	OCR0 		= 0;
	OCR0 		= ceil( (float32)F_CPU / (2 * PRESCALER_VALUE * freqKHZ * 1000) ) - 1;

	if (BIT_IS_SET(TIFR, OCF0)) {
		GPIO_togglePin(port_num, pin_num);
		SET_BIT(TIFR, OCF0);
	}


#elif (TIMER_SELECT == TIMER1)
	TCNT1 = 0x00;
	while (overFlowCounter < overflowAmount) {
		while (BIT_IS_CLR(TIFR, OCF1A)) {
			// This function is a Busy Wait
		}
		// Clear the overflow flag
		CLR_BIT(TIFR, OCF1A);
		overFlowCounter++;
	}
	overFlowCounter = 0;
	TCNT1 = 0x00;


#elif (TIMER_SELECT == TIMER2)
	TCNT2 = 0x00;
	while (overFlowCounter < overflowAmount) {
		while (BIT_IS_CLR(TIFR, OCF2)) {
			// This function is a Busy Wait
		}
		// Clear the overflow flag
		CLR_BIT(TIFR, OCF2);
		overFlowCounter++;
	}
	overFlowCounter = 0;
	TCNT2 = 0x00;
#endif
}
*/







/*
void Timer2_setMode(void) {
	switch(TIMER_MODE) {
		case NORMAL_MODE:
			Timer2_normalMode();
		break;

		case COMPARE_MODE:
			Timer2_compareMode();
		break;

		case PWM_MODE:
			Timer2_fastPWMMode();
		break;

		default:
			Timer2_normalMode();
		break;
	}
}*/
/*
void Timer2_normalMode(void) {
	SET_BIT(TCCR2, FOC2);
	CLR_BIT(TCCR2, WGM20);
	CLR_BIT(TCCR2, WGM21);
	CLR_BIT(TCCR2, COM21);
	CLR_BIT(TCCR2, COM20);
}

void Timer2_compareMode(void) {
	SET_BIT(TCCR2, FOC2);
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
}

void Timer2_fastPWMMode(void) {
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
}
*/
