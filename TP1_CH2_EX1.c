#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>



int main(int argc, char *argv[])
{

	int tab1[10]; // Table with 1 dimension (10 lines)
	int entier, iValue, i, grand, petit; // Variable int

	for (iValue = 0; iValue < 10; iValue++)
	{
		printf("Rentrez un entier \n");
		scanf("%d", &entier);

		tab1[iValue] = entier;
	}

	printf("\nrenvoie des valeurs du tableau : \n\n");

	for (i = 0; i < 10; i++)
	{
		printf("%d\n", tab1[i]);

		grand = tab1[0];

		if (grand < tab1[i])
		{
			grand = tab1[i];
		}

		petit = tab1[0];

		if (petit > tab1[i])
		{
			petit = tab1[i];
		}

	}
	printf("\nLe plus grand nombres entier est : %d et le plus petit est : %d", grand, petit);
	


}
