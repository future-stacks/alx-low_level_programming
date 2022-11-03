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
 * binarySearch - searches for a value using Binary search algorithm
 * @array: pointer to the first element in an array
 * @low: minimum index of search range
 * @high: maximum index of search range
 * @value: value to search for
 *
 * Return: index of value if found, else -1
 */
int binarySearch(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	if (low > high || array == NULL)
		return (-1);
	print_array(array, low, high);
	mid = (low + high) / 2;
	if (array[mid] == value)
		return (mid);
	if (array[mid] > value)
		return (binarySearch(array, low, mid - 1,  value));
	return (binarySearch(array, mid + 1, high, value));
}

/**
 * exponential_search - implements exponential search algorithm
 * @array: pointer to the first element in an array
 * @size: number of element the given array
 * @value: value to search for
 *
 * Return: index of value if found, else -1
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i, n;

	if (array == NULL)
		return (-1);
	if (array[0] == value)
		return (0);
	i = 1;
	while (i < size && array[i] <= value)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		i = i * 2;
	}
	n = i < size ? i : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", i / 2, n);
	return (binarySearch(array, i / 2, n, value));
}
