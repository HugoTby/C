#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>



int main(int argc, char *argv[])
{
	int t[3][4];
	float m[3];
	float moyenneL = 0;
	int i, j, c, row, col, sommeE = 0;

	printf("Le nombres de lignes de votre tableau (Max 3)\n");
	scanf("%d", &row);

	while (row > 3 || row < 0)
	{
		printf("Veuillez saisir un nombres de lignes valide (min 0 et max 3)\n");
		scanf("%d", &row);
	}

	printf("Le nombres de colones de votre tableau (Max 4)\n");
	scanf("%d", &col);

	while (col > 4 || col < 0)
	{
		printf("Veuillez saisir un nombres de colones valide (min 0 et max 4)\n");
		scanf("%d", &col);
	}

	printf("Rentrez (%d) nombres entier dans votre tableau\n", row*col);


	for (i = 0; i < row; i++) // Nombre de lignes
	{
		for (j = 0; j < col; j++) // Nombre de colones
		{
			scanf("%d", &t[i][j]);
			sommeE += t[i][j]; // Somme des valeurs de toute la ligne
		}
		moyenneL = sommeE / j; // Calcul la moyenne de la colone t[row][col]

		m[i] = moyenneL; // Met la moyenne des valeurs de t[i] dans m[i]
		sommeE = 0;
	}

	printf("\n");

	for (c = 0; c < row; c++)
	{
		printf("Moyenne colone %d = %.f\n", c + 1, m[c]); // Parcour le tableau m[] 
	}

	return 0;



}
