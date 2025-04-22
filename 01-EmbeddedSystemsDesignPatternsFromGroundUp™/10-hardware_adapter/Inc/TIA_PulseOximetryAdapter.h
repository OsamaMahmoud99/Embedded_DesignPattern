/*
 * TIA_PulseOximetryAdapter.h
 *
 *  Created on: Apr 21, 2025
 *      Author: Osama
 */

#ifndef TIA_PULSEOXIMETRYADAPTER_H_
#define TIA_PULSEOXIMETRYADAPTER_H_

#include "TIA_PhotodiodeProxy.h"
#include "pulseOximetrySensor.h"

typedef struct TIA_PulseOximetryAdapter TIA_PulseOximetryAdapter;

struct TIA_PulseOximetryAdapter
{
	pulseOximetrySensor * pulseOximetrySensor;
	TIA_PhotodiodeProxy * TIA_PhotodiodeProxy;
};

TIA_PulseOximetryAdapter * TIA_PulseOximetryAdapter_Create(void);
void TIA_PulseOximetryAdapter_Destroy(TIA_PulseOximetryAdapter * const me);

void TIA_PulseOximetryAdapter_Init(TIA_PulseOximetryAdapter * const me);
void TIA_PulseOximetryAdapter_Cleanup(TIA_PulseOximetryAdapter * const me);

int32_t TIA_PulseOximetryAdapter_readSpo2(TIA_PulseOximetryAdapter * const me);
int32_t TIA_PulseOximetryAdapter_readPulse(TIA_PulseOximetryAdapter * const me);

#endif /* TIA_PULSEOXIMETRYADAPTER_H_ */
