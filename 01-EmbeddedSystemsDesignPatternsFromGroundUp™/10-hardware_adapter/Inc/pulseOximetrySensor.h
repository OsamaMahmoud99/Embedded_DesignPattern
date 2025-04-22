/*
 * pulseOximetrySensor.h
 *
 *  Created on: Apr 21, 2025
 *      Author: Osama
 */

#ifndef PULSEOXIMETRYSENSOR_H_
#define PULSEOXIMETRYSENSOR_H_

#include <stdint.h>

typedef struct pulseOximetrySensor pulseOximetrySensor;

struct pulseOximetrySensor
{
	uint32_t (*readSpo2)(void);
	uint32_t (*readPulse)(void);
};

#endif /* PULSEOXIMETRYSENSOR_H_ */
