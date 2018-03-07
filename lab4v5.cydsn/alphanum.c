#include "project.h"
#include "header.h"

void alphanum()
{
	int temps = 0;
	
	uint8_t key_found = 0;
	
	uint8_t random_row = Random_ReadCounter()%4;
	uint8_t random_col = Random_ReadCounter()%4;
	char random_char = CLAVIER[random_row][random_col];

	UART_PutChar(random_char);

	enable();

	Timer_Start();
	g_key_pressed = 0;

	do
	{
		char user_char = lecture_clavier();
		if (random_char == user_char)
		{
			Timer_Stop();
			temps = Timer_ReadPeriod() - Timer_ReadCounter();
			key_found = 1;
		}

	} while (!temps || !key_found);

	char toUART[100] = {};
	snprintf(toUART,100,"%d\n ",temps);
	UART_PutString(toUART);
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
}