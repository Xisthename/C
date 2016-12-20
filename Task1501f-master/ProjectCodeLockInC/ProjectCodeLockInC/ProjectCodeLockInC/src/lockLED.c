/*
 * lockLED.c
 *
 * Created: 2015-12-16 19:53:42
 * Author: Daniel Petersén and Marcus Sandberg
 */ 
#include <asf.h>
#include "lockLED.h"
/**
 *  This tasks makes the on-board LED blink every second
 */
void task_led(void *pvParameters)
{
    portTickType xLastWakeTime;
    const portTickType xTimeIncrement = 500;

    xLastWakeTime = xTaskGetTickCount(); /* Initialise the xLastWakeTime variable with the current time. */
    while (1) 
	{
		vTaskDelayUntil(&xLastWakeTime, xTimeIncrement); /* Wait for the next cycle. */
        ioport_toggle_pin_level(LED0_IOPORT);
		//gpio_toggle_pin(LED0_GPIO);
    }
}
