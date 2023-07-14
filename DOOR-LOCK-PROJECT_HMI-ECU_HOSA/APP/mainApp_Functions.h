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

#ifndef MAINAPPFUNCTIONS_H_
#define MAINAPPFUNCTIONS_H_

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "../ECUAL/KEYPAD_DRIVER/KEYPAD.h" // I will need this driver for this ECU Driver
#include "../ECUAL/LCD_DRIVER/LCD.h" // I will need this driver for this ECU Driver


uint8* passwordEntry1(void);

uint8* passwordEntry2(void);

void displayPasswords(uint8* pass1, uint8* pass2);

void USART_sendPassword(uint8* pass);

//void USART_receiveCompleteCallback(uint8 receivedByte);


#endif /*MAINAPPFUNCTIONS_H_*/
