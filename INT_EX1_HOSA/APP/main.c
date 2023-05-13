/*
 * main.c
 *
 *  Created on: May 2, 2023
 *      Author: Administrator
 */
#include <util/delay.h>
#include <avr/io.h>
#include "../ECUAL/LED_DRIVER/LED.h"
#include "../ECUAL/BUTTON_DRIVER/BUTTON.h"
#include "../MCAL/EXT_INTERRUPT_DRIVER/EXT_INTERRUPT.h"
//#include "../ECUAL/SEVEN-SEGMENT_DRIVER/SEGMENT.h"
//#include "../ECUAL/KEYPAD_DRIVER/KEYPAD.h"
//#include "../ECUAL/LCD_DRIVER/LCD.h"
//#include "../MCAL/ADC_DRIVER/ADC.h"

int main(void) {

	// Initializes LED Driver
	LED_Init(PORT_C, PIN_0);

	LED_On(PORT_C, PIN_0);

	// Initializes Button Driver
	BUTTON_Init(PORT_D, PIN_2);
	BUTTON_Read(PORT_D, PIN_2);

	// Initializes External Interrupt Driver
	EXT_INTERRUPT_Init();
	EXT_INTERRUPT_SetCallBack(EXT_INTERRUPT_INT0_ISR);

	while (1) {

	}
}

void EXT_INTERRUPT_INT0_ISR (void) {
	LED_Toggle(PORT_C, PIN_0);
}
/*
ISR (INT0_vect) {
	LED_Toggle(PORT_C, PIN_0);
}
*/
