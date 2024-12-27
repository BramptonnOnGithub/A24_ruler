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

void mainSetup(){
	// initialisation de la communication
	UARTInit(); // baud rate initialisee a 19200 
	/*TODO : SPI*/
	
	// Initialisation des libraries
	displayInit();
	sdCardInit();
	buttonInit();
	encoderInit();
	
	// Activation des interrupt global (for button and encoder)
	sei();
}




void mainLoop(){
	transmitByte(0x69);
	_delay_ms(100);
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

