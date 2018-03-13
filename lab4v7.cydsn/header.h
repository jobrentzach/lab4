#include "project.h"
#include <stdio.h>		// snprintf();
#include <stdlib.h>		// abs();
#include <math.h>		// pow(), sqrt()

#ifndef __HEADER_H__
#define __HEADER_H__
	
// Déclaration des variables extern volatile pouvant être appelées et modifiées par d'autres fonctions
extern const char CLAVIER[4][4];
extern volatile uint8_t g_key_pressed;
extern volatile uint8_t g_btn_pressed;
extern volatile uint8_t g_touches[4][4];

struct Sequence
{
	int temps_react[8]; // Vecteur comportant les temps de réaction de chaque essai d'un test
	int compteur; // Position du dernier temps de réaction stocké
};
extern volatile struct Sequence sequenceD;
extern volatile struct Sequence sequenceF;
extern volatile struct Sequence sequenceA0;
extern volatile struct Sequence sequenceA1;

// Déclaration des fonctions
char lecture_clavier(void);
void menu(char choix);
void pins_read(void);
void debut(void);
void fin(void);
void alphanum(void);
void analog(void);
void affichage_stats(void);
int moyenne(volatile int length, volatile int a[8]);
int ecart(volatile int length, volatile int a[8]);
uint8_t enable(void);

#endif