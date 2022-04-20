#include "main.h"

/**
 * swap_int - Function to swap values of two integer
 * @a: pointer to the first int variable
 * @b: pointer to the second int variable
 * Description: function that swaps the values of two integers
 * Return: void
 */

void swap_int(int *a, int *b)
{
	int x;

	x = *a;

	*a = *b;

	*b = x;
}
