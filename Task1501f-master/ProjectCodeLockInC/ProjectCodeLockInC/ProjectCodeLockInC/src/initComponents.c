/*
 * initComponents.c
 *
 * Created: 2015-12-16 10:42:58
 *  Author: Daniel Petersén and Marcus Sandberg
 */ 

#include <asf.h>
#include "initComponents.h"

/* Sets which pins is going to be inputs and which is going to be outputs*/
void init()
{
	pinMode(PIN3, OUTPUT);
	pinMode(PIN4, OUTPUT);
	pinMode(PIN5, OUTPUT);
	pinMode(PIN6, OUTPUT);
	pinMode(PIN7, INPUT);
	pinMode(PIN8, INPUT);
	pinMode(PIN9, INPUT);
}

void pinMode(int pinNumber, mode_definition mode) 
{
	if (mode == OUTPUT) 
	{
		if (pinNumber == PIN3) 
		{
			ioport_set_pin_dir(PIO_PC28_IDX, GPIO_DIR_OUTPUT);
		}
		if (pinNumber == PIN4) 
		{
			ioport_set_pin_dir(PIO_PC26_IDX, GPIO_DIR_OUTPUT);
		}
		if (pinNumber == PIN5) 
		{
			ioport_set_pin_dir(PIO_PC25_IDX, GPIO_DIR_OUTPUT);
		}
		if (pinNumber == PIN6) 
		{
			ioport_set_pin_dir(PIO_PC24_IDX, GPIO_DIR_OUTPUT);
		}
	}
	else if (mode == INPUT) 
	{
		if (pinNumber == PIN8) 
		{
			ioport_set_pin_dir(PIO_PC22_IDX, GPIO_DIR_INPUT);
		}
		if (pinNumber == PIN9) 
		{
			ioport_set_pin_dir(PIO_PC21_IDX, GPIO_DIR_INPUT);
		}
	}
}

void digitalWrite(int pinNumber, int value) 
{
	if (value == HIGH) 
	{
		if (pinNumber == PIN3) 
		{
			ioport_set_pin_level(PIO_PC28_IDX, HIGH);
		}
		if (pinNumber == PIN4) 
		{
			ioport_set_pin_level(PIO_PC26_IDX, HIGH);
		}
		if (pinNumber == PIN5) 
		{
			ioport_set_pin_level(PIO_PC25_IDX, HIGH);
		}
		if (pinNumber == PIN6) 
		{
			ioport_set_pin_level(PIO_PC24_IDX, HIGH);
		}
	}
	if (value == LOW) 
	{
		if (pinNumber == PIN3) 
		{
			ioport_set_pin_level(PIO_PC28_IDX, LOW);
		}
		if (pinNumber == PIN4) 
		{
			ioport_set_pin_level(PIO_PC26_IDX, LOW);
		}
		if (pinNumber == PIN5) 
		{
			ioport_set_pin_level(PIO_PC25_IDX, LOW);
		}
		if (pinNumber == PIN6) 
		{
			ioport_set_pin_level(PIO_PC24_IDX, LOW);
		}
	}
}

int digitalRead(int pinNumber) 
{
	int pinValue; 
	if (pinNumber == PIN7) 
	{
		pinValue = ioport_get_pin_level(PIO_PC23_IDX);
	}
	if (pinNumber == PIN8) 
	{
		pinValue = ioport_get_pin_level(PIO_PC22_IDX);
	}
	if (pinNumber == PIN9) 
	{
		pinValue = ioport_get_pin_level(PIO_PC21_IDX);
	}
	return pinValue;
}

void testComponents() 
{
	pinMode(PIN3, OUTPUT);
	pinMode(PIN4, OUTPUT);
	pinMode(PIN5, OUTPUT);
	pinMode(PIN6, OUTPUT);
	pinMode(PIN7, INPUT);
	pinMode(PIN8, INPUT);
	pinMode(PIN9, INPUT);
	
	while (1) 
	{
		if (digitalRead(PIN7) == HIGH) 
		{
			digitalWrite(PIN4, HIGH);
			digitalWrite(PIN3, HIGH);
		}
		if (digitalRead(PIN8) == HIGH) 
		{
			digitalWrite(PIN5, HIGH);
		}
		if (digitalRead(PIN9) == HIGH) 
		{
			digitalWrite(PIN6, HIGH);
		}
	}
}
