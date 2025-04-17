/*
 * TimeSource.c
 *
 *  Created on: Apr 16, 2025
 *      Author: Osama
 */


#include "TimeSource.h"
#include "stm32f4xx.h"

/*Configure TIM2 to wrap around at 1Hz*/
//16MHZ = 16 000 000cycles every second

// 16 000 000 /1600-1 = 10000 ---> PSC
// 10000 /10000-1 = 1 ---> ARR
void timer2_sec_set(int max_sec, long *current_count)
{
	/*Enable clock access to TIM2*/
	RCC->APB1ENR |= (1U<<0);

	/*Scale clock to 1hz*/
	TIM2->PSC = 1600-1; /*Divided by 1600*/
	TIM2->ARR = 10000-1; /*Divided by 10000*/

	/*Clear Timer counter*/
	TIM2->CNT = 0;

	/*Enable TIM2*/
	TIM2->CR1 = (1U<<0);

	long seconds = 0;

	for(int i=0; i<max_sec; i++){
		while(!(TIM2->SR & 1)); /*wait for UIF set*/
		seconds++;
		*current_count = seconds;
		printf("Elapsed time : %ld \n\r", seconds);

		/*Clear UIF*/
		TIM2->SR &=~1;
	}
}

void timer2_sec_reset(void)
{
	TIM2->CR1 = 0;
}

void systick_millis_set(int max_millis, long *current_count)
{
	SysTick->LOAD = 16000-1; /*Reload with number of clocks per seconds*/
	SysTick->VAL = 0;
	SysTick->CTRL = 5; /*Enable Systick, No interrupt, use system clock*/

	long milliseconds = 0;
	for(int i=0; i<max_millis; i++){
		while((SysTick->CTRL & 0x10000)); /*if count flag is set*/
		milliseconds++;
		*current_count = milliseconds;
		printf("Elapsed Time : %ld\n\r",milliseconds);

	}

	SysTick->CTRL = 0; /*Disable clock*/

}

void systick_millis_reset(void)
{
	SysTick->CTRL = 0; /*Disable clock*/
}
