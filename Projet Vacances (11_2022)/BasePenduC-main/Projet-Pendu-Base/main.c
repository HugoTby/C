/********** L�GENDE ********************************************************************************
// INFO ... => Besoin d'informations suppl�mentaire
// WARNING ... => Cette ligne/bloc n�c�ssite un peu de maintenance/r�usinage
// ERROR ... => Le code est potentiellement dangereux et doit �tre corrig� au plus vite
// MODIF ... => Modifications � apporter ici
***************************************************************************************************/



#define _CRT_SECURE_NO_WARNINGS

#include "dico.h"	// Pour utiliser le dictionnaire de mots
#include <stdio.h> //Scanf et Printf
#include <string.h> //constantes et fonctions et chaines de caract�res
#include <conio.h> //interface de texte
#include <stdlib.h> // g�re dynamiquement la m�moire

int main(int argc, char ** argv)
{
	//--------------------------------------------------
	// Exemple d'utilisation du dictionnaire de mot : 
	char mot[100], charResearch;
	int i, c, j, tailleMot, essais, modeChoisi = 0;
	int *lettreTrouvee = NULL;
	/*piocherMot(mot);*/	// Pour le moment la fonction renvoi toujours
						// le m�me mot. Vous devez impl�menter la fonction
						// int nombreAleatoire(int nombreMax) dans le fichier
						// dico.c pour que cela fonctionne correctement.

	printf("Bienvenue dans le Pendu !\n\n\n(1) 1 joueur VS ordinateur\n(2) 1 joueur VS 1 joueur\n\nVeuillez saisir votre choix de mode de jeu : ");
	scanf("%d", &modeChoisi);

	while (modeChoisi != 1 && modeChoisi != 2) // MODIF
	{
		printf("\n**ERREUR** : Veuillez saisir un mode de jeu valide : (1) ou (2) : ");
		scanf("%d", &modeChoisi);
	}

	if (modeChoisi == 1)
	{
		//printf("\n**DEV_TOOL** : MODE (1) ");
		// Piocher un mot
		printf("\n\nPioche du mot en cours... [90%]\n\n");
		piocherMot(mot);
	}
	else if (modeChoisi == 2)
	{
		//printf("\n**DEV_TOOL** : MODE (2) ");
		// Entrer un mot
		printf("\n\nVeuillez saisir un mot\n\n");

		for (i = 0; i < 100; i++) {

			mot[i] = _getch(); // Recupere la saisie dans notre chaine

			if (mot[i] == 13) // Si entree
			{
				break;
			}

			printf("*");
		}
		

		mot[i] = '\0'; // Definis la case actuelle comme la derniere de notre chaine

		printf("\n\n");
	}

	// Demander le nombre d'essais
	printf("En combien d%cessais maximum voulez-vous retrouver le mot myst%cre ? : ", 39, 138 );
	scanf("%d", &essais);



//------------------------------------------------------------------------------------------------------------------------------


	// Ici on affiche le mot qui a �t� saisi
	printf("\nAvec les lettres saisies, le mot devient : ");
	for (i = 0; mot[i] != '\0'; i++)
	{
		printf("*");
	}

	tailleMot = strlen(mot); // On recup�re la taille du mot

	lettreTrouvee = malloc(tailleMot * sizeof(int));  // INFO

	for (i = 0; i < tailleMot; i++) // On d�signe le tableau a i=0
	{
		lettreTrouvee[i] = 0;
	}

	while (essais != 0) // Tant que le nombre d'essais est strictement diff�rent de 0 alors :
	{
		printf("\n\n\nIl vous reste %d coups %c jouer", essais, 133); // ici on affiche le nombre d'essais qu'il reste au joueur

		printf("\nVeuillez saisir une lettre (En majuscule) : "); // ici on demande au joueur de saisir un caract�re en MAJ pour qu'il soit compris
		scanf(" %c", &charResearch);


		// On parcourt motSecret pour voir si une lettre propos� par le joueur fait partie du mot
		for (i = 0; mot[i] != '\0'; i++)
		{
			if (charResearch == mot[i]) // Si la lettre fait partie du mot propos� alors :
			{
				lettreTrouvee[i] = 1; // le tableau devient �gal a 1 et donc la condition devient vraie
			}
		}


		j = 0;

		// Ici on affiche le mot qui a �t� saisi
		printf("\nAvec la lettre saisie, le mot devient : ");
		for (i = 0; mot[i] != '\0'; i++)
		{

			if (charResearch == mot[i])
			{
				printf("%c", mot[i]);

				j++; // on ajoute 1 a j
			}
			else if (lettreTrouvee[i])
			{
				printf("%c", mot[i]);
			}
			else
			{
				printf("*"); // on remplace les caract�res par un *
			}
		}

		int win = 1; // on initialise win a 1

		for (i = 0; i < tailleMot; i++)
		{
			if (lettreTrouvee[i] == 0)
			{

				win = 0; //si la condition est vraie alors le joueur gagne la partie, dans le cas pr�sent il ne gagne pas.
			}
		}

		if (win == 1)
		{
			printf("\n\nF%clicitations ! Le mot myst%cre %ctait : %s Bien jou%c !\n", 130, 138, 130, mot, 130); // Ici on affiche le mot myst�re et on d�clare que le joueur a gagn�
			printf("TP PROJET VACANCES - D%cvelopp%c par Hugo Tby\n", 130, 130);
			printf("Merci d'avoir jou%c !\n", 130);
			printf("\n\n\nAppuyez sur une touche pour quitter le jeu\n");
			break;
		}

		if (j == 0)
		{
			essais--;
		}

	}

	if (essais == 0)
	{
		printf("\n\nVous avez perdu ! Le mot myst%cre %ctait : %s\n", 138, 130, mot); // Ici on affiche le mot myst�re et on d�clare que le joueur a perdu
		printf("TP PROJET VACANCES - D%cvelopp%c par Hugo Tby\n", 130, 130);
		printf("Merci d'avoir jou%c !\n", 130);
		printf("\n\n\nAppuyez sur une touche pour quitter le jeu\n");

	}






	//printf("Pioche : %s", mot);
	//--------------------------------------------------
	_getch();

	return 0;
}

