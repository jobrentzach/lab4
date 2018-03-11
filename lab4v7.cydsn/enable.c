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
			
			UART_ClearTxBuffer();
			UART_ClearRxBuffer();
			UART_PutChar(key);
			char toUART[10] = {};
			snprintf(toUART,10,"\t\r\n\t ");
			UART_PutString(toUART);
			UART_ClearTxBuffer();
			UART_ClearRxBuffer();
			return 0;
		}
		else if (key == 'B')
		{
			// Envoyer en UART à MATLAB qu'on sort pour qu'il aille au menu lui aussi.
			return 1;
		}
	}
}