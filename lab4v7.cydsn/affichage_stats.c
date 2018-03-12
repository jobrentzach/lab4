#include "project.h"
#include "header.h"

void affichage_stats()
{
	double *statsA0[2];
	double *statsA1[2];
	double *statsD[2]; 
	double *statsF[2]; 
	*statsA0 = stats(secanceA0.compteur, secanceA0.temps_react);
	*statsA1 = stats(secanceA1.compteur, secanceA1.temps_react);
	*statsD = stats(secanceD.compteur, secanceD.temps_react);
	*statsF = stats(secanceF.compteur, secanceF.temps_react);
	
	UART_Start();
	UART_ClearRxBuffer();
	UART_ClearTxBuffer();
	
	char toUARTStat[500] = {};
	snprintf(toUARTStat,500,"\r\n\n\n Statistiques des essais : \r\n Test Alpha-Numerique (Moyenne) : %f ms Test Alpha-Numerique (Ecart-Type) : %f ms \r\n\r\n	", *statsA0[0],*statsA0[1]);
	UART_PutString(toUARTStat);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	snprintf(toUARTStat,500," \r\n Test Analogue (Moyenne) : %f ms Test Analogue (Ecart-Type) : %f ms  \r\n\r\n	", *statsA1[0],*statsA1[1]);
	UART_PutString(toUARTStat);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	snprintf(toUARTStat,500," \r\n Test Debut (Moyenne) : %f ms  Test Debut (Ecart-Type) : %f ms \r\n\r\n	", *statsD[0],*statsD[1]);
	UART_PutString(toUARTStat);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	snprintf(toUARTStat,500," \r\n Test Fin (Moyenne) : %f ms Test Fin (Ecart-Type) : %f ms \r\n\r\n	", *statsF[0],*statsF[1]);
	UART_PutString(toUARTStat);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	
}