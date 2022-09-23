#include "hash_tables.h"

/**
  * hash_table_print - function that prints a hash table.
  * @ht: hash table
  *
  * Return: void
  */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i, track = 0;
	hash_node_t *address;

	if (ht == NULL || ht->array == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		address = ht->array[i];
		if (address != NULL)
		{
			track += 1;
			if (track > 1)
				printf(", ");
			print_nodes(address);
		}
	}
	printf("}\n");
}


/**
 * print_nodes - print data in a linked list
 * @head: pointer to a linked list
 *
 * Return: void
 */
void print_nodes(hash_node_t *head)
{
	for ( ; head != NULL; head = head->next)
	{
		printf("'%s': '%s'", head->key, head->value);

		if (head->next)
			printf(", ");
	}
}

