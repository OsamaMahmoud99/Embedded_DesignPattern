
#include <stdio.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "gpio_driver.h"
#include "adc_driver.h"

bool btn_state;
uint32_t sensorValue;

int main(void)
{


	debug_uart_init();
	p1_button_init();
	pa1_analog_init();



    while(1)
    {
    	btn_state = get_p13_button_state();
    	sensorValue = pa1_analog_read();
    }
}
