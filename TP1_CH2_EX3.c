#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>



int main(int argc, char *argv[])
{
	float t[10];
	float sommeElements = 0, nombre = 0;
	int i, count, nbTable;

	printf("Rentrez le nombre d elements de votre tableau\n");
	scanf("%d", &nbTable);

	for (i = 0; i < nbTable; i++)
	{
		printf("Rentrez une valeur\n");
		scanf("%f", &nombre);

		t[i] = nombre;
	}

	for (count = 0; count < nbTable; count++)
	{
		sommeElements += t[count];
	}
	printf("La somme des elements du tableau est = %.1f", sommeElements);
	



}
