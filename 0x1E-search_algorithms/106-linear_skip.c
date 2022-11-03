#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer on the first node where value is located, else NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *start, *end;

	if (list == NULL)
		return (NULL);
	start = list, end = list;
	for ( ; end->next && end->n < value;
			end = end->express ? end->express : end->next)
		if (start->express == end)
			printf("Value checked at index [%ld] = [%d]\n",
					end->index, end->n), start = end;
	if (start->express == end)
		printf("Value checked at index [%ld] = [%d]\n",
				end->index, end->n);
	printf("Value found between indexes [%ld] and [%ld]\n",
			start->index, end->index);
	for ( ; start && start->n <= value; start = start->next)
	{
		printf("Value checked at index [%ld] = [%d]\n",
				start->index, start->n);
		if (start->n == value)
			return (start);
	}
	return (NULL);
}
