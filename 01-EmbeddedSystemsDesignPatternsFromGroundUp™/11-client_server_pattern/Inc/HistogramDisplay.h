/*
 * HistogramDisplay.h
 *
 *  Created on: Apr 26, 2025
 *      Author: Osama
 */

#ifndef HISTOGRAMDISPLAY_H_
#define HISTOGRAMDISPLAY_H_

#include <stdint.h>
#include "ECGPkg.h"


typedef struct HistogramDisplay HistogramDisplay;

struct HistogramDisplay{
   uint32_t index;
	struct TMDQueue * itsTMDQueue;
};

void HistogramDisplay_Init(HistogramDisplay * const me);
HistogramDisplay * HistogramDisplay_Create(void);
void HistogramDisplay_getValue(HistogramDisplay * const me);
void HistogramDisplay_updateHistogram(HistogramDisplay * const me);
void HistogramDisplay_setItsTMDQueue(HistogramDisplay * const me,struct TMDQueue * p_TMDQueue);
void HistogramDisplay_Destroy(HistogramDisplay * const me);


#endif /* HISTOGRAMDISPLAY_H_ */
