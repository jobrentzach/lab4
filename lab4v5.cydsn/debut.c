#include "project.h"
#include "header.h"

void debut()
{
	// Attente du départ
	enable();
	LED_Write(0);
	// Initialisation du temps de réaction
	int temps_seance_D = 0;
	
	// Génération d'un délai aléatoire inférieur ou égal à 5000ms
	int delay_D = Random_ReadCounter()%5000;
	
	CyDelay(delay_D);
	Timer_Start();
	LED_Write(!LED_Read());

	//On s'assure que le user_btn est initialisé à 0
	g_btn_pressed = 0;

	do 
	{
		if(g_btn_pressed)
		{
			Timer_Stop();
			temps_seance_D = Timer_ReadPeriod() - Timer_ReadCounter();
			LED_Write(1);
			g_btn_pressed = 0;
		}
	} while (!g_btn_pressed || !temps_seance_D);
	
	LED_Write(0);
	char toUART[100] = {};
	snprintf(toUART,100,"\r\n %3d ",temps_seance_D);
	UART_PutString(toUART);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
}