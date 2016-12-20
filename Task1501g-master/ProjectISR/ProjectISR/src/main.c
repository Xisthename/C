/**
 * @file main.c
 *
 * @brief main file initiating all necessary hardware and then blinking LED
 *
 * @author Uek
 *
 * @date 2015-12-17
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
#include <asf.h>
#include "digitalIO.h" /* Functions developed in Task1501a */
#include "DelayFunctions.h"
#include "ISR.h"
#include "DAC.h"

int main (void)
{
	// Insert system clock initialization code here (sysclk_init()).
	sysclk_init();
	board_init();
	delayInit();
	configure_tc();
	daccInit();
	pinMode(22, OUTPUT);
	pinMode(13, OUTPUT);
	
	while(1)	/* repeat blink to infinity */
	{
		digitalWrite(13, 1); /* sets a bit of I/O port B to high */
		delayMicroseconds(500000);
		digitalWrite(13, 0); /* clears a bit of I/O port B */
		delayMicroseconds(500000);
	}
}
