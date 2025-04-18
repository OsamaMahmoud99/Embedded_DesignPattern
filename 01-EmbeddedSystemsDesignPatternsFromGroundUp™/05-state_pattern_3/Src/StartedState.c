/*
 * StartedState.c
 *
 *  Created on: Apr 17, 2025
 *      Author: Osama
 */

#include "StartedState.h"
#include "StoppedState.h"

static void stopWatch(WatchStatePtr state){

	transitionToStopped(state);
}

void transitionToStarted(WatchStatePtr state)
{
	defaultImplementation(state);
	state->stop = stopWatch;
}
