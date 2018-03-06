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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

	ADC_Start();
	ADC_StartConvert();
	UART_Start();
	Random_Start();//à enlever 
	uint8_t lecture_present = 0;
	uint8_t lecture_precedent = 0;
	float vitesse = 0;
	int delai = 100;
	//Random_ReadCounter()%255;
	uint8_t lecture_cible = 150;
	char phrase[40] = {};
	sprintf(phrase,"\r La valeur cible est: %d \n",lecture_cible);
	UART_PutString(phrase);
	
	Timer_Start();
    for(;;)
    {	
		
        if(ADC_IsEndConversion(ADC_WAIT_FOR_RESULT))
		{	
			lecture_present = ADC_GetResult8();
			vitesse = abs((lecture_precedent - lecture_present)/delai);
			sprintf(phrase,"\b \r %d",lecture_present);
			UART_PutString(phrase); 
			if(vitesse < 0.000005 && (abs(lecture_cible - lecture_present)) < 2)
			{
				int temps_reaction = Timer_ReadPeriod() - Timer_ReadCounter();
				Timer_Stop();
				sprintf(phrase,"\n Bravo! Votre temps est de: %d ms \n", temps_reaction);
				UART_PutString(phrase);
				break;
			}
			CyDelay(delai);				
				
		}
			lecture_precedent = lecture_present;
			CyDelay(10); //cette valeur est utilisée afin d'optimiser l'affichage
	}

}

/* [] END OF FILE */
