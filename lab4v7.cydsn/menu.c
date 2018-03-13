#include "project.h"
#include "header.h"


void menu(char choix) // Prend en argument la valeur retournée par la lecture du clavier
{
	char CRNL[2] = {};		 // Déclaration d'un buffer permettant l'impression d'un saut et
	snprintf(CRNL,2,"\r\n"); // retour à la ligne utilisé après chaque impression (optimisation du code)

	switch(choix)
	{
		case 'C' :
		{
			UART_PutChar('C');
			UART_PutString(CRNL);
			affichage_stats(); // Appel de la fonction correspondante
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
			CyDelay(100); // Temps d'attente avant de nettoyer le buffer Tx, cette dernière commande se rend
			UART_ClearTxBuffer(); // plus rapidement au UART que l'impression, règle les problèmes d'affichage
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
				/*default :
				{
					UART_PutChar('Y'); 
					UART_PutString(CRNL);
					break;
				}*/

			}
			break;
		}
		default : // Retour d'un message d'erreur si une autre touche est appuyée
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