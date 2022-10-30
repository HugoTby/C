#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>



int main(int argc, char *argv[])
{
	float notesSubject;
	int notesSup10 = 0, i = 0, nbEleves;
	printf("Veuillez saisir le nombres d eleves dans la classe !\n");
	scanf("%d", &nbEleves);
	while (i < nbEleves)
	{
		printf("\nVeuillez saisir la note de l eleve numero %d\n", i + 1);
		scanf("%f", &notesSubject);
		if (notesSubject > 20 || notesSubject < 0)
		{
			printf("Saisis de note stopper car la note que vous avez saisi est superieur a 20 ou inferieur a 0 !");
			break;
		}
		if (notesSubject > 10)
		{
			notesSup10 += 1;
		}
		i++;
	}
}
