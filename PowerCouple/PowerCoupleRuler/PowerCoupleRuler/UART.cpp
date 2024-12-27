/*
 * UART.cpp
 * Author: Miriam C
 */ 

#include "UART.h"

void UARTInit(void) {
	// see table 24.9 of datasheet
	// baud rate set to 19200 (required by TM1652)
	// double speed mode abd F_CPU = 16MHz
	
	UBRR0H = 0;
	UBRR0L = 0x67; // 103
	UCSR0A |= (1 << U2X0);						//Enable double speed mode ; UCSR0A &= ~(1 << U2X0) to disable
	UCSR0B |= (1 << TXEN0) | (1 << RXEN0);		//Enable USART transmitter/receiver 
	
	// Bit structure :
	// start bit handled automatically
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);	//8 data bits
	UCSR0C |= (1 << UPM01);  // Even
	//UCSR0C &= ~(1 << USBS0);  // 1 stop bit (clear USBS0)
	
}

void transmitByte(uint8_t data) {
	loop_until_bit_is_set(UCSR0A, UDRE0); /* Attendre que le buffer de transmission soit vide */
	UDR0 = data;                      /* envoyer la donnée */
}

void USART0_SendBytes(uint8_t *data, uint8_t length) {
	for (uint16_t i = 0; i < length; i++) {
		// Attendre que le buffer de transmission soit vide 
		while (!(UCSR0A & (1 << UDRE0)));
		
		// Envoyer le byte
		UDR0 = data[i];
	}
}


uint8_t receiveByte(void){
    loop_until_bit_is_set(UCSR0A, RXC0);		//Attendre que le buffer de reception soit vide 
	return UDR0;                                //retourner la donnée
}
