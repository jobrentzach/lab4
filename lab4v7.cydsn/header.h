#include "project.h"
#include <stdio.h>		// snprintf();
#include <stdlib.h>		// abs();
#include <math.h>

#ifndef __HEADER_H__
#define __HEADER_H__
	
extern const char CLAVIER[4][4];
extern volatile uint8_t g_key_pressed;
extern volatile uint8_t g_btn_pressed;
extern volatile uint8_t g_touches[4][4];

struct Sequence
{
	int temps_react[8];
	int compteur; // Position du dernier temps de réaction stocké
};
extern volatile struct Sequence sequenceD;
extern volatile struct Sequence sequenceF;
extern volatile struct Sequence sequenceA0;
extern volatile struct Sequence sequenceA1;

char lecture_clavier();
void menu(char choix);
void pins_read();
void debut();
void fin();
void alphanum();
void analog();
void affichage_stats();
int moyenne(volatile int length, volatile int a[8]);
int ecart(volatile int length, volatile int a[8]);
uint8_t enable();

#endif