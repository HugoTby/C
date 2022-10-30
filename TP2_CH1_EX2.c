#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>



int main(int argc, char *argv[])
{
	int a, b, c;

	printf("Veuillez entrer 3 nombres entiers svp \n");
	scanf("%d%d%d", &a, &b, &c);

	// For a is the minimum
	if (a < b && a < c && b < c)
	{
		printf("%d < %d < %d", a, b, c);
	}
	else if (a < b && a < c && c < b)
	{
		printf("%d < %d < %d", a, c, b);
	}

	// For b is the minimum
	if (b < a && b < c && a < c)
	{
		printf("%d < %d < %d", b, a, c);
	}
	else if (b < a && b < c && c < a)
	{
		printf("%d < %d < %d", b, c, a);
	}

	// For c is the minimum
	if (c < a && c < b && a < b)
	{
		printf("%d < %d < %d", c, a, b);
	}
	else if (c < a && c < b && b < a)
	{
		printf("%d < %d < %d", c, b, a);
	}






}
