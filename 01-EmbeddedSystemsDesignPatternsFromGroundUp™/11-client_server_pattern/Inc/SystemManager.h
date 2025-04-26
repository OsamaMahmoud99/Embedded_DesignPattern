/*
 * SystemManager.h
 *
 *  Created on: Apr 26, 2025
 *      Author: Osama
 */

#ifndef SYSTEMMANAGER_H_
#define SYSTEMMANAGER_H_

#include "ECG_Module.h"
#include "TMDQueue.h"
#include "HistogramDisplay.h"
#include "ArrythmiaDetector.h"
#include "QRSDetector.h"

#include "ECGPkg.h"


typedef struct SystemManager  SystemManager;

struct SystemManager{
   struct ECG_Module itsECG_Module;
	 struct HistogramDisplay itsHistogramDisplay;
	 struct QRSDetector itsQRSDetector;
	 struct ArrythmiaDetector itsArrythmiaDetector;
	 struct TMDQueue itsTMDQueue;
};

SystemManager * SystemManager_Create(void);
void SystemManager_Init( SystemManager * const me);
struct HistogramDisplay * SystemManager_getItsHistogramDisplay(SystemManager * const me);
struct QRSDetector * SystemManager_getItsQRSDetector(SystemManager * const me);
struct ArrythmiaDetector * SystemManager_getItsArrythmiaDetector(SystemManager * const me);
struct TMDQueue * SystemManager_getItsTMDQueue(SystemManager * const me);
void SystemManager_Destroy( SystemManager * const me);



#endif /* SYSTEMMANAGER_H_ */
