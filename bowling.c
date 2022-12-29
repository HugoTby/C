//ex0301
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

typedef struct
{
	char name[50];
	int numJoueur;
	int lancerNum1[10];
	int lancerNum2[10];
	int lancerBonus[1];
	int points;
	int SauvegardePoints[10];

} Bowling;

int saisieJoueurs(Bowling ** Players);
void structureJeu(Bowling ** Players, int nbPlayer);
int calculDesPoints(Bowling ** Players, int numJoueur, int nbTours, int numCoups, int *lancerBonus);
void score(Bowling * Players, int nbJoueur, int nbTours);
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

void structureJeu(Bowling ** Players, int nbPlayer)
{

	int nbLancer = 0, LancerBonus = 0;

	do
	{
		nbLancer++;

		for (int i = 0; i < nbPlayer; i++)
		{
			int tableauDuScore[2];
			LancerBonus = 0;

			for (int k = 0; k < 2; k++)
			{
				printf("\n\n\n\tLe %d %cme tour est en cours pour : %s\n", nbLancer, 138, (*Players)[i].name);
				printf("\tPour lancer la %d %cme boule de bowling, saisissez le symbole [@]\n", k + 1, 138);

				while (_getch() != 64)
				{
					printf("\n\n\n\tVeuillez saisir le symbole [@] pour lancer la boule %d \n", k + 1);
				}

				tableauDuScore[k] = calculDesPoints(Players, i, nbLancer - 1, k + 1, &LancerBonus);

				if (tableauDuScore[0] == 10) // -> donc en cas de strike
				{
					(*Players)[i].points += tableauDuScore[0];

					if (nbLancer == 10)
					{
						printf("\n\n\n\tVous disposez de deux lancers suppl%cmentaires pour avoir r%calis%c un strike ! bravo !!\n", 130, 130, 130);
						for (int b = 0; b < 2; b++)
						{
							printf("\n\n\n\tLe %d %cme tour est en cours pour : %s\n", nbLancer, 138, (*Players)[i].name);
							printf("\tPour lancer la %d %cme boule (bonus) de bowling, saisissez le symbole [@]\n", b + 1, 138);

							while (_getch() != 64)
							{
								printf("\n\n\n\tVeuillez saisir le symbole [@] pour lancer la boule %d \n", k + 1);
							}
							if (b == 0) 
							{
								tableauDuScore[1] = calculDesPoints(Players, i, nbLancer - 1, b + 2, &LancerBonus); // 1er lancer
							}
							else 
							{
								(*Players)[i].lancerBonus[0] = calculDesPoints(Players, i, nbLancer - 1, b + 2, &LancerBonus); // 2eme lancer
							}
						}
							(*Players)[i].points += tableauDuScore[1] + (*Players)[i].lancerBonus[0];
					}
					break;
				}
				else if (k == 1 && tableauDuScore[0] + tableauDuScore[1] == 10) // -> donc en cas de spare
				{
					if (nbLancer == 10)
					{
						printf("\n\n\n\tVous disposez d%cun lancers suppl%cmentaires pour avoir r%calis%c un spare ! bravo !!\n", 39, 130, 130, 130);

						printf("\n\n\n\tLe %d %cme tour est en cours pour : %s\n", nbLancer, 138, (*Players)[i].name);
						printf("\tPour lancer la boule (bonus) de bowling, saisissez le symbole [@]\n");

						while (_getch() != 64)
						{
							printf("\n\n\n\tVeuillez saisir le symbole [@] pour lancer la boule %d \n", k + 1);
						}

						(*Players)[i].lancerBonus[0] = calculDesPoints(Players, i, nbLancer - 1, k + 2, &LancerBonus); // 1er et unique lancer
						(*Players)[i].points += tableauDuScore[1] + (*Players)[i].lancerBonus[0]; // affichage du point bonus
					}
					break;
				}
				else //Si le joueur ne fait ni de spare, ni de strike
				{
					(*Players)[i].points += tableauDuScore[k];
				}
				
			}
			(*Players)[i].SauvegardePoints[nbLancer - 1] = (*Players)[i].points; // point du tour
			affichageScore(*Players, nbPlayer, nbLancer);
		}

	} while (nbLancer < 10);

}


int calculDesPoints(Bowling ** Players, int numJoueur, int nbTours, int numCoups, int *lancerBonus)
{
	int resultatCoups[2], max = 0;
	srand(time(NULL));

	if (numCoups == 1)
	{
		(*Players)[numJoueur].lancerNum1[nbTours] = rand() % 11; // faire tomber les quilles 0 -> 10
		resultatCoups[0] = (*Players)[numJoueur].lancerNum1[nbTours];

		if (*lancerBonus != 1 && nbTours > 0 && (*Players)[numJoueur].lancerNum1[nbTours - 1] + (*Players)[numJoueur].lancerNum2[nbTours - 1] == 10)// en cas de spare au lancer précédent
		{
			if ((*Players)[numJoueur].lancerNum1[nbTours - 1] != 10) // Si le joueur n'a pas fait de strike
			{
				(*Players)[numJoueur].lancerNum2[nbTours - 1] += resultatCoups[0]; // Ajout du premier coup pour le tour suivant
				(*Players)[numJoueur].points += (*Players)[numJoueur].lancerNum2[nbTours - 1]; 
				*lancerBonus = 1;
			}
		}

		if (*lancerBonus != 1 && nbTours > 1 && (*Players)[numJoueur].lancerNum1[nbTours - 2] == 10) // un strike deux tours avant
		{
			if ((*Players)[numJoueur].lancerNum1[nbTours - 1] == 10) // un strike le tour avant
			{
				if (resultatCoups[0] == 10) // en cas de strike
				{
					(*Players)[numJoueur].lancerNum1[nbTours - 2] += 10 + 10; // 3 strike à la suite -> = 30 points
					(*Players)[numJoueur].points += (*Players)[numJoueur].lancerNum1[nbTours - 2] - 10; 
				}
				else 
				{
					(*Players)[numJoueur].lancerNum1[nbTours - 2] += 10 + resultatCoups[0];  
					(*Players)[numJoueur].points += (*Players)[numJoueur].lancerNum1[nbTours - 2] - 10; 
				}
			}
		}

		if (resultatCoups[0] == 10 && nbTours != 9) // en cas de strike a un tour different de 10
		{
			(*Players)[numJoueur].lancerNum2[nbTours] = NULL; 
		}

		return resultatCoups[0];

	}
	else if (numCoups == 2) // si 2eme lancer
	{
		if (nbTours == 9 && (*Players)[numJoueur].lancerNum1[nbTours] == 10) // Si tour =x 10 et strike = 0
		{
			(*Players)[numJoueur].lancerNum2[nbTours] = rand() % 11; // rand quilles 0 -> 10
			resultatCoups[1] = (*Players)[numJoueur].lancerNum2[nbTours]; // score au 2eme lancer
		}
		else // Si tour = 10 et strike = 1
		{
			max = 10 - (*Players)[numJoueur].lancerNum1[nbTours]; // combien de quilles sont encore debout

			(*Players)[numJoueur].lancerNum2[nbTours] = rand() % ++max; // rand quilles restantes
			resultatCoups[1] = (*Players)[numJoueur].lancerNum2[nbTours]; // score au 2eme lancer
		}
		if (*lancerBonus != 1 && nbTours > 0 && (*Players)[numJoueur].lancerNum1[nbTours - 1] == 10) // en cas de strike précédent
		{
			(*Players)[numJoueur].lancerNum1[nbTours - 1] += (*Players)[numJoueur].lancerNum1[nbTours] + resultatCoups[1]; // 2 coups suivant dans le strike précédent
			if (nbTours != 9)
			{
				(*Players)[numJoueur].points += (*Players)[numJoueur].lancerNum1[nbTours - 1] - 10; 

			}
			else
			{
				(*Players)[numJoueur].points += (*Players)[numJoueur].lancerNum1[nbTours - 1] - 10 + resultatCoups[1]; 
			}
			*lancerBonus = 1;
		}
		return resultatCoups[1]; // Lancer no2
	}
	else if (numCoups == 3) // si bonus au 10 eme tour
	{
		printf("\n\n\n\tnumCoups = %d\n", numCoups);
		return rand() % 11; // rand quilles 0 -> 10
	}
}
