#include "search_algos.h"
#include <math.h>

/**
 * jump_list - searches for a value using Jump search algorithm
 * @list: pointer to the head of the list to search in
 * @size: number of nodes in list
 * @value: value to search for
 *
 * Return: index of value if found, else -1
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t i, step;
	listint_t *trace = list;

	if (list == NULL)
		return (NULL);
	step = sqrt((double) size), i = list->index + step;
	for (; list != NULL; list = list->next)
	{
		if (list->index == i)
		{
			printf("Value checked at index [%ld] = [%d]\n",
					list->index, list->n);
			if (list->n < value && list->next)
				trace = list, i = i + step;
			else
				break;
			i = i < size ? i : size - 1;
		}
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
			trace->index, i);
	for (; trace && trace->index <= i &&
			trace->n <= value; trace = trace->next)
	{
		printf("Value checked at index [%ld] = [%d]\n",
				trace->index, trace->n);
		if (trace->n == value)
			return (trace);
	}
	return (NULL);
}
