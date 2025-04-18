/*
 * WatchState.c
 *
 *  Created on: Apr 17, 2025
 *      Author: Osama
 */

#include "WatchState.h"

static void defaultStop(WatchStatePtr state)
{

}

static void defaultStart(WatchStatePtr state)
{

}

void defaultImplementation(WatchStatePtr state)
{
	state->start = defaultStart;
	state->stop = defaultStop;
}
