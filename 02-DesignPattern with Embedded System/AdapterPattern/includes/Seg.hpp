#ifndef SEG_H
#define SEG_H

#include <Utils.hpp>
#include <STD_Types.hpp>
#include "avr/io.h"

#define SEG_DIR DDRB
#define SEG_VALUE PORTB

class Segment
{
    private:

    public:
        void ResToNumber(int number);
};

#endif