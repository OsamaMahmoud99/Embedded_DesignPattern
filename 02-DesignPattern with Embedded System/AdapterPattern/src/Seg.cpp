#include <Seg.hpp>

void Segment::ResToNumber(int number)
{
    WRITE_PORT(SEG_DIR , 0xFF);

    static unsigned char SEG_DataNumber[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

    WRITE_PORT(SEG_VALUE, SEG_DataNumber[number]);
}