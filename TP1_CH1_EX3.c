#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>



int main(int argc, char *argv[])
{
	float notesEleve;
	int noteSuperieur10 = 0, i = 0, nbEleves;

	printf("Veuillez saisir le nombre d'%cl%cves sans la classe! \n", 130, 138);

	scanf("%d", &nbEleves);

	while (i < nbEleves)
	{
		printf("\nVeuillez saisir la note de 1 %cl%cve num%cro %d\n", 130, 138, 130, i + 1);
		scanf("%f", &notesEleve);

		if (notesEleve > 20 || notesEleve < 0)
		{
			printf("La saisie de note est stopp%ce car la note que vous avez saisi est sup%crieur %c 20 ou inf%crieur à 0!", 130, 130, 133, 130);
			break;
		}
		if (notesEleve > 10)
		{
			noteSuperieur10 += 1;
		}
		i++;
	}
	printf("Il  y a %d note sup%crieur %c 10", noteSuperieur10, 130, 133);
}
