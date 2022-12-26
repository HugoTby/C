//ex0301
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct
{
	char name[50];
	int numJoueur;

	int coup1[10];
	int coup2[10];
	int coup3Bonus[1];

	int points;
	int SavePoints[10];

} Bowling;

int saisieJoueurs(Bowling ** Players);
void continuer();


int main(int argc, char ** argv)
{
	Bowling * Joueurs = NULL;
	printf("\n\n\n\tBienvenue au bowling de biribi !\n");
	printf("\tAdresse : 146 Bd de Saint-Quentin, 80090 Amiens, France\n");
	printf("\tTel : +33 3 22 33 77 77\n");
	continuer();
	int nbSaisi;

	do
	{
		system("CLS");
		int nbChoisi;

		printf("\n\n\n\t1 - Jouer %c une partie de bowling\n", 133);
		printf("\t2 - Consulter les r%cgles du jeu\n", 138);
		printf("\t3 - Quitter le jeu\n");

		printf("\n\tVeuillez saisir votre choix ( 1, 2 ou 3 ) : ");
		scanf("%d", &nbChoisi);

		while (nbChoisi != 1 && nbChoisi != 2 && nbChoisi != 3)
		{
			printf("\n\tVeuillez saisir un chiffre correct ( 1, 2 ou 3 ) : ");
			scanf("%d", &nbChoisi);
		}

		if (nbChoisi == 1)
		{
			// (Fonction de jeu ----------------------------------------)
			system("CLS");

			int nbJoueur = saisieJoueurs(&Joueurs);

			// (Fonction de jeu ----------------------------------------)
		}
		else if (nbChoisi == 2)
		{
			system("CLS");
			printf("Le nombre choisi est 2");//test
		}
		else if (nbChoisi == 3)
		{
			system("CLS");
			printf("Le nombre choisi est 3");//test
			return 0; //exit

		}
		nbSaisi = 0;

		printf("\n\n\tVoulez-vous revenir au pupitre ou quiter le jeu ? ( 1 ou 0 ) : \n");
		printf("\t1 - Revenir au pupitre du jeu\n");
		printf("\t0 - Quitter le jeu\n");
		scanf("%d", &nbSaisi);

		while (nbSaisi != 0 && nbSaisi != 1)
		{
			printf("\n\tVeuillez saisir un chiffre correct ( 1 ou 0 ) : \n");
			scanf("%d", &nbSaisi);
		}

		if (nbSaisi == 1)
		{

		}
		else
		{

		}

	} while (nbSaisi != 0);


}

//fonction du texte de chargement
void continuer()
{
	printf("\n\n\n\tChargement en cours, veuillez patienter...\n\n\n");
	Sleep(5000);
}




int saisieJoueurs(Bowling ** Players)
{
	char nom[50];
	int nbJoueur = 0;
	int nbJoueurSupp = 0;

	printf("\n\n\n\tBienvenue au pupitre");

	do
	{
		printf("\n\n\n\t\tVeuillez saisir un nom pour le joueur numero %d :", nbJoueur + 1);
		scanf("%s", nom);

		//Vérification de la présence du joueur :
		int joueurPresent = 0;
		int joueurIn = 0;

		for (int i = 0; i < nbJoueur; i++)
		{
			if (strcmp(nom, (*Players)[i].name) == 0)
			{
				joueurPresent = 1;
				joueurIn = i;
				break;
			}

		}
		while (joueurPresent == 1) // Si le joueur existe deja
		{
			printf("\n\n\n\tCe nom %cxiste d%cj%c ! Veuillez en saisir un autre : ", 130, 130, 133);
			scanf("%s", nom);


			joueurPresent = 0;
			joueurIn = 0;

			for (int i = 0; i < nbJoueur; i++)
			{
				if (strcmp(nom, (*Players)[i].name) == 0)
				{
					joueurPresent = 1;
					joueurIn = i;
					break;
				}
			}
		}

		if (joueurPresent == 0) // Si le joueur n'existe pas
		{
			nbJoueur++;
			Bowling * oldMem = (*Players);
			(*Players) = malloc(nbJoueur * sizeof(Bowling));
			if (oldMem != NULL)
			{
				memcpy((*Players), oldMem, (nbJoueur - 1) * sizeof(Bowling));
				free(oldMem);
			}
			strcpy((*Players)[nbJoueur - 1].name, nom); // Ajouter le nom du joueur
			(*Players)[nbJoueur - 1].numJoueur = nbJoueur; // Numero du joueur
			(*Players)[nbJoueur - 1].points = 0; // Points a 0
			printf("\n\n\n\t----------------------------------------------------------------------\n");
			printf("\t| Le joueur %c bien %ct%c ajout%c %c la liste des joueurs.                |\n", 133, 130, 130, 130, 133);

		}

		if (nbJoueur != 6)
		{
			printf("\t| Souhaitez-vous ajouter un nouveau joueur ? ( Oui = 1 et Non = 0 ): |\n");
			printf("\t----------------------------------------------------------------------\n\t");
			nbJoueurSupp = _getch();

			while (nbJoueurSupp != 49 && nbJoueurSupp != 48) // Si l'utilisateur rentre pas 1 ou 0
			{
				printf("\n\n\n\tVeuillez choisir un chiffre correct : ");
				nbJoueurSupp = _getch();
			}

			if (nbJoueurSupp == 48) // Si fin saisie 
			{
				if (nbJoueur == 1)
				{
					printf("\nNous vous souhaitons une bonne partie !");
					break;
				}
				else
				{
					printf("\nNous souhaitons une bonne partie %c tout les joueurs !", 133);
					break;
				}
			}
		}
		else
		{
			printf("\n\n\n\tNous souhaitons une bonne partie %c tout les joueurs ! ( le nombre de joueur maximum %c %ct%c atteint)", 133, 133, 130, 130);
			break;
		}
	} while (nbJoueurSupp != 0 || nbJoueur < 6);

	return nbJoueur;

}
