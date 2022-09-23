#include <stdio.h>
#include <stdlib.h>
/**
 * main - print the sum of arguments
 * @argc: integer, number of arguments given to this function
 * @argv: pointer to an array of char pointers to strings
 *
 * Return: integer, 1 if none integer is present in the arguments
 */
int main(int argc, char *argv[])
{
	int total, i;
	char *p;
	int num;

	total = 0;
	if (argc > 1)
	{
		for (i = 1; argv[i]; i++)
		{
			num = strtol(argv[i], &p, 10);
			if (!*p)
				total += num;
			else
			{
				printf("Error\n");
				return (1);
			}
		}
	}
	printf("%d\n", total);
	return (0);
}

