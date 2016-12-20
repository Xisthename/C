/*
 * stateMachine.c
 *
 * Created: 2015-08-05 11:10:34
 *  Author: Uek
 */ 

#include "stateMachine.h"

codeLockType SM;			/* The memory area for the state machine */
codeLockPtrType instance;	/* A pointer to a state machine of this type */

/* 
 * The assignment of the pointer to the memory area for the state machine,
 * instance = &SM, is done in test_FSM_runner.c
 */

void startCodeLock(codeLockPtrType foo) /* Maing sure the FSM starts in the right state */
{
	/* Write code here */
}

void pushButton1(codeLockPtrType foo)		/* Yellow button is pushed */
{
	/* Write code here */
}

void pushButton2(codeLockPtrType foo)		/* Red button is pushed */
{
	/* Write code here */
}

void pushButton3(codeLockPtrType foo)		/* Green button is pushed */
{
	/* Write code here */
}

void releaseButton(codeLockPtrType foo)	/* No button is pushed */
{
	/* Write code here */
}