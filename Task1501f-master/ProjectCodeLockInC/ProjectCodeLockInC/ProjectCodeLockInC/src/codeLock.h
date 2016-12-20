/*
 * codeLock.h
 *
 * Created: 2015-12-16 13:53:49
 * Author: Daniel Petersén and Marcus Sandberg
 */

#ifndef CODELOCK_H_
#define CODELOCK_H_
#define TASK_CODELOCK_STACK_SIZE        (2048/sizeof(portSTACK_TYPE))
#define TASK_CODELOCK_STACK_PRIORITY    (2)

/* Creates the states that the state machine can be in*/
typedef enum {LOCKED, PUSH_ONE, RELEASE_ONE, PUSH_TWO, RELEASE_TWO,
			  PUSH_THREE, RELEASE_THREE, PUSH_FOUR, OPEN} lock_states;
	
void task_codeLock(void *pvParameters);

#endif /* CODELOCK_H_ */