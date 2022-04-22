#include "main.h"

/**
 * cap_string - capitilise words of a string
 * @s: pointer to the string
 * Description: a function that capitalizes all words of a string
 * - Separators of words: space, tabulation,
 * new line, ,, ;, ., !, ?, ", (, ), {, and }
 * Return: s
 */

char *cap_string(char *s)
{
	char c[] = " \t\n,;.!?\"(){}";
	int i, j;

	if (s[0] >= 'a' && s[0] <= 'z')
		s[0] = 'A' + (s[0] - 'a');
	i = 1;
	while (s[i] != '\0')
	{
		for (j = 0; c[j] != '\0'; j++)
		{
			if ((s[i - 1] == c[j]) && (s[i] >= 'a' && s[i] <= 'z'))
				s[i] = 'A' + (s[i] - 'a');
		}
		i++;
	}
	return (s);
}
