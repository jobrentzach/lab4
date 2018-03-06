/* ========================================
 * 
 * GBM2100 - Laboratoire 4
 * 31 janvier 2018
 * 
 * Zacharie Legault (1853133)
 * 
 * ========================================
*/

#include "project.h"

const char clavier[4][4] = {
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'0', 'F', 'E', 'D'}};

int main(void)
{
	CyGlobalIntEnable;
	char hello[12] = {'U','A','R','T',' ','s','t','a','r','t','!','\n'};
	UART_Start();
	UART_ClearTxBuffer();
	
	const char clavier[4][4] = {
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'0', 'F', 'E', 'D'}};

	uint8_t touches[4][4] = {0};
	
	//CyDelay(1000);
	UART_PutString(hello);
	
	io_0_SetDriveMode(io_0_DM_DIG_HIZ);
	io_1_SetDriveMode(io_1_DM_DIG_HIZ);
	io_2_SetDriveMode(io_2_DM_DIG_HIZ);
	io_3_SetDriveMode(io_3_DM_DIG_HIZ);
	while(1){
		io_0_SetDriveMode(io_0_DM_STRONG);
		io_0_Write(0);
		touches[0][0] = i_0_Read();
		touches[0][1] = i_1_Read();
		touches[0][2] = i_2_Read();
		touches[0][3] = i_3_Read();
		io_0_SetDriveMode(io_0_DM_DIG_HIZ);
		
		io_1_SetDriveMode(io_1_DM_STRONG);
		io_1_Write(0);
		touches[1][0] = i_0_Read();
		touches[1][1] = i_1_Read();
		touches[1][2] = i_2_Read();
		touches[1][3] = i_3_Read();
		io_1_SetDriveMode(io_1_DM_DIG_HIZ);
		
		io_2_SetDriveMode(io_2_DM_STRONG);
		io_2_Write(0);
		touches[2][0] = i_0_Read();
		touches[2][1] = i_1_Read();
		touches[2][2] = i_2_Read();
		touches[2][3] = i_3_Read();
		io_2_SetDriveMode(io_2_DM_DIG_HIZ);
		
		io_3_SetDriveMode(io_3_DM_STRONG);
		io_3_Write(0);
		touches[3][0] = i_0_Read();
		touches[3][1] = i_1_Read();
		touches[3][2] = i_2_Read();
		touches[3][3] = i_3_Read();
		io_3_SetDriveMode(io_3_DM_DIG_HIZ);
		
		for (int i = 0; i < 4; i ++){
			for (int j = 0; j < 4; j++){
				if (!touches[i][j]){
					UART_ClearTxBuffer();
					UART_PutChar(clavier[i][j]);
				}
			}
		}
	}
}