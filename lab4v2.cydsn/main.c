/* ========================================
 * 
 * GBM2100 - Laboratoire 4
 * 31 janvier, 7 et 14 février et  2018
 * 
 * Zacharie Legault (1853133)
 * 
 * ========================================
*/

#include "project.h"

const char clavier[4][4] = {{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'0','F','E','D'}};
void PinsRead();
void ClearScreen();
CY_ISR_PROTO(ISR_inputPins_Handler);
uint8_t flag = 0;
volatile uint8_t touches[4][4] = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};

int main(void)
{
	// Setup
	ISR_inputPins_StartEx(ISR_inputPins_Handler);
	CyGlobalIntEnable;
	
	UART_Start();
	char hello[13] = {'U','A','R','T',' ','s','t','a','r','t','!','\n','\r'};
	UART_PutString(hello);

	while(1){
		UART_PutChar(UART_GetChar());
		
		if (flag){
			flag = 0;
			
			// Debouncing
			CyDelay(20);
			
			PinsRead();
			for (int i = 0; i < 4; i ++){
				for (int j = 0; j < 4; j++){
					if (!touches[i][j]){
						UART_PutChar(clavier[i][j]);
					}
				}
			}
			
			CyDelay(200);
		}
	}
}

CY_ISR(ISR_inputPins_Handler){
	flag = 1;
	inputPins_ClearInterrupt();
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

