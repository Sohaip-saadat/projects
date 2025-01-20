#include "uart.h"
char data[100] = "data sended....!";
void main(void)
{
    uart_send_data(data);
}