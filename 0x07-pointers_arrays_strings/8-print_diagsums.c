#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - sum of two square
 * @a: pointer to an array of array
 * @size: size of square
 *
 * Description: a function that prints the sum of
 * the two diagonals of a square matrix of integers
 * Return: Void
 */
void print_diagsums(int *a, int size)
}
int i, s1 = 0, s2 = 0;

	for (i = 0; i < size; i++)
	{
		s1 += a[i];
		a += size;
	}

	a -= size;

	for (i = 0; i < size; i++)
	{
		s2 += a[i];
		a -= size;
	}

	printf("%d, %d\n", s1, s2);
}
