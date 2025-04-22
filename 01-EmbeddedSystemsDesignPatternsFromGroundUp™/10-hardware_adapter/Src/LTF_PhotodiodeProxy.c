/*
 * LTF_PhotodiodeProxy.c
 *
 *  Created on: Apr 21, 2025
 *      Author: Osama
 */

#include "adc_driver.h"


uint32_t accessSpo2(void)
{
	temp_sensor_init();

	return (read_chip_analog());
}

uint32_t accessPulse(void)
{
	temp_sensor_init();

	return (read_chip_analog());
}
