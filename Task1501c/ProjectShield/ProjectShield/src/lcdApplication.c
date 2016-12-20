/*
 * lcdApplication.c
 *
 * Created: 2015-09-10 08:44:50
 *  Author: To Be Decided
 */ 

#include "lcdApplication.h"
#include "buttons.h"	/* to get the buttontype definiton */
#include "LCDFunctions.h"
#include "delayFunctions.h"

int lcdWrite4DigitNumber(int number)
{
	int temp[4];
	int count = 0;
	while (number > 0)
	{
		int digit = number % 10;
		temp[count] = digit;
		count++;
		number /= 10;
	}
	
	for (int i = 3; i > -1; i--)
	{
		if (temp[i] >= 0 && temp[i] <= 9)
		{
			lcdWrite(temp[i] + 48, HIGH);
		}
	}
	delayMicroseconds(500);
	return 0;	/* Assuming everything went ok */	
}

int lcdWriteAsciiString(const char *string)
/* writes an ascii string up to 40 characters on the LCD display */
{
	return 0;	/* Assuming everything went ok */
}

int lcdWriteButtonValue(buttonType inputButton)
/* Writes the text corresponding to one of the buttosn on the LCD dispaly using lcdWriteAsciiString() 
 * Output should be one of SELECT, LEFT, UP, DOWN, RIGHT on the LCD display
 * if no buttons is pushed you can chose on displaying nothing or NONE  */
{
	lcdWrite(inputButton, HIGH);
	return 0;	/* Assuming everything went ok */
}