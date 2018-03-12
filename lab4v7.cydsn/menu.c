#include "project.h"
#include "header.h"

void menu(char choix)
{
	char CRNL[2] = {};
	snprintf(CRNL,2,"\r\n");

	switch(choix)
	{
		case 'C' :
		{
			UART_PutChar('C');
			UART_PutString(CRNL);
			affichage_stats();
			break;
		}
		case 'D' :
		{
			UART_PutChar('D');
			UART_PutString(CRNL);
			debut();
			break;
		}
		case 'F' :
		{
			UART_PutChar('F');
			UART_PutString(CRNL);
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
					UART_PutString(CRNL);
					analog();
					break;
				}
				case '0' :
				{
					UART_PutChar('0');
					UART_PutString(CRNL);
					alphanum();
					break;
				}
				default :
				{
					UART_PutChar('Y');
					UART_PutString(CRNL);
					break;
				}

			}
			break;
		}
		default :
		{
			UART_PutChar(choix);
			char erreur[250] = {};
			UART_ClearTxBuffer();
			snprintf(erreur,250,"\r\nErreur, choisissez une option valide. \r\n ");
			UART_PutString(erreur);
			break;
		}
	}
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
}