/*
 * ISR.c
 *
 * Created: 2016-01-13 13:40:26
 *  Author: Daniel and Marcus
 */ 

#include <asf.h>
#include "ISR.h"
#include "digitalIO.h"
#include <inttypes.h>
uint8_t counter;
uint32_t result; /* global variable declared outside of the ISR */
uint32_t freq = ((950821 % 1979) + 1013) / 16;
uint32_t daccOutput[] = {1860, 2216, 2517, 2720, 2791, 2720, 2517, 2216, 1860, 1504, 1203, 1001, 930, 1001, 1203, 1504};
uint32_t randomNumber;
uint32_t value;
 
void TC5_Handler(void) /* function name defined by ASF */
{
	digitalWrite(22, HIGH);							// Checking that this function really are running by setting pin 22 high and then low
	pmc_enable_periph_clk(ID_TRNG);
	trng_enable(TRNG);
	volatile uint32_t ul_dummy;
	/* Clear status bit to acknowledge interrupt */
	ul_dummy = tc_get_status(TC1, 0);
	UNUSED(ul_dummy); /* Avoid compiler warning */
	randomNumber = trng_read_output_data(TRNG);		// Stores a random 32 bit number into the variable 'randomNumber'
	randomNumber = randomNumber % (2 * 186) - 186;  // Scales 'randomnumber' to an interval of -186 to 186 (-0.1V to 0.1V when written to the DACC)
	value = daccOutput[counter] + randomNumber;		// Stores a number from the array daccOutput and adds 'randomnumber' to it
	counter++;										// Increases the counter by 1
	if (counter > 15)								// Resets the counter
	{
		counter = 0;
	}
	digitalWrite(22, LOW);
	dacc_write_conversion_data(DACC, value);		// Writes to the DACC
}

void configure_tc(void)
{
	uint32_t ul_div;
	uint32_t ul_tcclks;
	uint32_t ul_sysclk = sysclk_get_cpu_hz();
	/* Configure power management of timer clocks */
	pmc_enable_periph_clk(ID_TC5);
	/* Configure TC for a 44,1kHz frequency and trigger on RC compare. */
	tc_find_mck_divisor(freq, ul_sysclk, &ul_div, &ul_tcclks, ul_sysclk);
	tc_init(TC1, 2, ul_tcclks | TC_CMR_CPCTRG);
	tc_write_rc(TC1, 2, (ul_sysclk / ul_div) / freq);
	/* Configure and enable interrupt on RC compare */
	NVIC_EnableIRQ((IRQn_Type) ID_TC5);
	tc_enable_interrupt(TC1, 2, TC_IER_CPCS);
	tc_start(TC1, 2);
}

// k = 1861
// b = -931
// reg = k * v + b
// reg = 1861 * 1.5 - 931
