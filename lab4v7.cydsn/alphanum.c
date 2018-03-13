#include "project.h"
#include "header.h"

void alphanum(void)
{
	UART_Start();
	Timer_WritePeriod(100000);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	int temps = 0; // Initialisation du temps de réaction
	
	// Utilisation du compteur de Random pour générer un seed différent à chaque appel
	// afin de générer un nombre réellement aléatoire
	int t = Random_ReadCounter()%30000; 
    srand(t);
	
	// Coordonnées de la touche aléatoire
	uint8_t random_row = rand() %4;
	uint8_t random_col = rand() %4;
	Random_Stop();
	Random_Init();
	Random_Start();
	
	char random_char = CLAVIER[random_row][random_col];
	
	// Attente du départ
	uint8_t sortie = enable();
	
	// Valeur de sortie dépend de la touche E ou B
	if (sortie) // B a été appuyé
	{
		return; // Sortie de la fonction et retour au menu
	}
	
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	char toUART1[100] = {};
	snprintf(toUART1,100," \r\n Appuyez sur %c \r\n", random_char);
	UART_PutString(toUART1);
	UART_PutChar(random_char);

	Timer_Start();
	g_key_pressed = 0; 
	
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();

	uint8_t key_found = 0; // Flag permettant de sortir de la boucle
	do
	{
		char user_char = lecture_clavier();
		if (random_char == user_char)
		{
			temps = (Timer_ReadPeriod() - Timer_ReadCounter()); 
			key_found = 1;
		}
	} while (!temps || !key_found);
	Timer_Stop();
	Timer_Init();
	
	//Impression
	char toUART[250] = {};
	sprintf(toUART,"\r\n\n\n Votre temps de reaction pour cette seance est de : %d ms \r\n ",temps);
	UART_PutString(toUART);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	//Stockage des temps de réaction dans le vecteur volatile correspondant
	sequenceA0.temps_react[sequenceA0.compteur] = temps;
	if(sequenceA0.compteur == 7)
	{
		sequenceA0.compteur = 0;	// Réinitialisation du compteur, permet de faire plus que 8 essais  
	}								// et de compiler les statistiques tout de même
	sequenceA0.compteur +=1;
}