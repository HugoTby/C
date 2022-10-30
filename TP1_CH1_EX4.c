#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>



int main(int argc, char *argv[])
{
	float moyenneClasse = 0, notes;
	int compteurI = 0;
	while (compteurI < 30)
	{
		printf("Veuillez rentrer la note !\n");
		scanf("%f", &notes);
		while (notes > 20 || notes < 0)
		{
			printf("Veuillez saisir une note ENTRE 0 et 20 SVP!\n");
			scanf("%f", &notes);
		}
		moyenneClasse += notes;
		compteurI++;
	}
	moyenneClasse = moyenneClasse / compteurI;
	printf("La moyenne de classe pour %d eleves est de %f/20", compteurI, moyenneClasse);
}









