#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>



int main(int argc, char *argv[])
{
	string x, sexe, fastFood, sport, sportName;
	int age, nbCine, nbFastFood;

	printf("Voulez vous faire le questionnaire ?\n");
	scanf("%s", &x);

	while (strcmp(x, "oui") == 0 || strcmp(x, "Oui") == 0)
	{
		printf("\nVotre age\n");
		scanf("%d", &age);

		printf("\nVotre sexe\n");
		scanf("%s", &sexe);

		printf("\nLe nombre de fois ou vous allez au cinema par mois\n");
		scanf("%d", &nbCine);

		printf("\nVous preferez quick ou macdo ?\n");
		scanf("%s", &fastFood);

		if (strcmp(fastFood, "quick") == 0 || strcmp(fastFood, "Quick") == 0)
		{
			printf("\nLe nombre de fois ou vous y allez par mois ?\n");
			scanf("%d", &nbFastFood);
		}
		else if (strcmp(fastFood, "macdo") == 0 || strcmp(fastFood, "Macdo") == 0)
		{
			printf("\nLe nombre de fois ou vous y allez par mois ?\n");
			scanf("%d", &nbFastFood);
		}

		printf("\nPratiquez vous un sport ?\n");
		scanf("%s", &sport);

		if (strcmp(sport, "oui") == 0 || strcmp(sport, "Oui") == 0)
		{
			printf("\nUn sport parmi : foot, tennis, basket, judo, natation ?\n");
			scanf("%s", &sportName);

		}
		else if (strcmp(sport, "non") == 0 || strcmp(sport, "non") == 0)
		{
			string sportName = "non";
		}

		printf("\nVotre age : %d\nVotre sexe : %s\nLe nombre de fois que vous allez au cine par mois : %d\nVotre fast food preferez : %s\nLe nombre de fois que vous y allez par mois : %d\nPratique de sport : %s, parmi (foot, tennis, basket, judo, natation) : %s\n", age, sexe, nbCine, fastFood, nbFastFood, sport, sportName);

		printf("Voulez vous refaire le questionnaire ?\n");
		scanf("%s", &x);
	}






}
