/*
 * TIA_PulseOximetryAdapter.c
 *
 *  Created on: Apr 22, 2025
 *      Author: Osama
 */


#include "TIA_PulseOximetryAdapter.h"
#include <stdlib.h>
#include "uart.h"

TIA_PulseOximetryAdapter * TIA_PulseOximetryAdapter_Create(void)
{
	TIA_PulseOximetryAdapter * me = (TIA_PulseOximetryAdapter*)malloc(sizeof(TIA_PulseOximetryAdapter));
	if(me != NULL){
		TIA_PulseOximetryAdapter_Init(me);
		printf("TIA_PulseOximetryAdapter created successfully\n\r");
	}
	else{
		printf("Low memory could not create adapter\n\r");
	}

	return me;

}

void TIA_PulseOximetryAdapter_Destroy(TIA_PulseOximetryAdapter * const me)
{
	TIA_PulseOximetryAdapter_Cleanup(me);
	free(me);
}

void TIA_PulseOximetryAdapter_Cleanup(TIA_PulseOximetryAdapter * const me)
{
	//Do something...
	printf("Cleanup complete...\n\r");
}

void TIA_PulseOximetryAdapter_Init(TIA_PulseOximetryAdapter * const me)
{
	me->TIA_PhotodiodeProxy =(TIA_PhotodiodeProxy*)malloc(sizeof(TIA_PhotodiodeProxy));

	if(me->TIA_PhotodiodeProxy != NULL){
		me->TIA_PhotodiodeProxy->getSpo2 = getSpo2;
		me->TIA_PhotodiodeProxy->getPulse = getPulse;
	}
}

int32_t TIA_PulseOximetryAdapter_readSpo2(TIA_PulseOximetryAdapter * const me)
{
	double volt, computed_spo2;
	uint32_t temp;
	temp = me->TIA_PhotodiodeProxy->getSpo2();

	volt = ((temp *3.3)/4095);
	/*PSUEDO ALGO*/
	computed_spo2 = volt * 30;

	if(computed_spo2 < 80){
		return -999;
	}
	else{
		return computed_spo2;
	}
}

int32_t TIA_PulseOximetryAdapter_readPulse(TIA_PulseOximetryAdapter * const me)
{
	double volt, computed_pulse;
	uint32_t temp;
	temp = me->TIA_PhotodiodeProxy->getPulse();

	volt = ((temp *3.3)/4095);
	/*PSUEDO ALGO*/
	computed_pulse = volt * 25;

	return computed_pulse;
}
