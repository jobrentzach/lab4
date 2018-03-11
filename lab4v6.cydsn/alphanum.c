#include "project.h"
#include "header.h"

void alphanum()
{
	UART_Start();
	Timer_WritePeriod(100000);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	int temps = 0;
	
	uint8_t key_found = 0;
	int t= Random_ReadCounter()%30000; // Utilisation du compteur Random comme seed pour générer les nombres aléatoires
    srand(t);
	
	//uint8_t random_row = Random_ReadCounter()%4;
	//uint8_t random_col = Random_ReadCounter()%4;
	uint8_t random_row = rand() %4;
	uint8_t random_col = rand() %4;
	Random_Stop();
	Random_Init();
	Random_Start();
	
	char random_char = CLAVIER[random_row][random_col];

	enable();
	
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	
	UART_PutChar(random_char);
//	char toUART1[10] = {};
//	snprintf(toUART1,10,"\r\n ");
//	UART_PutString(toUART1);

	Timer_Start();
	g_key_pressed = 0;
	
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();

	

	do
	{
		char user_char = lecture_clavier();
		if (random_char == user_char)
		{
			
			temps = (Timer_ReadPeriod() - Timer_ReadCounter())*10;
			key_found = 1;
		}

	} while (!temps || !key_found);
	Timer_Stop();
	Timer_Init();
	char toUART[100] = {};
	snprintf(toUART,100,"\r\n %d \n ",temps);
	UART_PutString(toUART);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
}