#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int check_prime(int a);

/**
 * main - the main file
 *
 * @argc: the number of arguments passed
 * @argv: the array of arguments passed
 *
 * Return 0 on success
 */

int main(int argc, char **argv)
{
	FILE *fd;
	long long unsigned int num, p, q;
	size_t n;
	char *numstr = malloc(1);

	if (argc != 2)
		return(0);

	fd = fopen(argv[1], "r");

	while (getline(&numstr, &n, fd) != -1)
	{
		num = atoll(numstr);
		for (q = 2; q < num; q++)
		{
			if (num % q == 0)
			{
				p = num / q;
				if (check_prime(p) & check_prime(q))
				{
					printf("%lld=%lld*%lld\n", num, p, q);
					break;
				}
			}
		}
	}

	free(numstr);
	fclose(fd);

	return(0);
}

/**
 * check_prime - checks to ensure a number is a prime number
 *
 * @a: the integer
 *
 * Return: 1 if prime or 0 if not prime
 */

int check_prime(int a)
{
	int i;

	for (i = 2; i < a; i++)
	{
		if (a % i == 0)
			return (0);
	}
	return (1);
}
