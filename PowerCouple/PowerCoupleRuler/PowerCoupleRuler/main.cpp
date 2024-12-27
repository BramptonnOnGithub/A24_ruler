/*
 * PowerCoupleRuler.cpp
 * Author : Ramtin B. M.
 */ 

// CLK speed de 1MHz
#define F_CPU 1000000UL

// Libraries de base
#include <avr/io.h>
#include <util/delay.h>

// Libraries de l'equipe
#include "Buttons.h"
#include "Display.h"
#include "Encoder.h"
#include "SD_Card.h"

// Définition des bytes
typedef uint8_t byte;


void mainSetup(){
	// Initialisation des libraries
	
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

