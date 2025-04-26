/*
 * HistogramDisplay.c
 *
 *  Created on: Apr 26, 2025
 *      Author: Osama
 */


#include "HistogramDisplay.h"
#include "TMDQueue.h"
#include <stdlib.h>
#include "uart.h"

void HistogramDisplay_Init(HistogramDisplay * const me){
  me->index = 0;
	me->itsTMDQueue = NULL;

}
HistogramDisplay * HistogramDisplay_Create(void){

   HistogramDisplay * me=(HistogramDisplay *) malloc(sizeof(HistogramDisplay));
	  if(me!=NULL){
		  HistogramDisplay_Init(me);
		}

		return me;
}

void HistogramDisplay_getValue(HistogramDisplay * const me){

	TimeMarkedData tmd;
	tmd  = TMDQueue_remove(me->itsTMDQueue,me->index);
	printf("Histogram index is : %d TimeInterval:  %d  DataValue :  %d \r\n",me->index,tmd.timeInterval,tmd.dataValue);
	me->index =  TMDQueue_getNextIndex(me->itsTMDQueue,me->index);

}


void HistogramDisplay_updateHistogram(HistogramDisplay * const me){

   //Do something...

	printf("Hitogram updated...\n\r");

}

void HistogramDisplay_setItsTMDQueue(HistogramDisplay * const me,struct TMDQueue * p_TMDQueue){

   me->itsTMDQueue =  p_TMDQueue;
}


void HistogramDisplay_Destroy(HistogramDisplay * const me){

	if(me->itsTMDQueue != NULL){
	   me->itsTMDQueue = NULL;
	}
	free(me);
}


