#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <iostream>

typedef struct fiche
{
	char nom[50];
	char prenom[50];
	int age;
	char sexe;
	char adresse[500];
	char profession[100];
}fiche;

void initfiche(fiche*p)
{
	
	printf("Veuillez saisir votre nom\n");
	scanf("%s", p->nom);

	printf("Veuillez saisir votre prenom\n");
	scanf("%s", p->prenom);

	printf("Veuillez saisir votre age\n");
	scanf("%d", &p->age);

	while (getchar() != '\n');

	printf("Veuillez saisir votre sexe\n");
	scanf("%c", &p->sexe);
}



int main(int argc, char ** argv)
{
	
	fiche p;
	initfiche(&p);
	printf("\n\n\n\n\nVotre nom est :%s", p.nom);
	printf("\nVotre prenom est :%s", p.prenom);
	printf("\nVotre age est :%d", p.age);
	printf("\nVotre sexe est :%c\n\n\n\n\n\n\n", p.sexe);



	return 0;
}

