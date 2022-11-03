#include "search_algos.h"

/**
 * print_array - prints the search array
 * @array: pointer the first element in the array
 * @l: start index of array to be print
 * @r: last index of array to print
 *
 * Return: void
 */
void print_array(int *array, size_t l, size_t r)
{
	printf("Searching in array: ");
	while (l < r)
		printf("%d, ", array[l]), l++;
	printf("%d\n", array[l]);
}

/**
 * binary_search - searches for a value using Binary search algorithm
 * @array: pointer to the first element in an array
 * @size: size of the array to be sorted
 * @value: value to be searched for
 *
 * Return: index of value if found, else -1
 */
int binary_search(int *array, size_t size, int value)
{
	size_t l = 0, r = size - 1, m;

	if (array == NULL)
		return (-1);

	while (l <= r)
	{
		print_array(array, l, r);
		m = (l + r) / 2;
		if (array[m] == value)
			return (m);
		else if (array[m] < value)
			l = m + 1;
		else
			r = m - 1;
	}
	return (-1);
}
