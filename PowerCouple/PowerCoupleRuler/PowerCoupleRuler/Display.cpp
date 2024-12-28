/*
 * Display.cpp
 * Author: Miriam C
 */ 
#include "Display.h"

uint8_t initData[LENGTH_INIT] = {CONTROL_MODE, LED_DUTY_CYCLE};
uint8_t group_mask[5] = {GR1_MASK, GR2_MASK, GR3_MASK, GR4_MASK, GR5_MASK};
uint8_t transmitData[LENGTH_DATA] = {CONTROL_ADDRESS,0,0,0,0,0}; // address of the group + data
uint8_t DP_position = 2;

uint8_t LEDnumber[10] = {LED_0, LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8, LED_9};

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
	_delay_ms(100);
}

//Transmission des donnees

}
void testdata(int position, int data) {
	/*// Ensure data is within the valid range
	if (data < 0 || data > 9) {
		return; // Or handle the invalid data case
	}

	// Reset transmitData to default or known values
	for (int i = 1; i < LENGTH_DATA; i++) {
		transmitData[i] = 0;  // Clear previous data
	}

	// Set LED data starting from index 1
	for (int i = 1; i < LENGTH_DATA; i++) {
		transmitData[i] = LEDnumber[data];
	}
	
*//*
	//uint8_t tempData[2] = {group_mask[position] | CONTROL_ADDRESS, LEDnumber[data]};
	uint8_t tempData[2] = {0x08, 0xFF};
	USART0_SendBytes(tempData, 2);
	_delay_ms(100);
	tempData[0] = 0x48;
	USART0_SendBytes(tempData, 2);
	_delay_ms(100);
	tempData[0] = 0xC8;
	USART0_SendBytes(tempData, 2);
	_delay_ms(100);
	
	tempData[0] = 0x88;
	USART0_SendBytes(tempData, 2);
	_delay_ms(100);
						
	 tempData[0] = 0x28;
	 tempData[1] = 0xFB;
	// Send the data over USART
	USART0_SendBytes(tempData, 2);
	_delay_ms(100);*/

	// Ensure the data is within the valid range
	if (data < 0 || data > 9) {
		return; // Handle invalid data case
	}

	// Reset the data array for all digits to 0xFF (turn off all digits initially)
	for (int i = 0; i < LENGTH_DATA; i++) {
		transmitData[i] = 0xFF;  // Turn off all digits initially
	}

	// Set the data for the specific position
	transmitData[position] = LEDnumber[data];  // Set the digit at the specified position

	// Send the data to the TM1652
	uint8_t tempData[2];
	for (int i = 0; i < LENGTH_DATA; i++) {
		// Control byte to select the current digit (0xC0 for first digit, etc.)
		tempData[0] = 0xC0 + i;  // Modify this based on your address scheme
		tempData[1] = transmitData[i];  // Send the corresponding data for the digit

		// Send the data to the TM1652
		USART0_SendBytes(tempData, 2);
		_delay_ms(100);  // Delay to allow the TM1652 to update the display
}
}

void displayReset(){
	//Reset la position du point
	for (int i = 1; i < LENGTH_DATA; i++) {
		transmitData[i] = 0;  // Clear previous data
	}
	_delay_ms(10);
	DP_position = 2;
	
	//Pose 0 a chaque afficheur 
	for (int i = 1 ; i<=5 ; i++) transmitData[i] = LED_0;
	//Ajoute le point a la position voulue
	transmitData[DP_position] &= ~DP_MASK;
	
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



	