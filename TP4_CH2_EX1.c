#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
using namespace std;



int main(int argc, char *argv[])
{
	
	int tab1[40];
	int i, t, c, k, o, a, b;

	// Demande l'user la taille du tableau
	printf("Saisir la taille du tableau (max 40 entier)\n");
	scanf("%d", &t);

	// Saisir les entiers dans le tableau
	printf("\n");
	for (i = 0; i < t; i++)
	{
		printf("Saisir un entier numero %d :\n", i + 1);
		scanf("%d", &tab1[i]);

		if (tab1[i] == -1)
		{
			break;
			printf("La sasie est maintenant arreter");
		}
	}

	// Renvoyer ce que contient le tableau
	printf("\nLe tableau renvoie : ");
	for (c = 0; c < t; c++)
	{
		printf("%d ", tab1[c]);
	}

	printf("\ntris en cours ....\n");

	// Tri du tableau dans l'ordre croissant
	for (k = 0; k < t; k++)
	{
		for (a = k + 1; a < t; a++)
		{
			if (tab1[k] > tab1[a])
			{
				b = tab1[k];
				tab1[k] = tab1[a];
				tab1[a] = b;
			}
		}
	}

	// Renvoyer ce que contient le tableau apres le tri
	printf("\nLe tableau apres le tri renvoi : ");
	for (o = 0; o < t; o++)
	{
		printf("%d  ", tab1[o]);
	}

	printf("\n");



}
