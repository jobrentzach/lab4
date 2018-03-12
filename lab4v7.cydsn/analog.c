#include "project.h"
#include "header.h"

void analog()
{
	UART_Start();
	Timer_WritePeriod(100000);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
 	ADC_Start();
	ADC_StartConvert();
	
	uint8_t lecture_present = 0;
	uint8_t lecture_precedent = 0;
	int temps_reaction = 0;
	float vitesse = 0;
	int delai = 100;
	
	uint8_t sortie = enable();
	
	if (sortie)
	{
		return;
	}
	
	int t= Random_ReadCounter()%30000; // Utilisation du compteur Random comme seed pour générer les nombres aléatoires
    srand(t);
	uint8_t lecture_cible = rand() %255;
	Random_Stop();
	Random_Init();
	Random_Start();
	char toUART1[100] = {};
	sprintf(toUART1," \n La valeur cible est : %d  \r \n ",lecture_cible);
	UART_PutString(toUART1);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	
	Timer_Start();
	
	int8_t trouve = 0;
	
	//char toUART2[50] = {};
    do 
    {	
        if(ADC_IsEndConversion(ADC_WAIT_FOR_RESULT))
		{	
			lecture_present = ADC_GetResult8();
			vitesse = abs((lecture_precedent - lecture_present)/delai);
			sprintf(toUART1," \b \r %d ",lecture_present);
			UART_PutString(toUART1); 
			if(vitesse < 0.000005 && (abs(lecture_cible - lecture_present)) < 2)
			{
				
				temps_reaction = (Timer_ReadPeriod() - Timer_ReadCounter());//*100; //a revoir le fois 100
				trouve = 1;
			}
			CyDelay(delai);
		}
		lecture_precedent = lecture_present;
		CyDelay(10); //cette valeur est utilisée afin d'optimiser l'affichage
	} while (!trouve);
	Timer_Stop();
	Timer_Init();
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	char toUART[50] = {};
	sprintf(toUART,"\n\r\n\n Votre temps de reaction pour cette seance est de : %d ms \n\r ", temps_reaction);
	UART_PutString(toUART);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	secanceA1.temps_react[secanceA1.compteur] = temps_reaction;
	secanceA1.compteur +=1;
	if(secanceA1.compteur == 7)
	{
		secanceA1.compteur = 0;
	}
}