#include "uart.h"

#define UARTDR *((volatile unsigned int *)(unsigned int)0x101f1000)

void uart_send_data(unsigned char *ptx_data)
{
    while (*ptx_data != '\0')
    {
        UARTDR = (unsigned int)(*ptx_data);
        ptx_data++;
    }
}