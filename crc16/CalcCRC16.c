#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define CRC16 0x8005

uint16_t crc16(const char *data, uint16_t size)
{
    uint16_t out = 0;
    int bits_read = 0, bit_flag;

    /* Sanity check: */
    if (data == NULL)
        return 0;

    while (size > 0)
    {
        bit_flag = out >> 15;

        /* Get next bit: */
        out <<= 1;
        out |= (*data >> bits_read) & 1; // item a) work from the least significant bits

        /* Increment bit counter: */
        bits_read++;
        if (bits_read > 7)
        {
            bits_read = 0;
            data++;
            size--;
        }

        /* Cycle check: */
        if (bit_flag)
            out ^= CRC16;
    }

    // item b) "push out" the last 16 bits
    int i;
    for (i = 0; i < 16; ++i)
    {
        bit_flag = out >> 15;
        out <<= 1;
        if (bit_flag)
            out ^= CRC16;
    }

    // item c) reverse the bits
    uint16_t crc = 0;
    i = 0x8000;
    int j = 0x0001;
    for (; i != 0; i >>= 1, j <<= 1)
    {
        if (i & out)
            crc |= j;
    }

    return crc;
}

int main()
{
    char *buffer = "0000";
    char text[] = "Test Message";

    uint16_t result = crc16(text, strlen(text));

    uint8_t crc[2];
    crc[0] = result & 0x0f;
    crc[1] = result >> 0x0f;

    printf("%d %d", crc[1], crc[0]);

    return 0;
}
