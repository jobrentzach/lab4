/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
volatile uint8_t g_btn_pressed = 0;
volatile int temps;

CY_ISR_PROTO(ISR_user_btn_Handler);
void Debut();
void Fin();


// TEST


int main(void)
{
    CyGlobalIntEnable; 
	
	ISR_user_btn_StartEx(ISR_user_btn_Handler);
    time_t t;
	srand((unsigned) time(&t));
	Random_Start();
	UART_Start();
	//char choix;
	//int Alpha_Analog;
	Clock2_Start();
	Clock1_Start();
	
	/*
	char toUART_Begin[200];
    sprintf(toUART_Begin,"\n Please choose D for Debut, F for Fin or A for AlphaNum/Analog : \t\r ");
    UART_PutString(toUART_Begin);
	UART_ClearRxBuffer();
	UART_ClearTxBuffer();
	*/
	
    for(;;)
    {
		
		UART_ClearTxBuffer();
    	UART_ClearRxBuffer();
		
		Debut();
		//Fin();
		UART_ClearTxBuffer();
    	UART_ClearRxBuffer();
		
		
    }
}


CY_ISR(ISR_user_btn_Handler)
{
    g_btn_pressed = 1;
    user_btn_ClearInterrupt();
}

/*
void Debut() : Fonction permettant de calculer le temps de réaction dont le stimuli 
est une LED qui s'allume après un temps aléatoire pendant un intervalle de 200ms 
*/
void Debut() 
{
	// Initialisation du temps de réaction
	int temps_seance_D =0;
	
	// Génération d'un délai aléatoire inférieur ou égal à 5000ms
	uint delay_D = Random_ReadCounter()%5000;
	
	CyDelay(delay_D);
	Timer_Start();
	LED_Write(!LED_Read());
	CyDelay(200);
	LED_Write(!LED_Read());
	
	//On s'assure que le user_btn est initialisé à 0
	g_btn_pressed = 0;
	while(!g_btn_pressed || !temps_seance_D)
	{
		if(g_btn_pressed)
		{
			temps_seance_D = Timer_ReadPeriod() - Timer_ReadCounter();	
		}
	} 
	g_btn_pressed = 0;
	Timer_Stop();
	Timer_Init();
	char toUART[200] ={};
	if (temps_seance_D)
	{
		snprintf(toUART,200,"\n %d \r",temps_seance_D);
		UART_PutString(toUART);
		UART_ClearTxBuffer();
	    UART_ClearRxBuffer();
	}
}

void Fin()
{
	
	int temps_seanceF = 0;
	int delayF = Random_ReadCounter()%10000;
	CyDelay(1000);
	LED_Write(!LED_Read());
	CyDelay(delayF);
	Timer_Start();
	LED_Write(!LED_Read());
	g_btn_pressed = 0;
	while(!g_btn_pressed || !temps_seanceF)
	{
		if(g_btn_pressed)
		{
			temps_seanceF = Timer_ReadPeriod() - Timer_ReadCounter();
			
		}
	}
	Timer_Stop();
	Timer_Init();
	g_btn_pressed = 0;
	if(temps_seanceF)
	{
		UART_ClearTxBuffer();
	    UART_ClearRxBuffer();
		char toUARTFin[200] = {};
		snprintf(toUARTFin,100,"\n %d \r ",temps_seanceF);
		UART_PutString(toUARTFin);
	}
}
