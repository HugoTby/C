#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>



int main(int argc, char *argv[])
{
	float poid;
	float prix;
	float prix1;
	float prix2;
	float prix3;
	printf("Entrez le poid de votre lettre en grammes : ");
	scanf("%f", &poid);
	prix1 = 3.00;
	prix2 = 3.95;
	prix3 = 5.90;

	if (poid < 20)
	{
		prix = prix1;
	}

	if (poid >= 20 and poid < 50)
	{
		prix = prix2;
	}

	if (poid >= 50)
	{
		prix = prix3;
	}


	printf("Le prix de votre lettre est : %f", prix);
	printf(" frs \n");
	_getch();
}
