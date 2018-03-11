#include "project.h"
#include "header.h"

void menu(char choix)
{
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	switch(choix)
		{
			case 'D' :
			{
				UART_ClearTxBuffer();
				UART_ClearRxBuffer();
				UART_PutChar('D');
				debut();
				break;
			}
			case 'F' :
			{
				UART_ClearTxBuffer();
				UART_ClearRxBuffer();
				UART_PutChar('F');
				fin();
				break;
			}
			case 'A' :
			{
				UART_ClearTxBuffer();
				UART_ClearRxBuffer();
				UART_PutChar('A');
				char alpha_analog = lecture_clavier();
				switch(alpha_analog)
				{
					case '1' :
					{
						UART_ClearTxBuffer();
						UART_ClearRxBuffer();
						UART_PutChar('1');
						UART_ClearTxBuffer();
						UART_ClearRxBuffer();
						analog();
						break;
					}
					case '0' :
					{
						UART_ClearTxBuffer();
						UART_ClearRxBuffer();
						UART_PutChar('0');
						UART_ClearTxBuffer();
						UART_ClearRxBuffer();
						alphanum();
						break;
					}
					default :
					{
						UART_ClearTxBuffer();
						UART_ClearRxBuffer();
						UART_PutChar('Y');
						UART_PutChar(choix);
						UART_ClearTxBuffer();
						UART_ClearRxBuffer();
						break;
					}

				}
				break;
			}
			UART_ClearTxBuffer();
			UART_ClearRxBuffer();
			default :
			{
				UART_ClearTxBuffer();
				UART_ClearRxBuffer();
				UART_PutChar('Z');
				UART_PutChar(choix);
				UART_ClearTxBuffer();
				UART_ClearRxBuffer();
				break;
			}
		}
}