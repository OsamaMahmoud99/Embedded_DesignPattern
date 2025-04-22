/*
 * OximetryDisplay.c
 *
 *  Created on: Apr 22, 2025
 *      Author: Osama
 */


#include "OximetryDisplay.h"
#include "uart.h"


void oximetry_display_update(void)
{
	pulseOximetrySensor pulseOx;

	TIA_PulseOximetryAdapter * tia_PulseOximetryAdapter = TIA_PulseOximetryAdapter_Create();
	LTF_PulseOximetryAdapter * ltf_PulseOximetryAdapter = LTF_PulseOximetryAdapter_Create();

	int32_t tia_spo2 = TIA_PulseOximetryAdapter_readSpo2(tia_PulseOximetryAdapter);
	int32_t tia_pulse = TIA_PulseOximetryAdapter_readPulse(tia_PulseOximetryAdapter);

	int32_t ltf_spo2 = LTF_PulseOximetryAdapter_readSpo2(ltf_PulseOximetryAdapter);
	int32_t ltf_pulse = LTF_PulseOximetryAdapter_readPulse(ltf_PulseOximetryAdapter);


	printf("|**************TIA Sensor**********|\n\r");
	printf("Spo2 : %d\n\r",tia_spo2);
	printf("Pulse : %d\n\r",tia_pulse);
	printf("-------------------------------------\n\r");

	printf("|**************LTF Sensor**********|\n\r");
	printf("Spo2 : %d\n\r",ltf_spo2);
	printf("Pulse : %d\n\r",ltf_pulse);
	printf("-------------------------------------\n\r");
}
