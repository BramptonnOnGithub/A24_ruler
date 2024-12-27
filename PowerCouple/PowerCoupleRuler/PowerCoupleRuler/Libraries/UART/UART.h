/*
 * UART.h
 * Author: Miriam C
 */ 

#include "include_generic.h"

void UARTInit();

void transmitByte(uint8_t data);

uint8_t receiveByte(void);