#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>



int main(int argc, char *argv[])
{
	int x, i, j, again = 1, resultat;

	while (again == 1)
	{
		printf("Rentrez une valeur de x comprise entre 2 et 10\n");
		scanf("%d", &x);

		while (x < 2 || x > 30)
		{
			printf("Rentrez une valeur de x comprise entre 2 et 10\n");
			scanf("%d", &x);
		}

		printf("\t|");

		for (i = 1; i <= x; i++)
		{
			printf("%3d ", i);
		}

		printf("\n-------------------------------------------------------\n");

		for (i = 1; i <= x; i++) {
			printf("%d	|", i);

			for (j = 1; j <= x; j++) {
				resultat = i * j;
				printf("%3d ", resultat);
			}

			printf("\n");
		}

		printf("\nVous vous recommencez ? (1 = oui et 0 = non)\n");
		scanf("%d", &again);
	
	}


}
