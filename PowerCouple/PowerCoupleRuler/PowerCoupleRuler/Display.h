/*
 * Display.h
 * Author: Miriam C
 */ 
#include "include_generic.h"
#include "UART.h"

#define CONTROL_MODE		0x18 //display control command
#define LED_DUTY_CYCLE		0xF8 //about 50%

#define CONTROL_ADDRESS		0x08 //display address command

//Define 7 segment group masks
#define GR1_MASK 0x00    //0x00
#define GR2_MASK 0x80    //0x80
#define GR3_MASK 0x40    //0x40
#define GR4_MASK 0xC0    //0xC0
#define GR5_MASK 0x20	 //0x20

// Define data sent for each number to display
#define LED_0    0xC0    //0x3F
#define LED_1    0xF9    //0x06
#define LED_2    0xA4    //0x5B
#define LED_3    0xB0    //0x4F
#define LED_4    0x99    //0x66
#define LED_5    0x92    //0x6D
#define LED_6    0x82    //0x7D
#define LED_7    0xF8    //0x07
#define LED_8    0x80    //0x7F
#define LED_9    0x90    //0x6F
#define DP_MASK  0x7F    //0x80



#define LENGTH_INIT 2
#define LENGTH_DATA 6

void displayInit();

void displayData(float data);

// sets all of the 7 segments to 0
// precision at 00.000
void displayReset();

void displayIncrement();

void displayDecrement();

void testdata(int position, int data);

