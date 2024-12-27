/*
 * UART.cpp
 * Author: Miriam C
 */ 

void UARTInit(void) {
	UBRR0H = 0;
	UBRR0L = 0x0C;
	UCSR0A |= (1 << U2X0); //UCSR0A &= ~(1 << U2X0);
	UCSR0B |= (1 << TXEN0) | (1 << RXEN0); /* Enable USART transmitter/receiver */
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);   /* 8 data bits, 1 stop bit */
}

void transmitByte(uint8_t data){
    loop_until_bit_is_set(UCSR0A, UDRE0); /* Attendre que le buffer de transmission soit vide */
	UDR0 = data;                      /* envoyer la donnée */
}

uint8_t receiveByte(void){
    loop_until_bit_is_set(UCSR0A, RXC0);  /* Wait for empty transmit buffer */
	return UDR0;                                /* return register value */
}
