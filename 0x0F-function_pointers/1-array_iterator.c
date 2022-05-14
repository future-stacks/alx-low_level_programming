#include "function_pointers.h"

/**
 * array_iterator - function that executes a function on anarray given
 * @array: pointer to an array of integers
 * @size: size of the array i.e length
 * @action: pointer to a function
 *
 * Return: None
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned long int i;

	if (array != NULL && action != NULL && size)
	{
		for (i = 0; i < size; i++)
			action(array[i]);
	}
}
