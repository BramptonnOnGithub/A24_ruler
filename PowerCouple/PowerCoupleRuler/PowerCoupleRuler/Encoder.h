/*
 * Encoder.h
 * Author: Miriam C
 */ 

#include "include_generic.h"
#define RADIUS 13.5
#define PI 3.141592653589793
#define RESOLUTION 24


void encoderInit();
float encoderGetDistance();
void encoderReset();
int encoderGetTicks();
int encoderGetDirection();