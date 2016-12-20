/*
 * lockLED.h
 *
 * Created: 2015-12-16 19:54:17
 * Author: Daniel Petersén and Marcus Sandberg
 */ 

#ifndef INCFILE1_H_
#define INCFILE1_H_
#define LED0_IOPORT PIO_PB27_IDX
#define TASK_LED_STACK_SIZE     (1024/sizeof(portSTACK_TYPE))
#define TASK_LED_STACK_PRIORITY     (tskIDLE_PRIORITY)

void task_led(void *pvParameters);

#endif /* LOCKLED_H_ */