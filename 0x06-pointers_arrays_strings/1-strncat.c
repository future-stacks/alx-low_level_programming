#include "main.h"

/**
 * _strncat - concatenate two strings based on number of bytes
 * @dest: string to be added to
 * @src: string to be added
 * @n: number of string bytes to concatenate
 * Description: a function that concatenates two strings
 * Return: a pointer to @dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	while (*(dest + i))
		i++;
	if (n > 0)
	{
		while (*(src + j))
		{
			*(dest + i++) = *(src + j++);
			if (j == n)
				return (dest);
		}
	}
	return (dest);
}
