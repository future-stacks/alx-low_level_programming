#include "main.h"

/**
 * leet - encode string
 * @s: pointer to a string
 * Description: a function that encodes a string into 1337.
 * - Letters a and A should be replaced by 4
 * - Letters e and E should be replaced by 3
 * - Letters o and O should be replaced by 0
 * - Letters t and T should be replaced by 7
 * - Letters l and L should be replaced by 1
 * Return: s, pointer to the encoded string
 */

char *leet(char *s)
{
	int i = 0, j;
	char c[] = "aAeEoOtTlL";
	char v[] = "43071";

	while (s[i] != '\0')
	{
		for (j = 0; c[j] != '\0'; j++)
		{
			if (s[i] == c[j])
				s[i] = v[j / 2];
		}
		i++;
	}
	return (s);
}
