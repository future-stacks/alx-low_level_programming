#include "hash_tables.h"

/**
  * hash_table_create - function that creates a hash table
  * @size: size of the hash table to be created
  *
  * Return: pointer to a hash table or NULL if an error occurs
  */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_node_t **array;
	hash_table_t *table;
	unsigned long int i;

	table = (hash_table_t *) malloc(sizeof(hash_table_t));
	if (table == NULL)
		return (NULL);

	array = (hash_node_t **) malloc(sizeof(hash_node_t *) * size);

	if (array == NULL)
	{
		free(table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		array[i] = NULL;

	table->size = size;
	table->array = array;

	return (table);
}

