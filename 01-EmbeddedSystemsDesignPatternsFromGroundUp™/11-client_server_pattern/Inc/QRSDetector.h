/*
 * QRSDetector.h
 *
 *  Created on: Apr 26, 2025
 *      Author: Osama
 */

#ifndef QRSDETECTOR_H_
#define QRSDETECTOR_H_
#include <stdint.h>
#include "ECGPkg.h"


typedef struct QRSDetector QRSDetector;
struct QRSDetector{
	uint32_t index;
  struct TMDQueue * itsTMDQueue;
	uint32_t heartRate;
};


void QRSDetector_Init(QRSDetector * const me);
QRSDetector * QRSDetector_Create(void);

void QRSDetector_computeHeartRate(QRSDetector * const me);
void QRSDetector_getDataSample(QRSDetector * const me);
void QRSDetector_setItsTMDQueue(QRSDetector * const me, struct TMDQueue * p_TMDQueue);
void QRSDetector_Destroy(QRSDetector * const me);

#endif /* QRSDETECTOR_H_ */
