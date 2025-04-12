
#include <stdio.h>
#include "stm32f4xx.h"
#include "uart.h"


int main(void)
{


	debug_uart_init();



    while(1)
    {
    	printf("Hello from STM32\n\r");

    	for(int i=0; i<9000; i++){}
    }
}
