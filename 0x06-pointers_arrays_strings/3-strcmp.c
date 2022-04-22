#include "main.h"

/**
 * _strcmp - compare two strings
 * @s1: first operand
 * @s2: second operand
 * Description: a function that compares two strings
 * Return: integer, < or = or > 0
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++)
		;
	return (s1[i] - s2[i]);
}
