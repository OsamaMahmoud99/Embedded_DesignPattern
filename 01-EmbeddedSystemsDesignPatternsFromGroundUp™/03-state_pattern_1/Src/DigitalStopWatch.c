/*
 * DigitalStopWatch.c
 *
 *  Created on: Apr 16, 2025
 *      Author: Osama
 */

#include "DigitalStopWatch.h"
#include "TimeSource.h"

typedef enum
{
	stopped,
	started
}State;

struct DigitalStopWatch
{
	State state;
	TimeSource source;
	const char *name;
};

DigitalStopWatchPtr createWatch(const char *name, const TimeSource* tmr)
{
	DigitalStopWatchPtr new_watch = (DigitalStopWatchPtr)calloc(sizeof(DigitalStopWatchPtr), sizeof(DigitalStopWatchPtr));
	if(new_watch){
		new_watch->state = stopped;
		new_watch->name = name;
		new_watch->source.timer = tmr->timer;
		printf("Watch created successfully\n\r");
	}
	else{

		printf("Low Memory Could not create watch\n\r");
	}

	return new_watch;
}

void startWatch(DigitalStopWatchPtr instance, long max_time, long *current_count)
{
	switch(instance->state){
	case started:
		printf("watch has already started\n\r");
		break;
	case stopped:
		instance->state = started;
		printf("STARTED \n\r");
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
		break;
		default:
			printf("State does not exist\n\r");
	}
}

void stopWatch(DigitalStopWatchPtr instance)
{
	switch(instance->state){
	case started:
		instance->state = stopped;
		printf("STOPPED\n\r");
		switch(instance->source.timer){
		case TIMER2:
			timer2_sec_reset();
			break;
		case SYSTICK:
			systick_millis_reset();
			break;
		}
		break;
	case stopped:
		printf("watch has already stopped!!\n\r");
		break;
	default:
		printf("State does not exist\n\r");

	}
}



