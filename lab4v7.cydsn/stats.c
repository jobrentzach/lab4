#include "project.h"
#include "header.h"

int moyenne(volatile int length, volatile int a[8])
{
	int somme = 0;
	int mean = 0;
	
	for (int i =0; i < length; i++)
	{
		somme += a[i];
	}
	
	mean = somme/length;
	
	return mean;
}

int ecart(volatile int length, volatile int a[8])
{	
	double mean = (double) moyenne(length, a);
	double sq_sum = 0;
	
	for (int i = 0; i  < length; ++i)
	{
		sq_sum += a[i]*a[i];
	}
	double variance = sq_sum/length - mean*mean;
	double std = sqrt(variance);
	
	return (int) std;
}

void affichage_stats()
{
	uint8_t sortie = enable();
	if (sortie)
	{
		return;
	}

	int mA0 = moyenne(sequenceA0.compteur, sequenceA0.temps_react);
	int stdA0 = ecart(sequenceA0.compteur, sequenceA0.temps_react);
	int mA1 = moyenne(sequenceA1.compteur, sequenceA1.temps_react);
	int stdA1 = ecart(sequenceA1.compteur, sequenceA1.temps_react);
	int mD = moyenne(sequenceD.compteur, sequenceD.temps_react);
	int stdD = ecart(sequenceD.compteur, sequenceD.temps_react);
	int mF = moyenne(sequenceF.compteur, sequenceF.temps_react);
	int stdF = ecart(sequenceF.compteur, sequenceF.temps_react);
	
	UART_Start();
	UART_ClearRxBuffer();
	UART_ClearTxBuffer();
	
	char toUARTStat[500] = {};
	
	snprintf(toUARTStat,500," \r\n\n\n Statistiques des essais : \r\n\n");
	UART_PutString(toUARTStat);
	
	snprintf(toUARTStat,500," Test ALPHANUMERIQUE \r\n\t Moyenne : %d ms \r\n\t Ecart-type : %d ms \r\n", mA0, stdA0);
	UART_PutString(toUARTStat);
	
	snprintf(toUARTStat,500," Test ANALOGUE \r\n\t Moyenne : %d ms \r\n\t Ecart-type : %d ms \r\n", mA1, stdA1);
	UART_PutString(toUARTStat);
	
	snprintf(toUARTStat,500," Test DEBUT \r\n\t Moyenne : %d ms \r\n\t Ecart-type : %d ms \r\n", mD, stdD);
	UART_PutString(toUARTStat);
	
	snprintf(toUARTStat,500," Test FIN \r\n\t Moyenne : %d ms \r\n\t Ecart-type : %d ms \r\n\r\n", mF, stdF);
	UART_PutString(toUARTStat);
}