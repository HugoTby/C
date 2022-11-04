#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "dico.h"

int piocherMot(char * motPioche)
{
	FILE* dico = NULL; // Le pointeur de fichier qui va contenir notre fichier
	int nombreMots = 0, numMotChoisi = 0, i = 0, tempNumChoisi = 0;
	int caractereLu = 0;
	dico = fopen("dico.txt", "r"); // On ouvre le dictionnaire en lecture seule

	// On vérifie si on a réussi à ouvrir le dictionnaire
	if (dico == NULL) // Si on n'a PAS réussi à ouvrir le fichier
	{
		printf("\nImpossible de charger le dictionnaire de mots");
		return 0; // On retourne 0 pour indiquer que la fonction a échoué
		// A la lecture du return, la fonction s'arrête immédiatement.
	}

	// On compte le nombre de mots dans le fichier (il suffit de compter les
	// entrées \n
	do
	{
		caractereLu = fgetc(dico);
		if (caractereLu == '\n')
			nombreMots++;
	} while (caractereLu != EOF);

	numMotChoisi = nombreAleatoire(nombreMots); // On pioche un mot au hasard
	
	if (numMotChoisi == 8)
	{
		 tempNumChoisi = 8;
	}
	// On recommence à lire le fichier depuis le début. On s'arrête lorsqu'on est arrivés au bon mot
	rewind(dico);
	while (numMotChoisi > 0)
	{
		caractereLu = fgetc(dico);
		if (caractereLu == '\n')
			numMotChoisi--;
	}

	/* Le curseur du fichier est positionné au bon endroit.
	On n'a plus qu'à faire un fgets qui lira la ligne */
	fgets(motPioche, 100, dico);

	// On vire l'\n à la fin
	if (tempNumChoisi == 8)
	{
		motPioche[strlen(motPioche) + 1] = '\0';
	}
	else
	{
		motPioche[strlen(motPioche) - 1] = '\0';
	}

	fclose(dico);


	return 1; // Tout s'est bien passé, on retourne 1
}

int nombreAleatoire(int nombreMax)
{

	srand(time(NULL));
	int nbAleatoire = rand() % (nombreMax + 1 - 0); // piocher entre 0 et 8

	// A implémenter ...
	return nbAleatoire;
}
