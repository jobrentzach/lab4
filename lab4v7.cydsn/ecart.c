#include "project.h"
#include "header.h"

int ecart(volatile int length, volatile int a[8])
{
	//int somme = 0;
	int mean = moyenne(length, &a[8]);
	double std = 0;
//	for (int i =0; i < length; i++)
//	{
//		somme += a[i];
//	}
//	
//	mean = somme/(length + 1);
	
	
	
	for(int j=0; j < length; j++)
	{
        std += pow((double)a[j] - (double)mean,2);
	}
    std = sqrt((double)std/((double)length + 1));
	
	return (int)std;
	
}
