/*
 * ECG_Module.c
 *
 *  Created on: Apr 26, 2025
 *      Author: Osama
 */


#include "ECG_Module.h"
#include <stdlib.h>
#include "TMDQueue.h"
#include "adc_driver.h"

void ECG_Module_Init(ECG_Module * const me){
   me->dataNum =0;
   me->itsTMDQueue =NULL;
   pa1_analog_init();
}

ECG_Module * ECG_Module_Create(void){

ECG_Module*  me=(ECG_Module *)malloc(sizeof(ECG_Module));
	if(me!=NULL){
	ECG_Module_Init(me);
	}

	return me;
}


void ECG_Module_acquireValue(ECG_Module * const me){

    TimeMarkedData tmd;
	//tmd.dataValue =  rand();// TODO:  Change to adc_read
    tmd.dataValue = pa1_analog_read();
    tmd.timeInterval =  ++me->dataNum;
	TMDQueue_Insert(me->itsTMDQueue,tmd);
}


void ECG_Module_setLeadPair(ECG_Module * const me, uint32_t l1,uint32_t l2){
   me->lead1  = l1;
   me->lead2  = l2;
}


struct TMDQueue * ECG_Module_getsItsTMDQueue(ECG_Module * const me){

	   return (struct TMDQueue *)me->itsTMDQueue;
}
void ECG_Module_setItsTMDQueue(ECG_Module * const me,struct TMDQueue * p_TMDQueue){

   me->itsTMDQueue = p_TMDQueue;
}

void ECG_Module_Cleanup(ECG_Module * const me){

   //Do something...
}

void ECG_Module_Destroy(ECG_Module * const me){

   if(me!=NULL){
	 ECG_Module_Cleanup(me);
	 }

	 free(me);
}
