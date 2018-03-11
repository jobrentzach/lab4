#include "project.h"
#include "header.h"

void analog()
{
 	ADC_Start();
	ADC_StartConvert();
	
	uint8_t lecture_present = 0;
	uint8_t lecture_precedent = 0;
	int temps_reaction = 0;
	float vitesse = 0;
	int delai = 100;
	
	uint8_t lecture_cible = Random_ReadCounter()%255;
	
	char toUART[100] = {};
	snprintf(toUART,100,"%d\n",lecture_cible);
	UART_PutString(toUART);

	enable();
	
	Timer_Start();
	
	int8_t trouve = 0;
	
    do 
    {	
        if(ADC_IsEndConversion(ADC_WAIT_FOR_RESULT))
		{	
			lecture_present = ADC_GetResult8();
			vitesse = abs((lecture_precedent - lecture_present)/delai);
			snprintf(toUART,100,"%d\n",lecture_present);
			UART_PutString(toUART); 
			if(vitesse < 0.000005 && (abs(lecture_cible - lecture_present)) < 2)
			{
				Timer_Stop();
				temps_reaction = Timer_ReadPeriod() - Timer_ReadCounter();
				trouve = 1;
			}
			CyDelay(delai);
		}
		lecture_precedent = lecture_present;
		CyDelay(10); //cette valeur est utilisée afin d'optimiser l'affichage
	} while (!trouve);
	
	snprintf(toUART,100,"\n %d \r ",temps_reaction);
	UART_PutString(toUART);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
}