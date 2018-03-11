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
	
	char toUART[10] = {};
	sprintf(toUART,"\n\r %d\n\r",lecture_cible);
	UART_PutString(toUART);

	uint8_t sortie = enable();
	if (sortie)
	{
		return;
	}
	
	Timer_Start();
	Timer_WritePeriod(100000);
	int8_t trouve = 0;
	
    do 
    {	
        if(ADC_IsEndConversion(ADC_WAIT_FOR_RESULT))
		{	
			lecture_present = ADC_GetResult8();
			vitesse = abs((lecture_precedent - lecture_present)/delai);
			sprintf(toUART,"\n\r %d\n\r",lecture_present);
			UART_PutString(toUART); 
			if(vitesse < 0.000005 && (abs(lecture_cible - lecture_present)) < 2)
			{
				Timer_Stop();
				temps_reaction = (Timer_ReadPeriod() - Timer_ReadCounter())*100; //a revoir le fois 100
				trouve = 1;
			}
			CyDelay(delai);
		}
		lecture_precedent = lecture_present;
		CyDelay(10); //cette valeur est utilisée afin d'optimiser l'affichage
	} while (!trouve);
	
	sprintf(toUART,"\n\r %d\n\r",temps_reaction);
	UART_PutString(toUART);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
}