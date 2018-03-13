#include "project.h"
#include "header.h"

void analog()
{
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
	
	int t= Random_ReadCounter()%30000;	// Utilisation du compteur Random comme seed pour générer les nombres aléatoires
    srand(t);							// voir fonction alphanum
	uint8_t lecture_cible = rand() %255; // Valeur aléatoire entre 0 et 255 (sur 8 bits)
	Random_Stop();
	Random_Init();
	Random_Start();
	char toUART1[100] = {};
	sprintf(toUART1," \r\n La valeur cible est : %d / 100 \r \n ",lecture_cible*100/255); // Remise de la valeur aléatoire en %
	UART_PutString(toUART1);
	
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	Timer_Start();
	
	int8_t trouve = 0; // Initialisation d'un flag pour sortir de la boucle
	
	const double SEUIL_VITESSE = 0.000005; // Condition de sortie 
	const int SEUIL_VOLTAGE = 2; // Tolérance de +/- 2 sur 255

	UART_PutChar('\n');
    do 
    {	
        if(ADC_IsEndConversion(ADC_WAIT_FOR_RESULT)) // Attendre que l'ADC ait fini la conversion analogique-numérique avant de traiter les données
		{	
			lecture_present = ADC_GetResult8();
			vitesse = abs((lecture_precedent - lecture_present)/delai);
			sprintf(toUART1," \b \r %d / 100 ",lecture_present*100/255);	// Affichage avec une valeur sur 100
			UART_PutString(toUART1); 
			if(vitesse < SEUIL_VITESSE && (abs(lecture_cible - lecture_present)) < SEUIL_VOLTAGE) // Conditions temps de réaction
			{
				temps_reaction = (Timer_ReadPeriod() - Timer_ReadCounter());
				trouve = 1; // Flag de sortie
			}
			CyDelay(delai); // Améliore l'affichage
		}
		lecture_precedent = lecture_present; // On remplace les valeurs de lectures pour mettre à jour les vitesse et les seuils
		CyDelay(10);	// Cette valeur est utilisée afin d'optimiser l'affichage
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
	
	// Stockage des valeurs de temps de réaction, voir alphanum
	sequenceA1.temps_react[sequenceA1.compteur] = temps_reaction;
	if(sequenceA1.compteur == 7)
	{
		sequenceA1.compteur = 0;
	}
	sequenceA1.compteur +=1;

	ADC_Stop();
}