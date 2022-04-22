#include "main.h"

/**
 * _strncpy - copy string
 * @dest: pointer to a char variable to be modified
 * @src: pointer to a char variable to be copied
 * @n: length of characters to be copied
 * Description: a function that copies a string
 * Return: pointer to @dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';
	return (dest);
}
