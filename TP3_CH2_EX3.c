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
	
	char chainCharacter[100] = "", tabC[52], cMin, cMaj;
	int i, j = 0, t = 0, a, b, e = 0;

	printf("Les lettres de l alphabet en minuscule : ");

	for (cMin = 'a'; cMin <= 'z'; cMin++)
	{
		printf("%c", cMin);
		tabC[t] = cMin;
		t++;
	}

	printf("\n");

	printf("Les lettres de l alphabet en majuscule : ");
	for (cMaj = 'A'; cMaj <= 'Z'; cMaj++)
	{
		printf("%c", cMaj);
		tabC[t] = cMaj;
		t++;
	}

	printf("\n");

	printf("Mon tableau de l alphabet est : ");
	for (a = 0; a < t; a++)
	{
		printf("%c", tabC[a]);
	}

	printf("\n\nSaisir une chaine de caracteres svp :\n");
	fgets(chainCharacter, 100, stdin);

	for (i = 0; chainCharacter[i] != '\0'; i++)
	{
		for (b = 0; b < t; b++)
		{
			if (chainCharacter[i] == tabC[b])
			{
				j++;
			}
		}

		if (chainCharacter[i] == ' ')
		{
			e++;
		}
	}

	printf("\nLe nombre de lettre de l alphabet est de %d et d espaces dans votre chaine est de %d\n", j, e);



}
