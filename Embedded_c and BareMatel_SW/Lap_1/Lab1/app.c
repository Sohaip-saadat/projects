#include "uart.h"

unsigned char string[100] = " Learn-in-depth: Sohaip Saadat";
void main()
{
	UART_send_string(&string);
}