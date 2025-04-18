/*
 * TimeSource.h
 *
 *  Created on: Apr 16, 2025
 *      Author: Osama
 */

#ifndef TIMESOURCE_H_
#define TIMESOURCE_H_


typedef enum{
	TIMER2,
	SYSTICK
}HardwareTimer;

typedef struct
{
	HardwareTimer timer;
}TimeSource;

void timer2_sec_set(int max_sec, long *current_count);
void timer2_sec_reset(void);
void systick_millis_set(int max_millis, long *current_count);
void systick_millis_reset(void);

#endif /* TIMESOURCE_H_ */
