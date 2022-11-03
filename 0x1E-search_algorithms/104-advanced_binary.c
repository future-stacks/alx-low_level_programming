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
 * recursive_bs - finds first index of value using Binary search algorithm
 * @array: pointer to the first element in an array
 * @low: most left index of search range
 * @high: most right index if search range
 * @value: value to search for
 *
 * Return: index of value if found, else -1
 */
int recursive_bs(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	if (low > high || array == NULL)
		return (-1);
	print_array(array, low, high);
	mid = (low + high) / 2;
	if (array[mid] == value && (array[mid - 1] != value || mid == low))
		return (mid);
	if (array[mid] >= value)
		return (recursive_bs(array, low, mid, value));
	return (recursive_bs(array, mid + 1, high, value));
}

/**
 * advanced_binary - apply's recursive Binary search algorithm
 * @array: pointer to the first element in an array
 * @size: number of elements in an array
 * @value: value to search for
 *
 * Return: return value from recursive_bs function
 */
int advanced_binary(int *array, size_t size, int value)
{
	return (recursive_bs(array, 0, size - 1, value));
}
