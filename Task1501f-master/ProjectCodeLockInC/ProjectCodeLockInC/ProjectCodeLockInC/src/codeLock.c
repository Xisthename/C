/*
 * codeLock.c
 *
 * Created: 2015-12-16 14:10:22
 * Author: Daniel Petersén and Marcus Sandberg
 */ 
#include <asf.h>
#include "codeLock.h"
#include "initComponents.h"
#include "delayFunctions.h"

void task_codeLock(void *pvParameters) {
/**
 * This task will run the code lock and change the I/O
 */
	// sets current state to LOCKED
	lock_states state = LOCKED;
	init();
	// some variables to the buttons and to the leds
	int K1;
	int K2;
	int K3;
	int L1 = PIN6;
	int L2 = PIN4;
	int L3 = PIN5;
	int L4 = PIN3;
	
    while (1) 
	{
		K1 = digitalRead(PIN7);			// Reads if a button is high or low and stores it into the variables k1-k3
		K2 = digitalRead(PIN8);
		K3 = digitalRead(PIN9);
		
		switch (state)					// Looks at what state the machine is in.
		{
			case LOCKED:				// Current state is equal to LOCKED
			digitalWrite(L1, LOW);
			digitalWrite(L2, LOW);
			digitalWrite(L3, LOW);
			digitalWrite(L4, HIGH);
			if (K1) 
			{
				state = PUSH_ONE;		// Sets state to PUSH_ONE
			} 
			else if (K2 || K3) 
			{
				state = LOCKED;			// Sets state to LOCKED
			}
			break;
			case PUSH_ONE:				// Current state is equal to PUSH_ONE
			if (!K1) 
			{
				state = RELEASE_ONE;	// Sets state to RELEASE_ONE
			}
			break;
			case RELEASE_ONE:			// Current state is equal to RELEASE_ONE
			digitalWrite(L1, HIGH);
			if (K3) 
			{
				state = PUSH_TWO;		// Sets state to PUSH_TWO
			} 
			else if (K1 || K2) 
			{
				state = LOCKED;			// Sets state to LOCKED
			}
			break;
			case PUSH_TWO:				// Current state is equal to PUSH_TWO
			if (!K3) 
			{
				state = RELEASE_TWO;	// Sets state to RELEASE_TWO
			}
			break;
			case RELEASE_TWO:			// Current state is equal to RELEASE_TWO
			digitalWrite(L2, HIGH);
			if (K3) 
			{
				state = PUSH_THREE;		// Sets state to PUSH_THREE
			} 
			else if (K1 || K2) 
			{
				state = LOCKED;			// Sets state to LOCKED
			}
			break;
			case PUSH_THREE:			// Current state is equal to PUSH_THREE
			if (!K3) 
			{
				state = RELEASE_THREE;	// Sets state to RELEASE_THREE
			}
			break;
			case RELEASE_THREE:			// Current state is equal to RELEASE_THREE
			digitalWrite(L3, HIGH);
			if (K2) 
			{
				state = PUSH_FOUR;		// Sets state to PUSH_FOUR
			} 
			else if (K1 || K3) 
			{
				state = LOCKED;			// Sets state to LOCKED
			}
			break;
			case PUSH_FOUR:				// Current state is equal to PUSH_FOUR
			if (!K2) 
			{
				state = OPEN;			// Sets state to OPEN
			}
			break;
			case OPEN:					// Current state is equal to OPEN
			digitalWrite(L4, LOW);
			if (K1 || K2 || K3)
			{
				state = LOCKED;			// Sets state to LOCKED
			}
			break;
		}
        vTaskDelay(50);					// 50 millisecond delay
    }
}