#include "project.h"
#include "header.h"

void fin()
{
	// Attente du départ
	enable();

	int temps_seance_F = 0;
	int delayF = Random_ReadCounter()%10000;
	CyDelay(1000);
	LED_Write(!LED_Read());
	CyDelay(delayF);
	Timer_Start();
	LED_Write(!LED_Read());
	g_btn_pressed = 0;
	
	do 
	{
		if(g_btn_pressed)
		{
			Timer_Stop();
			temps_seance_F = Timer_ReadPeriod() - Timer_ReadCounter();
			g_btn_pressed = 0;
			
		}
	} while (!g_btn_pressed || !temps_seance_F);
	
	char toUART[100] = {};
	snprintf(toUART,100,"%d\n",temps_seance_F);
	UART_PutString(toUART);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
}