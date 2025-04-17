
#include <stdio.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "DigitalStopWatch.h"

long watch_1_counter = 0;

int main(void)
{


	debug_uart_init();

	DigitalStopWatchPtr stop_watch_1;
	const char* name1 = "Diag Timer";
	TimeSource timer = {TIMER2};

	stop_watch_1 = createWatch(name1, &timer);

	startWatch(stop_watch_1, 20, &watch_1_counter);

    while(1)
    {

    }
}
