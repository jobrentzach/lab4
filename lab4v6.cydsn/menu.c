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
				UART_PutChar('D');
				debut();
				break;
			}
			case 'F' :
			{
				UART_PutChar('F');
				fin();
				break;
			}
			case 'A' :
			{
				UART_PutChar('A');
				UART_ClearTxBuffer();
				UART_ClearRxBuffer();
				char alpha_analog = lecture_clavier();
				switch(alpha_analog)
				{
					case '1' :
					{
						UART_PutChar('1');
						analog();
						break;
					}
					case '0' :
					{
						UART_PutChar('0');
						alphanum();
						break;
					}
					default :
					{
						UART_PutChar('Y');
						UART_PutChar(choix);
						break;
					}

				}
				break;
			}
			UART_ClearTxBuffer();
			UART_ClearRxBuffer();
			default :
			{
				UART_PutChar('Z');
				UART_PutChar(choix);
				break;
			}
		}
}