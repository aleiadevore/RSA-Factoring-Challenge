#include <stdio.h>
#include <stdlib.h>

/**
 * getfactor - factorizes and prints number
 * @number: number to factor, turns to num
 *
 * Return: void
 */

void getfactor(char *number)
{
	int num = atoi(number);

	if (num % 2 == 0)
		printf("%d = 2 * %d\n", num, num / 2);
	else if (num % 3 == 0)
		printf("%d = 3 * %d\n", num, num / 3);
	else if (num % 5 == 0)
		printf("%d = 5 * %d\n", num, num / 5);
	else if (num % 7 == 0)
		printf("%d = 7 * %d\n", num, num / 7);
	else if (num % 11 == 0)
		printf("%d = 7 * %d\n", num, num / 11);
	else if (num % 13 == 0)
		printf("%d = 7 * %d\n", num, num / 13);
	else if (num % 17 == 0)
		printf("%d = 7 * %d\n", num, num / 17);
	else if (num % 19 == 0)
		printf("%d = 7 * %d\n", num, num / 19);
	else if (num % 23 == 0)
		printf("%d = 7 * %d\n", num, num / 23);
	else if (num % 29 == 0)
		printf("%d = 7 * %d\n", num, num / 29);
	else if (num % 31 == 0)
		printf("%d = 7 * %d\n", num, num / 31);
	else if (num % 37 == 0)
		printf("%d = 7 * %d\n", num, num / 37);
	else if (num % 41 == 0)
		printf("%d = 7 * %d\n", num, num / 41);
	else if (num % 43 == 0)
		printf("%d = 7 * %d\n", num, num / 43);
	else if (num % 47 == 0)
		printf("%d = 7 * %d\n", num, num / 47);
}

/**
 * main - prints factor of number
 * @argc: number of arguments
 * @argv: argument
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	int characters;
	char *number = NULL;
	size_t buffsize;
	FILE *fp = fopen(argv[1], "r");

	if (argc < 1)
		return (1);
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	characters = getline(&number, &buffsize, fp);
	while (characters >= 0)
	{
		getfactor(number);
		characters = getline(&number, &buffsize, fp);
	}
	free(number);
	fclose(fp);
	return (0);
}
