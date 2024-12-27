/*
 * Buttons.h
 * Author: Miriam C
 */ 

#include "include_generic.h"

//initializes the interrupts on the button pins
void buttonInit();

//Button actions
void buttonReduce();
void buttonIncrement();
void buttonAddSub();
void buttonCalib();
void buttonReset();
void buttonSave();