/*
 * Display.cpp
 * Author: Miriam C
 */ 
#include "Display.h"

uint8_t initData[LENGTH_INIT] = {CONTROL_MODE, LED_DUTY_CYCLE};
uint8_t group_mask[5] = {GR1_MASK, GR2_MASK, GR3_MASK, GR4_MASK, GR5_MASK};
uint8_t transmitData[LENGTH_DATA] = {CONTROL_ADDRESS,0}; // address of the group + data
uint8_t DP_position = 2;

void displayInit(){
	// Set the intensity of the display to the defined value
	USART0_SendBytes(initData, LENGTH_INIT);
	// set the display to 00.000
	displayReset(); 
}

uint8_t LEDnumber[10] = {LED_0, LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8, LED_9};

void displayData(float data){
	//Pose 0 a chaque afficheur
	for (int j = 0 ; j<10 ; j++){
	for (int i = 1 ; i<=5 ; i++)
	{
		transmitData[i] = LEDnumber[j];
		
	}
	USART0_SendBytes(transmitData, LENGTH_DATA);
	_delay_ms(1000);
}

//Transmission des donnees

}

void displayReset(){
	//Reset la position du point
	DP_position = 2;
	
	//Pose 0 a chaque afficheur 
	for (int i = 1 ; i<=5 ; i++) transmitData[i] = LED_8;
	//Ajoute le point a la position voulue
	transmitData[DP_position] |= DP_MASK;
	
	//Transmission des donnees
	USART0_SendBytes(transmitData, LENGTH_DATA);
}

void displayIncrement(){
	if(DP_position > 5) return;
	DP_position++;
}

void displayDecrement(){
	if(DP_position < 2) return;
	DP_position--;
}



	