/*
 * Encoder.cpp
 * Author: faryc
 */ 
#include "Encoder.h"
#include "UART.h"

// Define pins
#define encoderPinA PB2  // Interrupt pin for Channel A
#define encoderPinB PC1  // Channel B (no interrupt)
#define highPin PE3      // Pin for High
#define lowPin PC0       // Pin for Low

// Variables to track position
volatile int encoderPosition = 0; // Position counter
volatile int lastEncoded = 0;     // Last encoder state
float circumference = (2 * PI * RADIUS) / RESOLUTION;
int direction = 0;                // 1 -> forward, 2 -> backward

void encoderInit() {
    // Configure high and low pins as output
    DDRE |= (1 << highPin);
    DDRC |= (1 << lowPin);

    // Set high pin high and low pin low
    PORTE |= (1 << highPin);
    PORTC &= ~(1 << lowPin);

    // Configure encoder pins as input
    DDRB &= ~(1 << encoderPinA);
    DDRC &= ~(1 << encoderPinB);

    // Enable pull-ups for encoder pins
    PORTB |= (1 << encoderPinA);
    PORTC |= (1 << encoderPinB);

    // Enable interrupt for encoderPinA only
    PCICR |= (1 << PCIE0); 
    PCMSK0 |= (1 << PCINT2); // Enable interrupt for PB2 (encoderPinA)

    // Setup initial state of encoder pins
    lastEncoded = ((PINB & (1 << encoderPinA)) >> encoderPinA) << 1 | ((PINC & (1 << encoderPinB)) >> encoderPinB);
}

// Interrupt for encoderPinA
ISR(PCINT1_vect) {
    updateEncoder();
    transmitByte(0xAA); // Debug message to confirm interrupt execution
}

void updateEncoder() {
    int MSB = (PINB & (1 << encoderPinA)) >> encoderPinA; // Most Significant Bit (Channel A)
    int LSB = (PINC & (1 << encoderPinB)) >> encoderPinB; // Least Significant Bit (Channel B)

    int encoded = (MSB << 1) | LSB; // Combine MSB and LSB
    int sum = (lastEncoded << 2) | encoded; // Combine last and current states

    // Update position based on state change
    if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderPosition++;
    if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderPosition--;

    lastEncoded = encoded; // Store current state
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
    return (encoderPosition >= 0) ? 1 : 2; // 1 -> forward, 2 -> backward
}
