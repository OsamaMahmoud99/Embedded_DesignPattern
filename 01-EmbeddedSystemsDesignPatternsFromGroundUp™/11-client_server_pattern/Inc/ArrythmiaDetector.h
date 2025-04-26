/*
 * ArrythmiaDetector.h
 *
 *  Created on: Apr 26, 2025
 *      Author: Osama
 */

#ifndef ARRYTHMIADETECTOR_H_
#define ARRYTHMIADETECTOR_H_
#include "ECGPkg.h"
#include <stdint.h>


typedef struct ArrythmiaDetector ArrythmiaDetector;

struct ArrythmiaDetector
{
   uint32_t index;
	 struct TMDQueue * itsTMDQueue;
	 uint32_t  STSegmentHeight;
	 uint32_t fibrillation;
	 uint32_t firstDegreeHeartBlock;
};

ArrythmiaDetector *  ArrythmiaDetector_Create(void);
void ArrythmiaDetector_Init(ArrythmiaDetector * const me);
void ArrythmiaDetector_Identify(ArrythmiaDetector * const me);
void ArrythmiaDetector_getDataSample(ArrythmiaDetector * const me);
void ArrythmiaDetector_setItsTMDQueue(ArrythmiaDetector * const me, struct TMDQueue * p_TMDQueue);
void ArrythmiaDetector_Destroy(ArrythmiaDetector * const me);


#endif /* ARRYTHMIADETECTOR_H_ */
