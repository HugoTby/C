#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>



int main(int argc, char *argv[])
{
	float montantArticle, montantFacture = 0, reductionFacture = 0;
	int nbArticle;
	printf("Saisir le montant de l article et le nombre d article :\n");
	scanf("%f%d", &montantArticle, &nbArticle);
	montantFacture = nbArticle * montantArticle;
	if (montantFacture > 500)
	{
		reductionFacture = montantFacture * 10 / 100;
		montantFacture -= reductionFacture;
		printf("La facture est de = %f euros. Avec la reduction de 10 pourcent, on retire = %f euros", montantFacture, reductionFacture);
	}
	else
	{
		printf("La facture est de = %f euros.", montantFacture);
	}
}
