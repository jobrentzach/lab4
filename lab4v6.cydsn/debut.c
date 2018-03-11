#include "project.h"
#include "header.h"

void debut()
{
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	// Attente du départ
	LED_Write(0);
	enable();

	// Initialisation du temps de réaction
	int temps_seance_D = 0;
	
	// Génération d'un délai aléatoire inférieur ou égal à 5000ms
	int delay_D = Random_ReadCounter()%5000;
	
	CyDelay(delay_D);
	LED_Write(1);
	Timer_Init();
	Timer_Start();
	
	//On s'assure que le user_btn est initialisé à 0
	g_btn_pressed = 0;

	do 
	{
		if(g_btn_pressed)
		{
			temps_seance_D =  Timer_ReadPeriod()- Timer_ReadCounter();
		}
	} while (!temps_seance_D);
	
	Timer_Stop();
	LED_Write(0);
	char toUART[10] = {};
	sprintf(toUART,"\r\n %d \r\n ",temps_seance_D);
	UART_PutString(toUART);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
}