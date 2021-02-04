#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * getfactor - factorizes and prints number
 * @number: number to factor, turns to num
 *
 * Return: void
 */
void fasterfactor(char *number)
{
	long int num = atol(number);
	long int primes[60] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
			       47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103,
			       107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163,
			       167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227,
			       229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281};
	int i;

	for (i = 0; i < 60; i++)
	{
		if (num % primes[i] == 0)
		{
			printf("%ld=%ld*%ld\n", num, num / primes[i], primes[i]);
			return;
		}
	}
}


void getfactor(char *number)
{
	long int num = atol(number);

	if (num % 2 == 0)
		printf("%ld=%ld*2\n", num, num / 2);
	else if (num % 3 == 0)
		printf("%ld=%ld*3\n", num, num / 3);
	else if (num % 5 == 0)
		printf("%ld=%ld*5\n", num, num / 5);
	else if (num % 7 == 0)
		printf("%ld=%ld*7\n", num, num / 7);
	else if (num % 11 == 0)
		printf("%ld=%ld*11\n", num, num / 11);
	else if (num % 13 == 0)
		printf("%ld=%ld*13\n", num, num / 13);
	else if (num % 17 == 0)
		printf("%ld=%ld*17\n", num, num / 17);
	else if (num % 19 == 0)
		printf("%ld=%ld*19\n", num, num / 19);
	else if (num % 23 == 0)
		printf("%ld=%ld*23\n", num, num / 23);
	else if (num % 29 == 0)
		printf("%ld=%ld*29\n", num, num / 29);
	else if (num % 31 == 0)
		printf("%ld=%ld*31\n", num, num / 31);
	else if (num % 37 == 0)
		printf("%ld=%ld*37\n", num, num / 37);
	else if (num % 41 == 0)
		printf("%ld=%ld*41\n", num, num / 41);
	else if (num % 43 == 0)
		printf("%ld=%ld*43\n", num, num / 43);
	else if (num % 47 == 0)
		printf("%ld=%ld*47\n", num, num / 47);
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
		fasterfactor(number);
		characters = getline(&number, &buffsize, fp);
	}
	free(number);
	fclose(fp);
	return (0);
}
