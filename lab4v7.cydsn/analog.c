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
	sprintf(toUART1," \n La valeur cible est : %d / 100 \r \n ",lecture_cible*100/255);
	UART_PutString(toUART1);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	
	Timer_Start();
	
	int8_t trouve = 0;
	
	const double SEUIL_VITESSE = 0.000005;
	const int SEUIL_VOLTAGE = 2;
	
    do 
    {	
        if(ADC_IsEndConversion(ADC_WAIT_FOR_RESULT))
		{	
			lecture_present = ADC_GetResult8();
			vitesse = abs((lecture_precedent - lecture_present)/delai);
			sprintf(toUART1," \b \r %d / 100 ",lecture_present*100/255);	// Affichage avec une valeur sur 100
			UART_PutString(toUART1); 
			if(vitesse < SEUIL_VITESSE && (abs(lecture_cible - lecture_present)) < SEUIL_VOLTAGE)
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
	
	sequenceA1.temps_react[sequenceA1.compteur] = temps_reaction;
	if(sequenceA1.compteur == 7)
	{
		sequenceA1.compteur = 0;
	}
	sequenceA1.compteur +=1;
}