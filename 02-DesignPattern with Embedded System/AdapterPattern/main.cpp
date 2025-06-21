#define F_CPU 16000000UL

#include "Uart.hpp"
#include <Seg.hpp>
#include "Adapter.hpp"
int main(void)
{
        Uart serial;
        serial.TransmitString("hello\r\n");

        Segment Unitdisplay;
        AdapterSerialDisplay objcontrol;
        sei();

        while(1)
        {
                objcontrol.RequestNumber(serial, Unitdisplay);
        }

        return 0;
}