/*
 * PowerCoupleRuler.cpp
 * Author : Ramtin B. M.
 */ 

// CLK speed de 1MHz
#define F_CPU 16000000UL

// Libraries de base
#include "include_generic.h"

// Libraries de l'equipe
#include "Buttons.h"
#include "Display.h"
#include "Encoder.h"
#include "SD_Card.h"

// Definition des bytes
typedef uint8_t byte;

void mainSetup(){
	// initialisation de la communication
	/*TODO : UART*/
	/*TODO : SPI*/
	
	// Initialisation des libraries
	displayInit();
	sdCardInit();
	buttonInit();
	encoderInit();
	
	// Activation des interrupt global (for button and encoder)
	sei();
	
	
}

//Interrupt sur PORTB (encodeur)
ISR(PCINT0_vect){
	
}

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


void mainLoop(){
	
}

// Do not touch
int main(void)
{
	mainSetup();
    while (1) 
    {
		mainLoop();
    }
}

