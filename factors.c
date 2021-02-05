#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


/**
 * getfactor - factorizes and prints number
 * @number: number to factor, turns to num
 *
 * Return: void
 */
void factorlow(long int num)
{
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

void factorhigh(long int num)
{
        long int primes[120] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
                               47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103,
                               107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163,
                               167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227,
		   	       229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
			       283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
			       353, 359, 367, 373, 379, 383, 389, 397, 401, 409,
			       419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
			       467, 479, 487, 491, 499, 503, 509, 521, 523, 541,
			       547, 557, 563, 569, 571, 577, 587, 593, 599, 601,
			       607, 613, 617, 619, 631, 641, 643, 647, 653, 659};
        int i;

        for (i = 0; i < 120; i++)
        {
                if (num % primes[i] == 0)
                {
                        printf("%ld=%ld*%ld\n", num, num / primes[i], primes[i]);
                        return;
                }
        }
}

void choose(char *number)
{
        long int num = atol(number);

        if (num < 281)
		factorlow(num);
	else
		factorhigh(num);
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
		choose(number);
		characters = getline(&number, &buffsize, fp);
	}
	free(number);
	fclose(fp);
	return (0);
}
