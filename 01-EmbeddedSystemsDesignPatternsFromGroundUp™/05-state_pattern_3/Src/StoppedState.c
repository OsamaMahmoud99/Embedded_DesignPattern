/*
 * StoppedState.c
 *
 *  Created on: Apr 17, 2025
 *      Author: Osama
 */


#include "StoppedState.h"
#include "StartedState.h"

static void startWatch(WatchStatePtr state){

	transitionToStarted(state);
}

void transitionToStopped(WatchStatePtr state)
{
	defaultImplementation(state);
	state->start = startWatch;
}
