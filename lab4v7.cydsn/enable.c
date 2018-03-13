#include "project.h"
#include "header.h"

uint8_t enable()
{
	UART_Start();
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	

	while (1) // Lecture en boucle infinie en attendant la touche E
	{
		char key = lecture_clavier();
		if (key == 'E')
		{
			UART_PutChar(key);
			char toUART[10] = {};
			UART_PutString(toUART);
			UART_ClearTxBuffer();
			UART_ClearRxBuffer();
			CyDelay(3000); // Délai de 3 secondes afin de donner le temps à l'usager à se préparer avant le test
			return 0; 
		}
		// Fonction << Back >> incluse : dans l'attente du E pour démarrer une expérience, 
		// la touche appuyée B permet de sortir de la fonction et de revenir au menu
		else if (key == 'B') 
		{
			return 1;
		}
	}
}