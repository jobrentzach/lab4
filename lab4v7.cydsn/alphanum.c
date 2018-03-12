#include "project.h"
#include "header.h"

void alphanum()
{
	UART_Start();
	Timer_WritePeriod(100000);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	int temps = 0;
	
	uint8_t key_found = 0;
	int t= Random_ReadCounter()%30000; // Utilisation du compteur Random comme seed pour générer les nombres aléatoires
    srand(t);
	
	//uint8_t random_row = Random_ReadCounter()%4;
	//uint8_t random_col = Random_ReadCounter()%4;
	uint8_t random_row = rand() %4;
	uint8_t random_col = rand() %4;
	Random_Stop();
	Random_Init();
	Random_Start();
	
	char random_char = CLAVIER[random_row][random_col];

	uint8_t sortie = enable();
	if (sortie)
	{
		return;
	}
	
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	
	
	UART_PutChar(random_char);
	char toUART1[10] = {};
	snprintf(toUART1,10,"\r\n %c \r\n", random_char);
	UART_PutString(toUART1);

	Timer_Start();
	g_key_pressed = 0;
	
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();

	

	do
	{
		char user_char = lecture_clavier();
		if (random_char == user_char)
		{
			
			temps = (Timer_ReadPeriod() - Timer_ReadCounter()); //Le *10 a été enlevé depuis qu'il faut envoyer le random_char en format string
			key_found = 1;
		}

	} while (!temps || !key_found);
	Timer_Stop();
	Timer_Init();
	char toUART[250] = {};
	sprintf(toUART,"\r\n\n\n Votre temps de reaction pour cette seance est de : %d ms \r\n ",temps);
	UART_PutString(toUART);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	sequenceA0.temps_react[sequenceA0.compteur] = temps;
	sequenceA0.compteur +=1;
	if(sequenceA0.compteur == 7)
	{
		sequenceA0.compteur = 0;
	}
}