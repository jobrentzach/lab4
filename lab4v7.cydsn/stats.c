#include "project.h"
#include "header.h"
#include <stdio.h>
#include <math.h> // Fonction sqrt, pow

double * stats(int length, double a[])
{
	double length2 = (double)length;
	double *statistic[2];
	double somme = 0;
	double mean = 0;
	double std = 0;
	for (int i =0; i < length; i++)
	{
		somme += a[i];
	}
	
	mean = somme/(length2 + 1);

    for(int j=0; j < length; j++)
	{
        std += pow(a[j] - mean,2);
	}
    std = sqrt(std/length2);
	*statistic[0] = mean;
	*statistic[1] = std;
	return *statistic;
}
