/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *3
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
const int str_len = 100;

volatile int lecture_present = 0;
volatile int lecture_precedent = 0;
const float INTERVALLE = 0.0001;		// Période clock interruption
volatile float vitesse = 0;

// TODO: Seuils à ajuster
const int seuil_vitesse = 200000;		// (10/0.0001) * 2
const int seuil_valeur = 100;			// Valeur choisie pour les bornes

CY_ISR(lecture_ISR_handler){
	// On assume que l'ADC roule assez vite pour ne pas avoir à vérifier que la conversion.
	lecture_present = ADC_GetResult16();
	
	vitesse = (float)(lecture_present - lecture_precedent)/INTERVALLE;
	
	// Écrase la valeur pour la prochaine interruption
	lecture_precedent = lecture_present;
}



int main(void)
{
	CyGlobalIntEnable;
	
	lecture_ISR_StartEx(lecture_ISR_handler);
	
	UART_Start();
	UART_ClearTxBuffer();
//	char toUART[str_len] = {};
//	snprintf(toUART, str_len, "UART START\n\r");
//	UART_PutString(toUART);
	
	ADC_Start();
	ADC_StartConvert();
	time_t t;
	srand((unsigned) time(&t));
	int val_aleatoire = rand() % 4096;
	char toUART[str_len];
	snprintf(toUART, str_len, "%d\n\r",val_aleatoire);
	UART_PutString(toUART);
	Timer_Start();
	for(;;)
	{
		if (fabsf(vitesse) < seuil_vitesse && (val_aleatoire - seuil_valeur) < lecture_present < (val_aleatoire + seuil_valeur))
		{
			Timer_Stop();
			int temps = Timer_ReadPeriod() - Timer_ReadCounter();
			char toUART2[str_len];
			snprintf(toUART2, str_len, "%d\n",temps);
			UART_PutString(toUART2);
		}
	}
}


/*

	int lecture_passee = 0;
		CyDelay(200);
		if (ADC_IsEndConversion(ADC_WAIT_FOR_RESULT))
		{
		    
		    
		    int16_t lectureADC = ADC_GetResult16();
		    int lecture_presente = lectureADC;
		    float voltage  = (float)lectureADC * (float)5/(float)4095;
		    int cx;
		    cx = snprintf(toUART, str_len, "%d\n\r", lectureADC);
		    if (cx>=0 && cx<str_len){
		        UART_PutString(toUART);
		    }
		    int temps;
		    int diff = lecture_passee - lecture_presente;
		    int vitesse = abs(diff)/temps;
		    
		 
		}
	while (1)
	{
	    if(vitesse >= limite && )
	    {
	    	int cx;
	    	cx = snprintf(toUART, str_len, "%d\n\r", lectureADC);
	    	if (cx>=0 && cx<str_len){
				UART_PutString(toUART);}
	    	for (int i = 1, i < 21, i++)
	    	{
	    		if (lectureADC >= 205 *(i-1) && lectureADC < 205*i)
	    	    {
	    			UART_PutChar('X');
	    		}
	    		else
	    		{
					UART_PutChar(' ');
	    		}
	    	}
	    }
	} */