#include "project.h"
#include "header.h"

void menu(char choix)
{
	UART_Start();
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	switch(choix)
		{
			case 'D' :
			{
				
				UART_PutChar('D');
				UART_ClearTxBuffer();
				UART_ClearRxBuffer();
				debut();
				break;
			}
			case 'F' :
			{
				
				UART_PutChar('F');
				UART_ClearTxBuffer();
				UART_ClearRxBuffer();
				fin();
				break;
			}
			case 'A' :
			{
				
				UART_PutChar('A');
				char toUART[10] = {};
				snprintf(toUART,10,"\r\n\t ");
				UART_PutString(toUART);
				UART_ClearTxBuffer();
				UART_ClearRxBuffer();
				
				char alpha_analog = lecture_clavier();
				switch(alpha_analog)
				{
					case '1' :
					{
						
						UART_PutChar('1');
						char toUART[10] = {};
						snprintf(toUART,10,"\r\n ");
						UART_PutString(toUART);
						UART_ClearTxBuffer();
						UART_ClearRxBuffer();
						analog();
						break;
					}
					case '0' :
					{
						
						UART_PutChar('0');
						char toUART[10] = {};
						snprintf(toUART,10,"\r\n\t ");
						UART_PutString(toUART);
						UART_ClearTxBuffer();
						UART_ClearRxBuffer();
						alphanum();
						break;
					}
					default :
					{
						
						UART_PutChar('Y');
						//UART_PutChar(choix);
						char toUART[10] = {};
						snprintf(toUART,10,"\r\n ");
						UART_PutString(toUART);
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
			
				UART_PutChar('Z');
				//UART_PutChar(choix);
				char toUART[10] = {};
				snprintf(toUART,10,"\r\n ");
				UART_PutString(toUART);
				UART_ClearTxBuffer();
				UART_ClearRxBuffer();
				break;
			}
		}
		UART_ClearTxBuffer();
		UART_ClearRxBuffer();
}