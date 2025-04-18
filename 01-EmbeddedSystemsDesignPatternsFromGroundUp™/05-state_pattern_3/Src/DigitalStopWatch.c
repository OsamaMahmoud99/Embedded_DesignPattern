/*
 * DigitalStopWatch.c
 *
 *  Created on: Apr 16, 2025
 *      Author: Osama
 */

#include "DigitalStopWatch.h"
#include "TimeSource.h"

#include "StoppedState.h"

struct DigitalStopWatch
{
	struct WatchState state;
	TimeSource source;
	const char *name;
};

DigitalStopWatchPtr createWatch(const char *name, const TimeSource* tmr)
{
	DigitalStopWatchPtr new_watch = (DigitalStopWatchPtr)calloc(sizeof(DigitalStopWatchPtr), sizeof(DigitalStopWatchPtr));

	if(new_watch){

		transitionToStopped(&new_watch->state);
		new_watch->name = name;
		new_watch->source.timer = tmr->timer;

		printf("Watch created successfully \n\r");
	}else{

		printf("Low Memory Could not create watch \n\r");
	}

	return new_watch;
}

void stopWatch(DigitalStopWatchPtr instance)
{
	instance->state.stop(&instance->state);

	switch(instance->source.timer){
	case TIMER2:
		timer2_sec_reset();
		break;
	case SYSTICK:
		systick_millis_reset();
		break;
	default:
		break;
	}
}

void startWatch(DigitalStopWatchPtr instance, long max_time, long *current_count)
{
	instance->state.start(&instance->state);

	switch(instance->source.timer){
	case TIMER2:
		timer2_sec_set(max_time, current_count);
		break;
	case SYSTICK:
		systick_millis_set(max_time, current_count);
		break;
	default:
		break;
	}
}

void destroyWatch(DigitalStopWatchPtr instance){
	free(instance);
}
