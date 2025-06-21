#ifndef _ADAPTER_H
#define _ADAPTER_H

#include <Uart.hpp>
#include <Seg.hpp>

class AdapterSerialDisplay
{
    private:
    public:
        void RequestNumber(Uart &serial, Segment &display);
};

#endif // !_ADAPTER_H
