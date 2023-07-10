/******************************************************************************
 *
 * Application Comments and Code Trials
 *
 * File Name: Comments.c
 *
 * Description: File for comments and code samples for the HMI ECU in the final project
 *
 * Author: Hossam Mahmoud
 *
 *******************************************************************************/




/*******************************************************************************
 *                            			1st Implementation for the keypad entry                                  *
 *******************************************************************************/
/*
for (int i = 0 ; i < passLength ; i++) {
	uint8 KEYPAD_Value = 100;
	KEYPAD_Value =  KEYPAD_getPressedKey();
	_delay_ms(50);
	password[i] = KEYPAD_Value;
	if (i >= passLength) {
		i = 0;
	}
	else if (i < passLength) {
		if((KEYPAD_Value >= 0) && (KEYPAD_Value <= 9)) {
			LCD_moveCursor(1, i);
			LCD_intgerToString(KEYPAD_Value);
		}
		//i++;
	}
}


********************************************************************************
	// Code for getting keypad input and saving it in an uint8 array of size password length.
	LCD_moveCursor(0, 0);
	LCD_displayString("Enter Password: ");
	LCD_moveCursor(1, 0);
	LCD_displayString("-----");
	for (int i = 0 ; i < passLength ; i++) {
		uint8 KEYPAD_Value = 100;
		KEYPAD_Value =  KEYPAD_getPressedKey();
		_delay_ms(50);
		password[i] = KEYPAD_Value;

		if((KEYPAD_Value >= 0) && (KEYPAD_Value <= 9)) {
			LCD_moveCursor(1, i);
			LCD_displayCharacter('*');
//			LCD_intgerToString(KEYPAD_Value);
		}
	}

********************************************************************************
	// Displays the password saved in the array to check if keypad inputted correctly
	// This is a test code sample
	LCD_clearScreen();
	for (int i = 0 ; i < passLength ; i++) {
		LCD_moveCursor(0, 0);
		LCD_displayString("P1: ");
		LCD_moveCursor(0, 4 + i);
		LCD_intgerToString(password1[i]);

		LCD_moveCursor(1, 0);
		LCD_displayString("P2: ");
		LCD_moveCursor(1, 4 + i);
		LCD_intgerToString(passwordVerification[i]);
	}



*/
