/*
 * Display.cpp
 * Author: Miriam C
 */ 
#include "Display.h"

uint8_t initData[2] = {CONTROL_MODE, LED_DUTY_CYCLE};
uint8_t transmitData[6]; // command + 5 data bytes
uint8_t DP_position = 2;

void displayInit(){
	// Set the intensity of the display to the defined value
	USART0_SendBytes(initData, LENGTH_INIT)
	// set the display to 00.000
	displayReset(); 
}

void displayData(float data){
	
}

void displayReset(){
	DP_position = 2;
	transmitData = {CONTROL_ADDRESS, LED_0, LED_0||DP_MASK, LED_0, LED_0, LED_0};
	USART0_SendBytes(transmitData, LENGTH_DATA);
}

void displayIncrement(){
	if(DP_position > 5) return;
	DP_position++;
	
}

void displayDecrement(){
	if(DP_position < 0) return;
	DP_position--;
}

	