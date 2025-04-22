/*
 * TIA_PhotodiodeProxy.c
 *
 *  Created on: Apr 21, 2025
 *      Author: Osama
 */

#include "adc_driver.h"


uint32_t getSpo2(void)
{
	pa1_analog_init();

	return (pa1_analog_read());
}

uint32_t getPulse(void)
{
	pa1_analog_init();

	return (pa1_analog_read());
}
