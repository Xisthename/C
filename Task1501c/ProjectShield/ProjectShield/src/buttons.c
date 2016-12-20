/*
 * buttons.c
 *
 * Created: 2015-06-12 16:28:53
 * Author: To Be Decided
 */ 

#include "buttons.h"
#include "adcFunctions.h"	/* Must use the value from the ADC to figure out which button */
#include "LCDFunctions.h"
#include "lcdApplication.h"

buttonType readLCDbutton(void)
{
	if (analogRead(0) < 50)
	{
		return btnRIGHT;
	}
	else if (analogRead(0) < 600)
	{
		return btnUP;
	}
	else if (analogRead(0) < 1300)
	{
		return btnDOWN;
	}
	else if (analogRead(0) < 1900)
	{
		return btnLEFT;
	}
	else if (analogRead(0) < 2500)
	{
		return btnSELECT;
	}
	else 
	{
		return btnNONE;
	}
}