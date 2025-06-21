#include <Adapter.hpp>

void AdapterSerialDisplay::RequestNumber(Uart &serial, Segment &display)
{
    char* ptr = serial.GetString();
    if(ptr[0] != 0){
        display.ResToNumber(ptr[0] - 48);
    }
}