#include <stdio.h>
/**
 * main - function to print the name of this program
 * @argc: integer, number of arguments given to this function
 * @argv: pointer to an array of char pointers to strings
 *
 * Return: integer, Always 0 (success)
 */
int main(int argc, char *argv[])
{
	(void) argc;

	printf("%s\n", argv[0]);
	return (0);
}

