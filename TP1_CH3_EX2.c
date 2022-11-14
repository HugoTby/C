#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>


void affiche(int *t) {

	int i;

	for (i = 0; i < 10; i++) {
		printf("la position de %d est : %d\n", t[i], i + 1);
	}
}


int main(int argc, char ** argv)
{
	int tab[100] = { 1,2,4,8,16,32,64,128,256,512 };
	affiche(tab);

	return 0;
}



