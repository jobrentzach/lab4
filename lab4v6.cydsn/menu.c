#include "project.h"
#include "header.h"

void menu(char choix)
{
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
			default :
			{
				UART_PutChar('Z');
				UART_PutChar(choix);
				break;
			}
		}
}