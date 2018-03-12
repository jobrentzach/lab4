#include "project.h"
#include "header.h"
#include <stdio.h>
#include <math.h>





// TODO: Vérifier la bonne façon de déclarer les var/const extern
const char CLAVIER[4][4] = {{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'0','F','E','D'}};
volatile uint8_t g_key_pressed;
volatile uint8_t g_btn_pressed;
volatile uint8_t g_touches[4][4] = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};

volatile struct Sequence sequenceD;
volatile struct Sequence sequenceF;
volatile struct Sequence sequenceA0;
volatile struct Sequence sequenceA1;

CY_ISR_PROTO(ISR_input_pins_Handler);
CY_ISR_PROTO(ISR_user_btn_Handler);

int main(void)
{
	
	sequenceD.compteur = 0;
	sequenceF.compteur = 0;
	sequenceA0.compteur = 0;
	sequenceA1.compteur = 0;
	for (int k = 0; k < 8; k ++)
	{
		sequenceD.temps_react[k] = 0;
		sequenceF.temps_react[k] = 0;
		sequenceA0.temps_react[k] = 0;
		sequenceA1.temps_react[k] = 0;
	}
	CyGlobalIntEnable;
	
	ISR_input_pins_StartEx(ISR_input_pins_Handler);
	ISR_user_btn_StartEx(ISR_user_btn_Handler);
	Clock1_Start();
	Clock2_Start();
	UART_Start();
	UART_ClearTxBuffer();
	UART_ClearRxBuffer();
	
	Random_Start();
	
	
	while(1)
	{
		char toUARTMenu[1000] = {};
		snprintf(toUARTMenu,1000,"\r\n\n\n Menu principal - Veuillez choisir une option \r\n Test ALPHANUMERIQUE : A0 \r\n Test ANALOGUE : A1 \r\n Test DEBUT : D \r\n Test FIN : F \r\n Calculer les statistiques : C \r\n\r\n Votre choix (appuyez sur E pour valider): ");
		UART_PutString(toUARTMenu);
		char CRLFx2[4] = "\r\n\r\n";
		UART_PutString(CRLFx2);
		UART_ClearTxBuffer();
		UART_ClearRxBuffer();
		
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
