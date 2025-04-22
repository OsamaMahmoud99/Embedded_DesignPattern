#include "uart.h"
#include "OximetryDisplay.h"

int main(void)
{


	debug_uart_init();


	oximetry_display_update();

    while(1)
    {

    }
}
