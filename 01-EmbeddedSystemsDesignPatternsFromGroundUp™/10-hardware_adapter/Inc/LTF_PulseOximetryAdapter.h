/*
 * LTF_PulseOximetryAdapter.h
 *
 *  Created on: Apr 21, 2025
 *      Author: Osama
 */

#ifndef LTF_PULSEOXIMETRYADAPTER_H_
#define LTF_PULSEOXIMETRYADAPTER_H_

#include "LTF_PhotodiodeProxy.h"
#include "pulseOximetrySensor.h"

typedef struct LTF_PulseOximetryAdapter LTF_PulseOximetryAdapter;

struct LTF_PulseOximetryAdapter
{
	pulseOximetrySensor * pulseOximetrySensor;
	LTF_PhotodiodeProxy * LTF_PhotodiodeProxy;
};

LTF_PulseOximetryAdapter * LTF_PulseOximetryAdapter_Create(void);
void LTF_PulseOximetryAdapter_Destroy(LTF_PulseOximetryAdapter * const me);

void LTF_PulseOximetryAdapter_Init(LTF_PulseOximetryAdapter * const me);
void LTF_PulseOximetryAdapter_Cleanup(LTF_PulseOximetryAdapter * const me);

int32_t LTF_PulseOximetryAdapter_readSpo2(LTF_PulseOximetryAdapter * const me);
int32_t LTF_PulseOximetryAdapter_readPulse(LTF_PulseOximetryAdapter * const me);

#endif /* LTF_PULSEOXIMETRYADAPTER_H_ */
