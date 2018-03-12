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
	
	int mean = moyenne(length, &a[8]);
	double temp = 0;
	
	for(int j=0; j < length; ++j)
	{
        temp += pow((double)a[j] - (double)mean,2);
	}
    double std = sqrt(temp/length);
	
	return (int)std;
	
}
