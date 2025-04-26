/*
 * ArrythmiaDetector.c
 *
 *  Created on: Apr 26, 2025
 *      Author: Osama
 */


#include "ArrythmiaDetector.h"
#include "TMDQueue.h"
#include <stdlib.h>
#include "uart.h"

void ArrythmiaDetector_Init(ArrythmiaDetector * const me){

	me->index =0;
	me->itsTMDQueue= NULL;

}

ArrythmiaDetector *  ArrythmiaDetector_Create(void){

		ArrythmiaDetector *	me=		(ArrythmiaDetector *)	malloc(sizeof(ArrythmiaDetector));
	if( me !=NULL){

	ArrythmiaDetector_Init(me);

	}
}

void ArrythmiaDetector_Identify(ArrythmiaDetector * const me){

	 //Implement complex arrythmia identification...
}


void ArrythmiaDetector_getDataSample(ArrythmiaDetector * const me){
   TimeMarkedData tmd;
	 tmd =  TMDQueue_remove(me->itsTMDQueue,me->index);
	 printf("ArrythmiaDetector index :  %d  TimeInterval : %d DataValue :  %d\n\r",me->index,tmd.timeInterval,tmd.dataValue);
	 me->index  =  TMDQueue_getNextIndex(me->itsTMDQueue,me->index);
}

void ArrythmiaDetector_setItsTMDQueue(ArrythmiaDetector * const me, struct TMDQueue * p_TMDQueue){

	me->itsTMDQueue =  p_TMDQueue;
}


void ArrythmiaDetector_Destroy(ArrythmiaDetector * const me){

   //Do cleanup..
	  free(me);
}
