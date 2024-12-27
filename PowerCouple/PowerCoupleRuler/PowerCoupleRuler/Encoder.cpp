/*
 * Encoder.cpp
 *  Author: faryc
 */ 
#include "Encoder.h"

volatile int encoderPosition = 0;
volatile int lastState = 0;

bool encoderInit(){
	//Configure pins as input
	DDRB &= ~(1 << PB0) & ~(1 << PB1);
	
	//Enable pull-ups
	PORTB |= (1 << PB0) | (1 << PB1);
	
	//Enable interrupt PCINT0..7
	PCICR |= (1 << PCIE0); 
	PCMSK0 |= (1 << PCINT0) | (1 << PCINT1); //Enables it for PB0 and PB1
	
	//Setup initial state of pins
	lastState = PINB & ((1 << PB0) | (1 << PB1));
	
}