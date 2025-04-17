/*
 * DigitalStopWatch.c
 *
 *  Created on: Apr 16, 2025
 *      Author: Osama
 */

#include "DigitalStopWatch.h"
#include "TimeSource.h"

#define NO_OF_EVENTS 2
#define NO_OF_STATES 2

typedef enum
{
	stopped,
	started
}State;

typedef enum
{
	stopEvent,
	startEvent
}Event;

static State TransitionTable[NO_OF_STATES][NO_OF_EVENTS] = {{stopped,started},{stopped,started}};

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
	const State currentState = instance->state;

	switch(currentState){
	case started:
		printf("watch has already started\n\r");
		break;
	case stopped:

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

	instance->state = TransitionTable[currentState][startEvent];
}

void stopWatch(DigitalStopWatchPtr instance)
{
	const State currentState = instance->state;

	switch(currentState){
	case started:

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

	instance->state = TransitionTable[currentState][stopEvent];

}



