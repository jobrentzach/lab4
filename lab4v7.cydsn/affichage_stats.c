#include "project.h"
#include "header.h"

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
	
	
	snprintf(toUARTStat,500,"\r\n\n\n Statistiques des essais : \r\n Test Alpha-Numerique (Moyenne) : %d ms Test Alpha-Numerique (Ecart-Type) : %d ms \r\n\r\n	", mA0, stdA0);
	UART_PutString(toUARTStat);
	
	snprintf(toUARTStat,500," \r\n Test Analogue (Moyenne) : %d ms Test Analogue (Ecart-Type) : %d ms  \r\n\r\n	", mA1, stdA1);
	UART_PutString(toUARTStat);
	
	snprintf(toUARTStat,500," \r\n Test Debut (Moyenne) : %d ms  Test Debut (Ecart-Type) : %d ms \r\n\r\n	", mD, stdD);
	UART_PutString(toUARTStat);
	
	snprintf(toUARTStat,500," \r\n Test Fin (Moyenne) : %d ms Test Fin (Ecart-Type) : %d ms \r\n\r\n	", mF, stdF);
	UART_PutString(toUARTStat);
	
//	snprintf(toUARTStat,500,"\r\n\n\n Statistiques des essais : \r\n Test Alpha-Numerique (Moyenne) : %f ms Test Alpha-Numerique (Ecart-Type) : %f ms \r\n\r\n	", *statsA0[0], *statsA0[1]);
//	UART_PutString(toUARTStat);
//	
//	snprintf(toUARTStat,500," \r\n Test Analogue (Moyenne) : %f ms Test Analogue (Ecart-Type) : %f ms  \r\n\r\n	", *statsA1[0], *statsA1[1]);
//	UART_PutString(toUARTStat);
//	
//	snprintf(toUARTStat,500," \r\n Test Debut (Moyenne) : %f ms  Test Debut (Ecart-Type) : %f ms \r\n\r\n	", *statsD[0], *statsD[1]);
//	UART_PutString(toUARTStat);
//	
//	snprintf(toUARTStat,500," \r\n Test Fin (Moyenne) : %f ms Test Fin (Ecart-Type) : %f ms \r\n\r\n	", *statsF[0], *statsF[1]);
//	UART_PutString(toUARTStat);
	

	
}