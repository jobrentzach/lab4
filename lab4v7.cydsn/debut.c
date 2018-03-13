#include "project.h"
#include "header.h"

void debut()
{
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	// Attente du départ
	LED_Write(0);
	uint8_t sortie = enable();
	if (sortie)
	{
		return;
	}
	
	Timer_WritePeriod(100000);
	int temps_seance_D = 0;
	int delay_D = Random_ReadCounter()%5000;
	
	CyDelay(delay_D);
	LED_Write(1);
	Timer_Start();

	g_btn_pressed = 0;

	do 
	{
		if(g_btn_pressed)
		{
			temps_seance_D =  Timer_ReadPeriod()- Timer_ReadCounter();
		}
	} while (!temps_seance_D);
	
	Timer_Stop();
	Timer_Init();
	LED_Write(0);
	// Impression
	char toUART[250] = {};
	sprintf(toUART,"\r\n\n\n Votre temps de reaction pour cette seance est de : %d ms \r\n ",temps_seance_D);
	UART_PutString(toUART);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	// Stockage des temps de réaction, voir fonction alphanum
	sequenceD.temps_react[sequenceD.compteur] = temps_seance_D;
	if(sequenceD.compteur == 7)
	{
		sequenceD.compteur = 0;
	}
	sequenceD.compteur +=1;
}