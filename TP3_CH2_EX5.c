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
	
	char chaine2[100], res[100];
	int i, j = 0;

	printf("Rentrez votre chaine de caracteres : ");
	fgets(chaine2, 100, stdin);

	for (i = 0; chaine2[i] != '\0'; i++)
	{
		if (chaine2[i] != ' ')
		{
			res[j] = chaine2[i];
			j++;
		}
	}

	res[j] = '\0';

	printf("Votre chaine sans espaces donne : %s", res);


	return 0;



}
