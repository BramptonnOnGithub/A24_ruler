/*
 * Buttons.cpp
 * Author: Miriam C
 */ 
#include "Buttons.h"

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

