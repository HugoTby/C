#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <iostream>

long getFileSize(FILE* file)
{
	long position = ftell(file);
	fseek(file, 0L, SEEK_END);
	long result = ftell(file);
	fseek(file, position, SEEK_SET);
	return result;

}


void closeFile(FILE* file) {

	//On vérifie si le fichier est bien fermé ou non
	if (fclose(file) == 0)
	{
		printf("Fermeture reussie\n");
	}
	else
	{
		printf("Echec de fermeture du fichier\n");
	}

}

int main(int argc, char ** argv)
{
	FILE* file = fopen("./source.txt", "r");
	FILE* dest1File = fopen("./dest1.txt", "r");
	FILE* destFile = fopen("./dest2.txt", "w");

	if (file == NULL || destFile == NULL || dest1File == NULL)
	{
		printf("L'ouverture du fichier %c %cchou%ce\n", 133, 130, 130);
		if (file != NULL) fclose(file);
		if (destFile != NULL) fclose(destFile);
		if (dest1File != NULL) fclose(dest1File);
	}
	else
	{
		//Réussite à l'ouverture du fichier :
		char c;
		do
		{

			c = (char)getc(file);
			printf("%c", c);
			if (c != EOF && c != 'a') // [...] && ignore la lettre 'a' en copiant le fichier source.txt dans dest2.txt
			{
				putc(c, destFile);
			}

		} while (c != EOF);
		printf("\n");

		printf("Taille fichier source : %ld octets\n", getFileSize(file));
		printf("Taille fichier dest1 : %ld octets\n", getFileSize(dest1File));
		printf("Taille fichier dest2 : %ld octets\n", getFileSize(destFile));


		closeFile(destFile);
		closeFile(dest1File);
		closeFile(file);

	}

	return 0;
}
	
	
	////////////////////////////////////////////////////////////////////////
	//EX 1 SUPPLÉMENTAIRES
	
	#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <iostream>

long getFileSize(FILE* file)
{
	long position = ftell(file);
	fseek(file, 0L, SEEK_END);
	long result = ftell(file);
	fseek(file, position, SEEK_SET);
	return result;

}


void closeFile(FILE* file) {

	//On vérifie si le fichier est bien fermé ou non
	if (fclose(file) == 0)
	{
		printf("Fermeture reussie\n");
	}
	else
	{
		printf("Echec de fermeture du fichier\n");
	}

}

int main(int argc, char ** argv)
{
	FILE* alphabet = fopen("./alphabet.txt", "w");

	if (alphabet == NULL)
	{
		printf("L'ouverture du fichier %c %cchou%ce\n", 133, 130, 130);
		if (alphabet != NULL) fclose(alphabet);
	}
	else
	{
		//Réussite à l'ouverture du fichier :
		char c;
		for (char c = 'a'; c <= 'z'; c++)
		{
			putc(c, alphabet);
		}
		printf("\n");

		printf("Taille fichier dest2 : %ld octets\n", getFileSize(alphabet));

		closeFile(alphabet);

	}

	return 0;
}

