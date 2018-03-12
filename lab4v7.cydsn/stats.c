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
	
	mean = somme/length;
	
	return mean;
}

int ecart(volatile int length, volatile int a[8])
{	
	double mean = (double) moyenne(length, a);
	double sq_sum = 0;
	
	for (int i = 0; i  < length; ++i)
	{
		sq_sum += a[i]*a[i];
	}
	double variance = sq_sum/length - mean*mean;
	double std = sqrt(variance);
	
	return (int) std;
}
