/*
 * Display.h
 * Author: Miriam C
 */ 
#include "include_generic.h"
#include "UART.h"

#define CONTROL_MODE		0x18 //display control command
#define LED_DUTY_CYCLE		0x08 //about 50%

#define CONTROL_ADDRESS		0x08 //display address command

// Define data sent for each number to display
#define LED_0	0x3F
#define LED_1	0x06
#define LED_2	0x5B
#define LED_3	0x4F
#define LED_4	0x66
#define LED_5	0x6D
#define LED_6	0x7D
#define LED_7	0x07
#define LED_8	0x7F
#define LED_9	0x6F
#define DP_MASK 0x80

#define LENGTH_INIT 2
#define LENGTH_DATA 6

void displayInit();

void displayData(float data);

// sets all of the 7 segments to 0
// precision at 00.000
void displayReset();

void displayIncrement();

void displayDecrement();

