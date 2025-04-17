/*
 * DigitalStopWatch.h
 *
 *  Created on: Apr 16, 2025
 *      Author: Osama
 */

#ifndef DIGITALSTOPWATCH_H_
#define DIGITALSTOPWATCH_H_

#include "TimeSource.h"

typedef struct DigitalStopWatch * DigitalStopWatchPtr;

DigitalStopWatchPtr createWatch(const char *name, const TimeSource* tmr);

void startWatch(DigitalStopWatchPtr instance, long max_time, long *current_count);
void stopWatch(DigitalStopWatchPtr instance);

#endif /* DIGITALSTOPWATCH_H_ */
