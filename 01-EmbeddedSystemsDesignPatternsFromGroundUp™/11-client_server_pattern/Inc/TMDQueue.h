/*
 * TMDQueue.h
 *
 *  Created on: Apr 24, 2025
 *      Author: Osama
 */

#ifndef TMDQUEUE_H_
#define TMDQUEUE_H_

#include "ECGPkg.h"
#include "TimeMarkerData.h"

typedef struct TMDQueue TMDQueue;

struct TMDQueue{

	uint32_t head;
	uint32_t size;

	TimeMarkedData buffer[QUEUE_SIZE];
};

uint32_t TMDQueue_getNextIndex(TMDQueue * const me, uint32_t index);
TMDQueue * TMDQueue_Create(void);
void TMDQueue_Init(TMDQueue * const me);
void TMDQueue_Insert(TMDQueue * const me, const TimeMarkedData tmd);
uint8_t TMDQueue_isEmpty(TMDQueue * const me);
TimeMarkedData TMDQueue_remove(TMDQueue * const me, uint32_t index);
void TMDQueue_CleanUp(TMDQueue * const me);
void TMDQueue_Destroy(TMDQueue * const me);

#endif /* TMDQUEUE_H_ */
