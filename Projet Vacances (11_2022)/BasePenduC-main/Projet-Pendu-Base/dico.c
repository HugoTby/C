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

	// On v�rifie si on a r�ussi � ouvrir le dictionnaire
	if (dico == NULL) // Si on n'a PAS r�ussi � ouvrir le fichier
	{
		printf("\nImpossible de charger le dictionnaire de mots");
		return 0; // On retourne 0 pour indiquer que la fonction a �chou�
		// A la lecture du return, la fonction s'arr�te imm�diatement.
	}

	// On compte le nombre de mots dans le fichier (il suffit de compter les
	// entr�es \n
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
	// On recommence � lire le fichier depuis le d�but. On s'arr�te lorsqu'on est arriv�s au bon mot
	rewind(dico);
	while (numMotChoisi > 0)
	{
		caractereLu = fgetc(dico);
		if (caractereLu == '\n')
			numMotChoisi--;
	}

	/* Le curseur du fichier est positionn� au bon endroit.
	On n'a plus qu'� faire un fgets qui lira la ligne */
	fgets(motPioche, 100, dico);

	// On vire l'\n � la fin
	if (tempNumChoisi == 8)
	{
		motPioche[strlen(motPioche) + 1] = '\0';
	}
	else
	{
		motPioche[strlen(motPioche) - 1] = '\0';
	}

	fclose(dico);


	return 1; // Tout s'est bien pass�, on retourne 1
}

int nombreAleatoire(int nombreMax)
{

	srand(time(NULL));
	int nbAleatoire = rand() % (nombreMax + 1 - 0); // piocher entre 0 et 8

	// A impl�menter ...
	return nbAleatoire;
}
