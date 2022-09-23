#include <stdio.h>
#include <stdlib.h>
/**
 * main - print multiplication of two numbers
 * @argc: integer, number of arguments given to this function
 * @argv: pointer to an array of char pointers to strings
 *
 * Return: integer, Always 1 (success)
 */
int main(int argc, char *argv[])
{
	(void) argc;

	if (argv[1] && argv[2])
	{
		printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
		return (0);
	}
	else
		printf("Error\n");

	return (1);
}

