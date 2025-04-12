#include "uart.h"
#include "device.h"

State_T btn;

int main(void)
{


	debug_uart_init();

	DevicePtr device1;
	DevicePtr device2;

	const char* name1 = "Front LED";
	Address addr1 = {GPIOA, 5};

	const char* name2 = "Push Button";
	Address addr2 = {GPIOC, 13};

	device1 = createDevice(name1, &addr1);
	device2 = createDevice(name2, &addr2);

	turnOnDevice(device1);
	displayDeviceInfo(device1);

    while(1)
    {
    	btn = readDevice(device2);

    	if(btn){
    		turnOffDevice(device1);
    	}
    	else{
    		turnOnDevice(device1);
    	}
    }
}
