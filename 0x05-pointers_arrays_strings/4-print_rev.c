#include "main.h"

/**
 * print_rev - print input in reverse
 * @s: string parameter to reverse
 * Description: a function that prints string in reverse
 *
 * Return: void
 */

void print_rev(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	i--;
	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i--;
	}
	_putchar('\n');
}
