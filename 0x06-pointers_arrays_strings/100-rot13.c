#include "main.h"

/**
 * rot13 - rot13 encoding
 * @s: pointer to a string to be encoded
 * Description: a function that encodes a string using rot13.
 * Return: s, pointer to encoded string
 */
char *rot13(char *s)
{
	char a[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char r[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int i = 0, j;

	while (s[i] != '\0')
	{
		for (j = 0; a[j] != '\0'; j++)
		{
			if (s[i] == a[j])
			{
				s[i] = r[j];
				break;
			}
		}
		i++;
	}
	return (s);
}
