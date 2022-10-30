#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>



int main(int argc, char *argv[])
{
	int a;
	double b;
	int resultat;
	printf("Entrez le premier nombre a multiplier : ");
	scanf("%d", &a);
	printf_s("Entrez le second nombre a multiplier : ");
	scanf("%lf", &b);
	resultat = a / (1.00 / b);
	printf("Le resultat de a*b est : %d \n", resultat);
	_getch();
}
