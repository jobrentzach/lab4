#include "project.h"
#include "header.h"

void pins_read(void)
{
	io_1_SetDriveMode(io_1_DM_DIG_HIZ);
	io_2_SetDriveMode(io_2_DM_DIG_HIZ);
	io_3_SetDriveMode(io_3_DM_DIG_HIZ);
	
	io_0_SetDriveMode(io_0_DM_STRONG);
	g_touches[0][0] = CyPins_ReadPin(input_pins_0);
	g_touches[0][1] = CyPins_ReadPin(input_pins_1);
	g_touches[0][2] = CyPins_ReadPin(input_pins_2);
	g_touches[0][3] = CyPins_ReadPin(input_pins_3);
	io_0_SetDriveMode(io_0_DM_DIG_HIZ);
	
	io_1_SetDriveMode(io_1_DM_STRONG);
	g_touches[1][0] = CyPins_ReadPin(input_pins_0);
	g_touches[1][1] = CyPins_ReadPin(input_pins_1);
	g_touches[1][2] = CyPins_ReadPin(input_pins_2);
	g_touches[1][3] = CyPins_ReadPin(input_pins_3);
	io_1_SetDriveMode(io_1_DM_DIG_HIZ);
	
	io_2_SetDriveMode(io_2_DM_STRONG);
	g_touches[2][0] = CyPins_ReadPin(input_pins_0);
	g_touches[2][1] = CyPins_ReadPin(input_pins_1);
	g_touches[2][2] = CyPins_ReadPin(input_pins_2);
	g_touches[2][3] = CyPins_ReadPin(input_pins_3);
	io_2_SetDriveMode(io_2_DM_DIG_HIZ);
	
	io_3_SetDriveMode(io_3_DM_STRONG);
	g_touches[3][0] = CyPins_ReadPin(input_pins_0);
	g_touches[3][1] = CyPins_ReadPin(input_pins_1);
	g_touches[3][2] = CyPins_ReadPin(input_pins_2);
	g_touches[3][3] = CyPins_ReadPin(input_pins_3);
	
	io_0_SetDriveMode(io_0_DM_STRONG);
	io_1_SetDriveMode(io_1_DM_STRONG);
	io_2_SetDriveMode(io_2_DM_STRONG);
}
