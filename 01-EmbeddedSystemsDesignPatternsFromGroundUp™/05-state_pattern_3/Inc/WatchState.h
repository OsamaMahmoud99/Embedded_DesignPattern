/*
 * WatchState.h
 *
 *  Created on: Apr 17, 2025
 *      Author: Osama
 */

#ifndef WATCHSTATE_H_
#define WATCHSTATE_H_

typedef struct WatchState* WatchStatePtr;

typedef void(*EventStartFunc)(WatchStatePtr);
typedef void(*EventStopFunc)(WatchStatePtr);

struct WatchState
{
	EventStartFunc start;
	EventStopFunc  stop;
};

#endif /* WATCHSTATE_H_ */
