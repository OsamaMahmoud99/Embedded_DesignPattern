/*
 * SystemManager.c
 *
 *  Created on: Apr 26, 2025
 *      Author: Osama
 */


#include "SystemManager.h"
#include <stdlib.h>


void SystemManager_Init( SystemManager * const me){

   ECG_Module_Init(&(me->itsECG_Module));
	 HistogramDisplay_Init(&(me->itsHistogramDisplay));
	 ArrythmiaDetector_Init(&(me->itsArrythmiaDetector));
	 QRSDetector_Init(&(me->itsQRSDetector));

	 TMDQueue_Init(&(me->itsTMDQueue));
	 ECG_Module_setItsTMDQueue(&(me->itsECG_Module),&(me->itsTMDQueue));
	 HistogramDisplay_setItsTMDQueue(&(me->itsHistogramDisplay),&(me->itsTMDQueue));
     ArrythmiaDetector_setItsTMDQueue(&(me->itsArrythmiaDetector),&(me->itsTMDQueue));
     QRSDetector_setItsTMDQueue(&(me->itsQRSDetector),&(me->itsTMDQueue));

}
SystemManager * SystemManager_Create(void){

	 SystemManager * me = (SystemManager *)malloc(sizeof(SystemManager));
	 if(me!=NULL){

	   SystemManager_Init(me);
	 }

	 return me;

}


struct HistogramDisplay * SystemManager_getItsHistogramDisplay(SystemManager * const me){

	return  (struct HistogramDisplay  *)&(me->itsHistogramDisplay);

}

struct ArrythmiaDetector * SystemManager_getItsArrythmiaDetector(SystemManager * const me){

	return  (struct ArrythmiaDetector  *)&(me->itsArrythmiaDetector);

}

struct QRSDetector * SystemManager_getItsQRSDetector(SystemManager * const me){

	return  (struct QRSDetector  *)&(me->itsQRSDetector);

}

struct TMDQueue * SystemManager_getItsTMDQueue(SystemManager * const me){

     return (struct TMDQueue *) &(me->itsTMDQueue);

}

void SystemManager_Destroy( SystemManager * const me){

	 free(me);
}


