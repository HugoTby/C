#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>



int main(int argc, char *argv[])
{
	int i, j, row, col;
	float t[3][4];
	float somme = 0;

	printf("Rentrez le nombres de lignes du tableau (Maximum 3)\n");
	scanf("%d", &row);
	printf("Rentrez le nombres de colones du tableau (Maximum 4)\n");
	scanf("%d", &col);

	printf("Entrez les %d elements qui contiennent votre tableau\n", row * col);


	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			scanf("%f \n", &t[i][j]);
		}
	}

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			somme += t[i][j];
		}
	}

	printf("La somme des elements de votre tableau est = %f", somme);
	return 0;



}
