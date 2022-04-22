#include "main.h"

/**
 * string_toupper - convert lowercase to uppercase
 * @s: pointer to an array of characters
 * Description: a function that changes all
 * lowercase letters of a string to uppercase
 * Return: *s to the converted string
 */

char *string_toupper(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] >= 97 && s[i] <= 123)
		{
			s[i] = s[i] - 32;
		}
		i++;
	}
	return (s);
}
