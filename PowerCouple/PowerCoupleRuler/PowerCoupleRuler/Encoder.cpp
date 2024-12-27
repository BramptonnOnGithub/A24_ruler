/*
 * Encoder.cpp
 *  Author: faryc
 */ 
#include "Encoder.h"
#define RADIUS 13.5
#define PI 3.14
#define RESOLUTION 24

volatile int encoderPosition = 0;
volatile int lastState = 0;
float circumference = (2*PI*RADIUS) / RESOLUTION;
float distance;
int ticks;

bool encoderInit(){
	//Configure pins as input
	DDRB &= ~(1 << PB0) & ~(1 << PB1);
	
	//Enable pull-ups
	PORTB |= (1 << PB0) | (1 << PB1);
	
	//Enable interrupt PCINT0..7
	PCICR |= (1 << PCIE0); 
	PCMSK0 |= (1 << PCINT0) | (1 << PCINT1); //Enables it for PB0 and PB1
	
	//PE3 always high
	DDRE |= (1 << PE3);
	PORTE |= (1 << PE3);
	
	//PB2 always low
	DDRB |= (1 << PB2);
	PORTB &= ~(1 << PB2);
	
	//Setup initial state of pins
	lastState = PINB & ((1 << PB0) | (1 << PB1));
	
}

float encodergetPosition(){
	return circumference;
	
}

int encoderReset(){
	encoderPosition = 0
	return 1;
	
}

float encoderCalc(){
	distance = circumference * ticks;
	return distance;
	
}
