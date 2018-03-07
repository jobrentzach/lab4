#include "project.h"
#include <stdio.h>		// snprintf();
#include <stdlib.h>		// abs();

#ifndef __HEADER_H__
#define __HEADER_H__
	
extern const char CLAVIER[4][4];
extern volatile uint8_t g_key_pressed;
extern volatile uint8_t g_btn_pressed;
extern volatile uint8_t g_touches[4][4];

char lecture_clavier();
void menu(char choix);
void pins_read();
void debut();
void fin();
void alphanum();
void analog();
void enable();

#endif