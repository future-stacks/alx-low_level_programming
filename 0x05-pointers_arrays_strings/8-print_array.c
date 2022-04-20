#include "main.h"

/**
 * print_array - print elements of an array
 * @a: variable name of the array
 * @n: number of elements to print
 * Description: a function that prints n elements of
 * an array of integers
 * Return: None
 */

void print_array(int *a, int n)
{
	int i = 0;

	while (i < n)
	{
		if (i == (n - 1))
			printf("%d", a[i++]);
		else
			print("%d, ", a[i++]);
	}
	printf("\n");
}

