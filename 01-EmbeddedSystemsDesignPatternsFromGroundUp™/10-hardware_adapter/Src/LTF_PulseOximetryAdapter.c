/*
 * LTF_PulseOximetryAdapter.c
 *
 *  Created on: Apr 22, 2025
 *      Author: Osama
 */


#include "LTF_PulseOximetryAdapter.h"
#include <stdlib.h>
#include "uart.h"

LTF_PulseOximetryAdapter * LTF_PulseOximetryAdapter_Create(void)
{
	LTF_PulseOximetryAdapter * me = (LTF_PulseOximetryAdapter*)malloc(sizeof(LTF_PulseOximetryAdapter));
	if(me != NULL){
		LTF_PulseOximetryAdapter_Init(me);
		printf("LTF_PulseOximetryAdapter created successfully\n\r");
	}
	else{
		printf("Low memory could not create adapter\n\r");
	}

	return me;
}

void LTF_PulseOximetryAdapter_Destroy(LTF_PulseOximetryAdapter * const me)
{
	LTF_PulseOximetryAdapter_Cleanup(me);
	free(me);
}

void LTF_PulseOximetryAdapter_Cleanup(LTF_PulseOximetryAdapter * const me)
{
	//Do something...
	printf("Cleanup complete...\n\r");
}

void LTF_PulseOximetryAdapter_Init(LTF_PulseOximetryAdapter * const me)
{
	me->LTF_PhotodiodeProxy =(LTF_PhotodiodeProxy*)malloc(sizeof(LTF_PhotodiodeProxy));

	if(me->LTF_PhotodiodeProxy != NULL){
		me->LTF_PhotodiodeProxy->accessSpo2 = accessSpo2;
		me->LTF_PhotodiodeProxy->accessPulse = accessPulse;
	}
}

int32_t LTF_PulseOximetryAdapter_readSpo2(LTF_PulseOximetryAdapter * const me)
{
	double computed_spo2;

	/*PSUEDO ALGO*/
	computed_spo2 = me->LTF_PhotodiodeProxy->accessSpo2()/9.6;

	return computed_spo2;
}

int32_t LTF_PulseOximetryAdapter_readPulse(LTF_PulseOximetryAdapter * const me)
{
	double computed_pulse;

	/*PSUEDO ALGO*/
	computed_pulse = me->LTF_PhotodiodeProxy->accessPulse()/11;

	return computed_pulse;
}

