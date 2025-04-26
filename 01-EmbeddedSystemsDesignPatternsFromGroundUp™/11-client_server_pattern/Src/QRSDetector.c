/*
 * QRSDetector.c
 *
 *  Created on: Apr 26, 2025
 *      Author: Osama
 */


#include "QRSDetector.h"
#include "TMDQueue.h"
#include <stdlib.h>
#include "uart.h"

void QRSDetector_Init(QRSDetector * const me){

	 me->heartRate =0;
	 me->index =0;
	 me->itsTMDQueue = NULL;
}

QRSDetector * QRSDetector_Create(void){

 QRSDetector *  me  =(QRSDetector *) malloc(sizeof(QRSDetector));

	 if( me !=NULL){
	 QRSDetector_Init(me);
	 }
}


void QRSDetector_computeHeartRate(QRSDetector * const me){
   //HeartRate computation algo...


	  me->heartRate =  85; //The 85 is being used as an eg.

}


void QRSDetector_getDataSample(QRSDetector * const me){
	TimeMarkedData tmd;
	tmd  = TMDQueue_remove(me->itsTMDQueue,me->index);
	printf("QRSDetector index is : %d TimeInterval:  %d  DataValue :  %d \r\n",me->index,tmd.timeInterval,tmd.dataValue);
	me->index =  TMDQueue_getNextIndex(me->itsTMDQueue,me->index);
}

void QRSDetector_setItsTMDQueue(QRSDetector * const me, struct TMDQueue * p_TMDQueue){
   me->itsTMDQueue =  p_TMDQueue;
}


void QRSDetector_Destroy(QRSDetector * const me){

   free(me);
}
