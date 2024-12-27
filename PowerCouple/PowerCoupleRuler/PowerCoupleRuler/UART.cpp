/*
 * UART.cpp
 * Author: Miriam C
 */ 

void UARTInit(void) {
	// see table 24.9 of datasheet
	// baud rate set to 9600 with double speed mode abd F_CPU = 16MHz
	
	UBRR0H = 0;
	UBRR0L = 0xCF; // 207
	UCSR0A |= (1 << U2X0);						//Enable double speed mode ; UCSR0A &= ~(1 << U2X0) to disable
	UCSR0B |= (1 << TXEN0) | (1 << RXEN0);		//Enable USART transmitter/receiver 
	
	// Bit structure :
	// start bit handled automatically
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);	//8 data bits
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00) | (1 << UPM01);  // Even parity
	UCSR0C &= ~(1 << USBS0);  // 1 stop bit (clear USBS0)
	
}

void transmitByte(uint8_t data){
    loop_until_bit_is_set(UCSR0A, UDRE0);		//Attendre que le buffer de transmission soit vide 
	UDR0 = data;								//envoyer la donnée 
}

uint8_t receiveByte(void){
    loop_until_bit_is_set(UCSR0A, RXC0);		//Attendre que le buffer de reception soit vide 
	return UDR0;                                //retourner la donnée
}
