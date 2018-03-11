#include "project.h"
#include "header.h"

void enable()
{
	UART_Start();
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	uint8_t touche_E = 0;

	while (!touche_E)
	{
		char key = lecture_clavier();
		if (key == 'E')
		{
			touche_E = 1;
			UART_ClearTxBuffer();
			UART_ClearRxBuffer();
			UART_PutChar(key);
			char toUART[10] = {};
			snprintf(toUART,10,"\r\n ");
			UART_PutString(toUART);
			UART_ClearTxBuffer();
			UART_ClearRxBuffer();
		}
	}
}