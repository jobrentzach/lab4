/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
volatile uint8_t interrupteur = 0;
volatile int temps;

CY_ISR_PROTO(Interrupt_UserBTN_Routine);
void Debut();
void Fin();
int main(void)
{
    CyGlobalIntEnable; 
	
	B_Interrupt_StartEx(Interrupt_UserBTN_Routine);
    time_t t;
	srand((unsigned) time(&t));
	Random_Start();
	UART_Start();
	char choix;
	int Alpha_Analog;
	
	
	char toUART_Begin[200];
    sprintf(toUART_Begin,"\n Please choose D for Debut, F for Fin or A for AlphaNum/Analog : \t\r ");
    UART_PutString(toUART_Begin);
	UART_ClearRxBuffer();
	UART_ClearTxBuffer();
	
    for(;;)
    {
        // Lecture du clavier
		// if(lectureClavier)
		
		//choix = LectureClavier;
		switch(choix)
		{
			case 'D' :
			{
				UART_PutChar('D');
				Debut();
				UART_ClearRxBuffer();
				UART_ClearTxBuffer();
				break;
			}
			case 'F' :
			{
				UART_PutChar('F');
				Fin();
				UART_ClearRxBuffer();
				UART_ClearTxBuffer();
				break;
			}
			case 'A' :
			{
				UART_PutChar('A');
				UART_ClearRxBuffer();
				UART_ClearTxBuffer();
				//Alpha_Analog = LecureClavier;
				if(Alpha_Analog == '1')
				{
					//Analog();
					UART_ClearRxBuffer();
					UART_ClearTxBuffer();
					break;
				}
				else if (Alpha_Analog == '0')
				{
					//AlphaNum();
					UART_ClearRxBuffer();
					UART_ClearTxBuffer();
					break;
				}
				else
				{
					UART_PutChar('X');
					break;
				}
			}
			default :
			{
				UART_ClearRxBuffer();
				UART_ClearTxBuffer();
				char toUART_Error2[100];
    			sprintf(toUART_Error2,"\n Please try again and select D, F or A \t\r ");
    			UART_PutString(toUART_Error2);
				UART_ClearRxBuffer();
				UART_ClearTxBuffer();
				break;
			}
		}
    }
}


CY_ISR(Interrupt_UserBTN_Routine)
{
    interrupteur = 1;
    UserButton_ClearInterrupt();
}

void Debut(){
	int tempsSeanceD;
	interrupteur = 0;
	int delayD = Random_ReadCounter()%5000;
	CyDelay(delayD);
	LED_Write(!LED_Read());
	Timer_Start();
	CyDelay(200);
	LED_Write(!LED_Read());
	while(!interrupteur)
	{
		if(interrupteur)
		{
			tempsSeanceD = Timer_ReadPeriod() - Timer_ReadCounter();
			Timer_Stop();
			interrupteur = 0;
		}
	}
	UART_ClearTxBuffer();
    UART_ClearRxBuffer();
	char toUARTDebut[100];
	snprintf(toUARTDebut,100,"%d\n",tempsSeanceD);
	UART_PutString(toUARTDebut);
}

void Fin(){
	
	int tempsSeanceF;
	interrupteur = 0;
	int delayF = Random_ReadCounter()%10000;
	CyDelay(1000);
	LED_Write(!LED_Read());
	CyDelay(delayF);
	LED_Write(!LED_Read());
	Timer_Start();
	while(!interrupteur)
	{
		if(interrupteur)
		{
			tempsSeanceF = Timer_ReadPeriod() - Timer_ReadCounter();
			Timer_Stop();
			interrupteur = 0;
		}
		
	}
	UART_ClearTxBuffer();
    UART_ClearRxBuffer();
	char toUARTFin[100];
	snprintf(toUARTFin,100,"%d\n",tempsSeanceF);
	UART_PutString(toUARTFin);
}
