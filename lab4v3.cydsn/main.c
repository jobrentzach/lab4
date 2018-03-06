/* ========================================
 * 
 * GBM2100 - Laboratoire 4
 * 31 janvier, 7 et 14 février et  2018
 * 
 * Zacharie Legault (1853133)
 * 
 * ========================================
*/

/*
TODO
- Trouver pourquoi le timer repart seulement quand on a lâché la touche.
- Vérifier que les temps affichés sont corrects. On dirait qu'il y a un peu de lag.
*/

#include <stdio.h>
#include "project.h"

const char clavier[4][4] = {{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'0','F','E','D'}};
void PinsRead();
void ClearScreen();
CY_ISR_PROTO(ISR_inputPins_Handler);
uint8_t KEY_PRESSED = 0, KEY_RELEASED  = 1;
volatile uint8_t touches[4][4] = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
volatile int time;

int main(void)
{
	// Setup
	ISR_inputPins_StartEx(ISR_inputPins_Handler);
	CyGlobalIntEnable;
	
	UART_Start();
	const int str_len = 100;
	char hello[str_len];
	snprintf(hello, str_len, "UART start!\n\r");
	UART_PutString(hello);
	
	Timer_Start();

	while(1){
		UART_PutChar(UART_GetChar());
        
        if (!KEY_RELEASED){
            if (CyPins_ReadPin(inputPins_0) && CyPins_ReadPin(inputPins_1) && CyPins_ReadPin(inputPins_2) && CyPins_ReadPin(inputPins_3)){
                KEY_RELEASED = 1;
            }
        }
		
		if (KEY_PRESSED && KEY_RELEASED){
			
			KEY_PRESSED = 0;
            KEY_RELEASED = 0;
			
			// Debouncing
			CyDelay(20);
			
			PinsRead();
			for (int i = 0; i < 4; i ++){
				for (int j = 0; j < 4; j++){
					if (!touches[i][j]){
						char toUART[str_len];
						snprintf(toUART, str_len, "Touche %c en %d ms\n\r", clavier[i][j], time);
						UART_PutString(toUART);
					}
				}
			}
			
            Timer_Stop();
            Timer_WriteCounter(0);
            Timer_Start();
            
			CyDelay(200);
		}
	}
}

CY_ISR(ISR_inputPins_Handler){
	KEY_PRESSED = 1;
	inputPins_ClearInterrupt();
	time = Timer_ReadPeriod() - Timer_ReadCounter();
}

void PinsRead(){
	io_1_SetDriveMode(io_1_DM_DIG_HIZ);
	io_2_SetDriveMode(io_2_DM_DIG_HIZ);
	io_3_SetDriveMode(io_3_DM_DIG_HIZ);
	
	io_0_SetDriveMode(io_0_DM_STRONG);
	touches[0][0] = CyPins_ReadPin(inputPins_0);
	touches[0][1] = CyPins_ReadPin(inputPins_1);
	touches[0][2] = CyPins_ReadPin(inputPins_2);
	touches[0][3] = CyPins_ReadPin(inputPins_3);
	io_0_SetDriveMode(io_0_DM_DIG_HIZ);
	
	io_1_SetDriveMode(io_1_DM_STRONG);
	touches[1][0] = CyPins_ReadPin(inputPins_0);
	touches[1][1] = CyPins_ReadPin(inputPins_1);
	touches[1][2] = CyPins_ReadPin(inputPins_2);
	touches[1][3] = CyPins_ReadPin(inputPins_3);
	io_1_SetDriveMode(io_1_DM_DIG_HIZ);
	
	io_2_SetDriveMode(io_2_DM_STRONG);
	touches[2][0] = CyPins_ReadPin(inputPins_0);
	touches[2][1] = CyPins_ReadPin(inputPins_1);
	touches[2][2] = CyPins_ReadPin(inputPins_2);
	touches[2][3] = CyPins_ReadPin(inputPins_3);
	io_2_SetDriveMode(io_2_DM_DIG_HIZ);
	
	io_3_SetDriveMode(io_3_DM_STRONG);
	touches[3][0] = CyPins_ReadPin(inputPins_0);
	touches[3][1] = CyPins_ReadPin(inputPins_1);
	touches[3][2] = CyPins_ReadPin(inputPins_2);
	touches[3][3] = CyPins_ReadPin(inputPins_3);
	
	io_0_SetDriveMode(io_0_DM_STRONG);
	io_1_SetDriveMode(io_1_DM_STRONG);
	io_2_SetDriveMode(io_2_DM_STRONG);
}

