/*
 * Buttons.cpp
 * Author: Miriam C
 */ 

#include "Buttons.h"

//Interrupt sur PORTD (boutons)
ISR(PCINT2_vect){
	// state watchdog is here to make sure the button presses only do the action once per press
	
	uint8_t currentState = PIND & 0xFC; // Read PD2 to PD7
	static uint8_t lastState = 0xFC;   // Store previous state
	uint8_t changedPins = currentState ^ lastState; // Detect changes
	
	// Identify newly pressed buttons
	uint8_t pressedPins = currentState & changedPins;
	
	// Check which buttons were pressed
	if (pressedPins & (1 << PD2)) {
		buttonSave(); // PD2 pressed ; save the data
	}
	if (pressedPins & (1 << PD3)) {
		buttonReset(); // PD3 pressed ; reset the data
	}
	if (pressedPins & (1 << PD4)) {
		buttonCalib(); // PD4 pressed
	}
	if (pressedPins & (1 << PD5)) {
		buttonAddSub(); // PD5 pressed
	}
	if (pressedPins & (1 << PD6)) {
		buttonIncrement(); // PD6 pressed
	}
	if (pressedPins & (1 << PD7)) {
		buttonReduce(); // PD7 pressed
	}

	lastState = currentState; // Update last state
}

void buttonInit(){
	//Configure pins PD2..7 as input
	DDRD &= ~((1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5) | (1 << PD6) | (1 << PD7));
	
	//Enable pull-ups
	PORTD |= (1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5) | (1 << PD6) | (1 << PD7);

	//Enable pin change interrupts on PCINT[18:23] (PD2 to PD7) on group PCINT2
	PCICR |= (1 << PCIE2);           
	PCMSK2 |= 0xFC;                  // (0xFC = 11111100) for PCINT[18:23]
}

void buttonReduce(){
	
}

void buttonIncrement(){
	
}

void buttonAddSub(){
	
}

void buttonCalib(){
	
}

void buttonReset(){
	
}

void buttonSave(){
	
}

