#include "project.h"
#include "header.h"

int moyenne(volatile int length, volatile int a[8])
{
	int somme = 0;
	int mean = 0;
	
	for (int i =0; i < length; i++)
	{
		somme += a[i];
	}
	
	mean = somme/(length + 1);
	
	return mean;
}