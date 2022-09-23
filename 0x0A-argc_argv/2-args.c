#include <stdio.h>
/**
 * main - print all given argument
 * @argc: integer, number of arguments given to this function
 * @argv: pointer to an array of char pointers to strings
 *
 * Return: integer, Always 0 (success)
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}

