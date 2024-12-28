/*
 * PowerCoupleRuler.cpp
 * Author : Ramtin B. M.
 */

// Libraries de base
#include "include_generic.h"

// Libraries de l'equipe
#include "UART.h"
#include "Buttons.h"
#include "Display.h"
#include "Encoder.h"
#include "SD_Card.h"

void mainSetup() {
    // Initialize UART communication
    UARTInit(); // Baud rate initialized at 19200
    /* TODO: SPI initialization */
    
    // Initialize libraries
    displayInit();
    // sdCardInit();
    buttonInit();
    encoderInit();
    
    // Enable global interrupts (for button and encoder)
    sei();
}

void mainLoop() {
    // Print the encoder position
    static int lastPosition = 0;
    int currentPosition = encoderGetTicks();
    if (lastPosition != currentPosition) {
        transmitByte(currentPosition);
        lastPosition = currentPosition;
    }

    // Add a delay to prevent spamming
    _delay_ms(100);
}

// Do not touch
int main(void) {
    mainSetup();
    while (1) {
        mainLoop();
    }
} 
