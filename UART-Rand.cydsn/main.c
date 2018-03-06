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
volatile uint8_t interrupteur;
volatile int temps;

CY_ISR(C_Routine)
{
    
    interrupteur = 1;
    C_ClearInterrupt();
}

    
int main(void)
{
//==============
    //Variable for storing rx data:
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    CyGlobalIntEnable;
    UART_Start(); 
    char matrix[4][4] =  {{'1','2','3','A'}, {'4','5','6','B'}, {'7','8','9','C'}, {'0','F','E','D'}}; 
    
    Clock_1_Start();
    
     
     C_interrupt_StartEx(C_Routine);
     R1_SetDriveMode(R1_DM_STRONG);
     R2_SetDriveMode(R2_DM_STRONG);
     R3_SetDriveMode(R3_DM_STRONG);
     R4_SetDriveMode(R4_DM_STRONG);
     char randomValue;
    
     UART_ClearTxBuffer();
     UART_ClearRxBuffer();
     
     int trouve = 1;
    
    /*CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        int t= Timer_ReadCounter()%30000;
        srand(t);
        if(trouve)
        {
        uint8_t randomRow = rand() %4;
        uint8_t randomColumn = rand()%4;
        randomValue = matrix[randomRow][randomColumn];
        UART_ClearTxBuffer();
        UART_ClearRxBuffer();
        char tofind[50];
        sprintf(tofind,"\n Digit to press: %c \t ", randomValue);
        UART_PutString(tofind);
        Timer_Start();
        trouve = 0;
        }
        
        if(interrupteur)
        {
			temps = Timer_ReadCounter();
            char boutonPressed;
    
            uint8_t boutonC1 =15;
            uint8_t boutonC2 =15;
            uint8_t boutonC3 =15;
            uint8_t boutonC4 =15;
			R1_SetDriveMode(R1_DM_STRONG);
        	R2_SetDriveMode(R2_DM_DIG_HIZ);
        	R3_SetDriveMode(R3_DM_DIG_HIZ);
        	R4_SetDriveMode(R4_DM_DIG_HIZ);
			boutonC1 = Status_Colonne_Read();
			R1_SetDriveMode(R1_DM_DIG_HIZ);
       		R2_SetDriveMode(R2_DM_STRONG);
            boutonC2 = Status_Colonne_Read();
			R2_SetDriveMode(R2_DM_DIG_HIZ);
        	R3_SetDriveMode(R3_DM_STRONG);
            boutonC3 = Status_Colonne_Read();
			R3_SetDriveMode(R3_DM_DIG_HIZ);
        	R4_SetDriveMode(R4_DM_STRONG);
            boutonC4 = Status_Colonne_Read();
            interrupteur = 0;
            uint8_t RowVector[4] = {boutonC1, boutonC2, boutonC3,boutonC4};
        
            for(uint8_t i = 0; i < 4; i++)
            {
				UART_ClearTxBuffer();
                if (RowVector[i] != 15)
                {
                    if (RowVector[i] == 14)  //1110
                    {
                        boutonPressed = matrix[i][3];
                        
                        UART_PutChar(boutonPressed);
                        CyDelay(200);
                    }
                    else if (RowVector[i] == 13) // 1101
                    {
                        boutonPressed = matrix[i][2];
                        
                        UART_PutChar(boutonPressed);
                        CyDelay(200);
                    }
                    else if (RowVector[i] == 11) // 1011
                    {
                        boutonPressed = matrix[i][1];
                       
                        UART_PutChar(boutonPressed);
                        CyDelay(200);
                    }
                    else if (RowVector[i] == 7) //0111
                    {
                        boutonPressed = matrix[i][0];
                       
                        UART_PutChar(boutonPressed);
                        CyDelay(200);
                    }
                }       
            }   
	        R1_SetDriveMode(R1_DM_STRONG);
	        R2_SetDriveMode(R2_DM_STRONG);
	        R3_SetDriveMode(R3_DM_STRONG);
	        R4_SetDriveMode(R4_DM_STRONG);
           if (boutonPressed == randomValue)
           {    
               UART_ClearRxBuffer();
               UART_ClearTxBuffer();
               int patate = Timer_ReadPeriod() - Timer_ReadCounter();
               char t[200];
               sprintf(t,"%d \t ",patate);
               UART_PutString(t);
               trouve =1;
            }
           
        }
    }
}
/* [] END OF FILE */
