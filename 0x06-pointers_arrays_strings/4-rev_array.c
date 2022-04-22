#include "main.h"
/**
 * reverse_array - reverse an array
 * @a: pointer to array to be reverse
 * @n: no of elements in the array
 *
 * Description: a function that reverses the content of an array of integers
 * Return: void
 */

void reverse_array(int *a, int n)
{
	int i = 0, x, y = n - 1;

	while (i < y)
	{
		x = a[i];
		a[i++] = a[y];
		a[y--] = x;
	}
}
