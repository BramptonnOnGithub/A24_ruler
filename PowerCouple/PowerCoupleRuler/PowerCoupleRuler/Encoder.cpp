/*
 * Encoder.cpp
 * Author: faryc
 */ 
#include "Encoder.h"
#define RADIUS 13.5
#define PI 3.141592653589793
#define RESOLUTION 24

volatile int encoderPosition = 0; // Tracks encoder position
volatile int lastState = 0;       // Previous state of encoder pins
float circumference = (2 * PI * RADIUS) / RESOLUTION;
int direction = 0;                // 1 -> forward, 2 -> backward
int mode = 1; //1-> additive, 2->subtractive

void encoderInit() {
    // Configure pins as input
    DDRB &= ~((1 << PB0) | (1 << PB1));

    // Enable pull-ups
    PORTB |= (1 << PB0) | (1 << PB1);

    // Enable interrupt PCINT0..7
    PCICR |= (1 << PCIE0); 
    PCMSK0 |= (1 << PCINT0) | (1 << PCINT1); // Enable interrupts for PB0 and PB1

    // Setup initial state of encoder pins
    lastState = PINB & ((1 << PB0) | (1 << PB1));
}

//Interrupt sur PORTB (encodeur)
ISR(PCINT0_vect) {
    int currentState = PINB & ((1 << PB0) | (1 << PB1));

    // Decode quadrature encoder
    if ((lastState == (1 << PB0) && currentState == (1 << PB1)) || 
        (lastState == (1 << PB1) && currentState == 0) || 
        (lastState == 0 && currentState == (1 << PB0)) || 
        (lastState == ((1 << PB0) | (1 << PB1)) && currentState == (1 << PB1))) {
        encoderPosition++;
        direction = 1; // Forward
    } else if ((lastState == (1 << PB1) && currentState == (1 << PB0)) || 
               (lastState == (1 << PB0) && currentState == 0) || 
               (lastState == 0 && currentState == (1 << PB1)) || 
               (lastState == ((1 << PB0) | (1 << PB1)) && currentState == (1 << PB0))) {
		if (mode == 2) encoderPosition--;
		else encoderPosition++;
        direction = 2; // Backward
    }

    lastState = currentState; // Update state
}

float encoderGetDistance() {
    return (encoderPosition * circumference);
}

void encoderReset() {
    encoderPosition = 0;
}

int encoderGetTicks() {
    return encoderPosition;
}

int encoderGetDirection() {
    return direction; // 1 -> forward, 2 -> backward
}
