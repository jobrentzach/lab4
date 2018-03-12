#include "project.h"
#include "header.h"

uint8_t enable()
{
	UART_Start();
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	

	while (1)
	{
		char key = lecture_clavier();
		if (key == 'E')
		{
			UART_PutChar(key);
			char toUART[10] = {};
			UART_PutString(toUART);
			UART_ClearTxBuffer();
			UART_ClearRxBuffer();
			return 0;
		}
		else if (key == 'B')
		{
			return 1;
		}
	}
}