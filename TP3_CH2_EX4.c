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
	
	char chaine1[100], tMaj[26], cMaj;
	int i, k, c = 0;

	for (cMaj = 'A'; cMaj <= 'Z'; cMaj++)
	{
		tMaj[c] = cMaj;
		c++;
	}

	printf("Rentrez votre chaine de caracteres de 100 caracteres max\n");
	fgets(chaine1, 100, stdin);

	for (i = 0; chaine1[i] != '\0'; i++)
	{
		for (k = 0; k < c; k++)
		{
			if (chaine1[i] == tMaj[k])
			{
				chaine1[i] = tolower(chaine1[i]);
			}
		}
	}

	printf("Votre chaine sans majuscules donne : %s", chaine1);



}
