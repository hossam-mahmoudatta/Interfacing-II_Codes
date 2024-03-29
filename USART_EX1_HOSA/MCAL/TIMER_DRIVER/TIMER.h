 /******************************************************************************
 *
 * Module: Timer
 *
 * File Name: TIMER.h
 *
 * Description: Header file for the AVR Timer Driver
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

#define TIMER0 							0
#define TIMER1  							1
#define TIMER2   							2

#define TIMER_SELECT    			TIMER0

#define PRESCALER_1024 			1024
#define PRESCALER_256  			256
#define PRESCALER_64   			64
#define PRESCALER_8    				8
#define PRESCALER_0    				1
#define NO_CLOCK   					0

#define PRESCALER_VALUE    	PRESCALER_1024

#define NORMAL_MODE 				0
#define COMPARE_MODE  			2
#define PWM_MODE   					3

#define TIMER_MODE    				NORMAL_MODE

#define CTC_NORMAL					0	// OC0 is disconnected
#define CTC_TOGGLE  				1	// Toggle OC0
#define CTC_CLEAR   					2	// Clear OC0
#define CTC_SET   						3	// Set OC0

#define CTC_MODE    					CTC_TOGGLE

#define FASTPWM_NORMAL		0	// OC0 is disconnected
#define FASTPWM_NOINVERT 	2	// Non Inverting OC0
#define FASTPWM_INVERT   		3	// Inverting OC0

#define FASTPWM_MODE    		FASTPWM_NOINVERT



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

/* TCCR2 - Timer2 Control Register
  *  Bit 7 – FOC2: Force O/P Compare
  *  Bit 6, 3 - WGM21:0: Waveform Generation Mode
  *  Bit 5:4 – COM21:0: Compare Match O/P Mode
  *  Bit 2:0 – CS22:0: Clock Select
  */

/* TIMSK - Timer Interrupt Mask Register
  *  Bit 7 – OCIE2: Timer/Counter2 Output Compare Match Interrupt Enable
  *  Bit 6 – TOIE2: Timer/Counter2 Overflow Interrupt Enable
  *  Bit 5 – TICIE1: Timer/Counter1, Input Capture Interrupt Enable
  *  Bit 4 – OCIE1A: Timer/Counter1, Output Compare A Match Interrupt Enable
  *  Bit 3 – OCIE1B: Timer/Counter1, Output Compare B Match Interrupt Enable
  *  Bit 2 – TOIE1: Timer/Counter1, Overflow Interrupt Enable
  *  Bit 1 – OCIE0: Output Compare Match Interrupt Enable
  *  Bit 0 – TOIE0: Timer Overflow Interrupt Enable
  */

/* TIFR - Timer Interrupt Flag Register
  *  Bit 7 – OCF2: Output Compare Flag 2
  *  Bit 6 – TOV2: Timer/Counter2 Overflow Flag
  *  Bit 5 – ICF1: Timer/Counter1, Input Capture Flag
  *  Bit 4 – OCF1A: Timer/Counter1, Output Compare A Match Flag
  *  Bit 3 – OCF1B: Timer/Counter1, Output Compare B Match Flag
  *  Bit 2 – TOV1: Timer/Counter1, Overflow Flag
  *  Bit 1 – OCF0: Output Compare Flag 0
  *  Bit 0 – TOV0: Timer Overflow Flag
  */

/* TCNT0 - Timer Register0
  *  Bit 7..0 – TCNT0: Timer Register
  */

/* TCNT1 - Timer Register1
  *  Bit 15..8 – TCNT1H: Timer Register
  *  Bit 7..0 – TCNT1L: Timer Register
  */

/* TCNT2 - Timer2 Register
  *  Bit 7..0 – TCNT2: Timer Register2
  */

/* OCR0 - Output Compare Register0
  *	  Bit 7..0 – OCR0: Output Compare Register
  */

/* OCR1A - Output Compare Register1 A
  *  Bit 15..8 – OCR1AH: Output Compare Register1 A
  *  Bit 7..0 – OCR1AL: Output Compare Register1 A
  */

/* OCR1B - Output Compare Register1 B
  *  Bit 15..8 – OCR1BH: Output Compare Register1 B
  *  Bit 7..0 – OCR1BL: Output Compare Register1 B
  */

/* OCR2 - Output Compare Register2
  *	  Bit 7..0 – OCR2: Output Compare Register
  */

/* ICR1 - Input Capture Register1
  *  Bit 15..8 – ICR1H: Input Capture Register
  *  Bit 7..0 – ICR1L: Input Capture Register
  */

/* SFIOR - Special Function IO Register
  *	  Bit 1 – PSR2: Prescaler Reset Timer/Counter2
  *	  Bit 0 – PSR10: Prescaler Reset Timer1 and Timer0
  */



/*******************************************************************************
 *                              						Functions Prototypes                         					  *
 *******************************************************************************/

// Initializes and enables the SPI Module to start functionality
void Timer0_Init(void);
void Timer0_setPrescaler(void);
void Timer0_setMode(void);
void Timer0_normalMode(void);
void Timer0_compareMode(void);
void Timer0_fastPWMMode(void);

void Timer1_Init(void);
void Timer1_setPrescaler(void);
void Timer1_setMode(void);
void Timer1_normalMode(void);
void Timer1_compareMode(void);
void Timer1_fastPWMMode(void);

void Timer2_Init(void);
void Timer2_setPrescaler(void);
void Timer2_setMode(void);
void Timer2_normalMode(void);
void Timer2_compareMode(void);
void Timer2_fastPWMMode(void);

void Timer_setDelay(float32 timeDelay);

void Timer_Start(void);
void Timer_Stop(void);
void Timer_setInterrupt(void);
void Timer_clearInterrupt(void);
void Timer_getCounterValue(void);
void Timer_setOutputCompare(void);


#endif /* TIMER_H_ */
