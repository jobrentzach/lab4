#include "project.h"
#include "header.h"

void fin()
{
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	// Attente du départ
	
	uint8_t sortie = enable();
	if (sortie)
	{
		return;
	}
	Timer_WritePeriod(100000);
	int temps_seance_F = 0;
	int delayF = Random_ReadCounter()%10000;
	CyDelay(1000);
	LED_Write(1);
	CyDelay(delayF);
	LED_Write(0);
	Timer_Start();
	g_btn_pressed = 0;
	
	do 
	{
		if(g_btn_pressed)
		{	
			temps_seance_F = (Timer_ReadPeriod()- Timer_ReadCounter());
		
		}
	} while (!temps_seance_F);
	Timer_Stop();
	Timer_Init();
	char toUART[250] = {};
	sprintf(toUART,"\r\n\n\n Votre temps de reaction pour cette seance est de : %d ms \r\n ",temps_seance_F);
	UART_PutString(toUART);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	sequenceF.temps_react[sequenceF.compteur] = temps_seance_F;
	if(sequenceF.compteur == 7)
	{
		sequenceF.compteur = 0;
	}
	sequenceF.compteur +=1;
}