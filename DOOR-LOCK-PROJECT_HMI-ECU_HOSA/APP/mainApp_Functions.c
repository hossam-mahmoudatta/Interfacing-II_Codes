/******************************************************************************
 *
 * Functions used in the main application
 *
 * File Name: mainApp_Functions.c
 *
 * Description: Functions used and code samples for the HMI ECU in the final project
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/

#include "mainApp_Functions.h"

#define ARRAY_SIZE 5

uint8* passwordEntry1 (void) {
	uint8 passLength = 5;
	uint8* passInput1 = (uint8*) malloc(passLength * sizeof(uint8));

	// Code for getting keypad input and saving it in an uint8 array of size password length.
	LCD_moveCursor(0, 0);
	LCD_displayString("1.Enter Pass:");
	LCD_moveCursor(1, 0);
	LCD_displayString("-----");
	for (int i = 0 ; i < passLength ; i++) {
		uint8 KEYPAD_Value = 100;
		KEYPAD_Value =  KEYPAD_getPressedKey();
		_delay_ms(50);
		passInput1[i] = KEYPAD_Value;

		if((KEYPAD_Value >= 0) && (KEYPAD_Value <= 9)) {
			LCD_moveCursor(1, i);
			LCD_displayCharacter('*');
//			LCD_intgerToString(KEYPAD_Value);
		}
	}
	return passInput1;
}

uint8* passwordEntry2 (void) {
	uint8 passLength = 5;
	uint8* passInput2 = (uint8*) malloc(passLength * sizeof(uint8));

	// Code for getting keypad input and saving it in an uint8 array of size password length.
	LCD_moveCursor(0, 0);
	LCD_displayString("1.Re-Enter Pass:");
	LCD_moveCursor(1, 0);
	LCD_displayString("-----");
	for (int i = 0 ; i < passLength ; i++) {
		uint8 KEYPAD_Value = 100;
		KEYPAD_Value =  KEYPAD_getPressedKey();
		_delay_ms(50);
		passInput2[i] = KEYPAD_Value;

		if((KEYPAD_Value >= 0) && (KEYPAD_Value <= 9)) {
			LCD_moveCursor(1, i);
			LCD_displayCharacter('*');
//			LCD_intgerToString(KEYPAD_Value);
		}
	}
	return passInput2;
}

void displayPasswords(uint8* pass1, uint8* pass2) {
	// Displays the password saved in the array to check if keypad inputted correctly
	// This is a test code sample
	uint8 passLength = 5;
	LCD_clearScreen();
	for (int i = 0 ; i < passLength ; i++) {
		LCD_moveCursor(0, 0);
		LCD_displayString("P1: ");
		LCD_moveCursor(0, 4 + i);
		LCD_intgerToString(pass1[i]);

		LCD_moveCursor(1, 0);
		LCD_displayString("P2: ");
		LCD_moveCursor(1, 4 + i);
		LCD_intgerToString(pass2[i]);
	}
}

void USART_sendPassword(uint8* pass) {
	char arraySize = sizeof(pass) / sizeof(pass[0]);
	for (int i = 0 ; i < arraySize ; i++) {
		USART_sendByte(pass[i]);
	}
}

/*
void USART_receiveCompleteCallback(uint8 receivedByte) {
	volatile uint8 dataReceivedCount = 0;
	volatile uint8 receivedData[ARRAY_SIZE];

	if (dataReceivedCount < ARRAY_SIZE) {
        receivedData[dataReceivedCount] = receivedByte;
        dataReceivedCount++;
    }
}
*/


