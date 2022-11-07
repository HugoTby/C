#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int puissance(int a, int b);


int main()
{
	printf("------ A a la puissance B ------\n\n");

	int a, b;
	printf("Entrer A : ");
	scanf("%d", &a);
	printf("Entrer B : ");
	scanf("%d", &b);

	printf("%d puissance %d = %d.\n\n", a, b, puissance(a, b));

	return 0;
}

int puissance(int a, int b)
{
	int resultat = 1;

	for (int i = 0; i < b; i++)
	{
		resultat *= a;

	}

	return resultat;
}

