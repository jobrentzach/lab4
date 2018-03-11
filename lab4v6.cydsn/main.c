#include "project.h"
#include "header.h"

// TODO: Vérifier la bonne façon de déclarer les var/const extern
const char CLAVIER[4][4] = {{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'0','F','E','D'}};
volatile uint8_t g_key_pressed;
volatile uint8_t g_btn_pressed;
volatile uint8_t g_touches[4][4] = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};

CY_ISR_PROTO(ISR_input_pins_Handler);
CY_ISR_PROTO(ISR_user_btn_Handler);

int main(void)
{

	CyGlobalIntEnable;
	
	ISR_input_pins_StartEx(ISR_input_pins_Handler);
	ISR_user_btn_StartEx(ISR_user_btn_Handler);
	Timer_WritePeriod(100000);
	Clock1_Start();
	Clock2_Start();
	UART_Start();
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	Random_Start();

	while(1)
	{
		char key = lecture_clavier();
		menu(key);
	}
}

CY_ISR(ISR_input_pins_Handler)
{
	g_key_pressed = 1;
	input_pins_ClearInterrupt();
}

CY_ISR(ISR_user_btn_Handler)
{
    g_btn_pressed = 1;
    user_btn_ClearInterrupt();
}
