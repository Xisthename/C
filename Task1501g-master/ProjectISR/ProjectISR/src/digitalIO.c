/*
 * digitalIO.c
 *
 * Created: 2015-06-10 15:11:18
 *  Author: Ulrik
 */ 

#include <inttypes.h>	/* See http://en.wikipedia.org/wiki/C_data_types#Fixed-width_integer_types for more info */
#include <asf.h>		/* Only needed to get the definitions for HIGH and LOW */
#include "digitalIO.h"

#define PIOB_BASE_ADDRESS 0x400E1000U

void pinMode(int pinNumber, mode_definition mode)
{
	if (mode == OUTPUT)	/* You only have to program a function that cares about OUTPUT, and does nothing for the other values */
	{
		if(pinNumber == 13) //What pin is selected?
		{
			PIOB-> PIO_PER = PIO_PB27; // Initialize pin 13
			PIOB -> PIO_OER = PIO_PB27; // Set pin 13 to OUTPUT
		}
		else if(pinNumber == 22)
		{
			PIOB-> PIO_PER = PIO_PB26; // Initialize pin 22
			PIOB -> PIO_OER = PIO_PB26; // Set pin 22 to OUTPUT
		}
	}
}

void digitalWrite(int pinNumber, int value)
{
	if (value == HIGH) //Pin to be set High?
	{
		if(pinNumber == 13) //What pin is selected?
		{
			PIOB-> PIO_SODR = PIO_PB27; //Pin 13 High
		}
		else if(pinNumber == 22)
		{
			PIOB-> PIO_SODR = PIO_PB26; //Pin 22 High
		}
	}
	else if (value == LOW) //Pin to be set Low?
	{
		if(pinNumber == 13)
		{
			PIOB-> PIO_CODR = PIO_PB27; //Pin 13 Low
		}
		else if(pinNumber == 22)
		{
			PIOB-> PIO_CODR = PIO_PB26; //Pin 22 Low
		}
	}
}