#include "search_algos.h"
#include <stdio.h>

/**
 * interpolation_search - implements interpolation search algorithm
 * @array: pointer to the first element in the array
 * @size: number of elements in the array
 * @value: value to be searched for in the array
 *
 * Return: index of value if found, else -1
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t p, l = 0, h = size - 1;

	if (array == NULL)
		return (-1);
	while (l <= h)
	{
		p = l + (((double) (h - l) /
			(array[h] - array[l])) * (value - array[l]));
		if (p < size)
			printf("Value checked array[%ld] = [%d]\n",
					p, array[p]);
		else
		{
			printf("Value checked array[%ld] is out of range\n",
					p);
			break;
		}
		if (array[p] == value)
			return (p);
		else if (array[p] < value)
			l = p + 1;
		else
			h = p - 1;
	}
	return (-1);
}
