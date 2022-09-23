#include "hash_tables.h"

/**
  * hash_table_set - function that adds an element to the hash table
  * @ht: pointer to hash table
  * @key: key of the new element
  * @value: value of the new element
  *
  * Return: 1 on success, 0 on failure
  */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new, *current;
	char *new_key, *new_value;

	if ((ht == NULL) || (ht->array == NULL) || (key == NULL) ||
			(strlen(key) == 0) || (value == NULL))
		return (0);

	index = key_index((const unsigned char *) key, ht->size);
	current = ht->array[index];
	new_value = strdup(value);
	if (new_value == NULL)
		return (0);
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = new_value;
			return (1);
		}
		current = current->next;
	}
	new = malloc(sizeof(hash_node_t));
	new_key = strdup(key);
	if (new == NULL || new_key == NULL)
	{
		free(new_value), free(new_key), free(new);
		return (0);
	}
	new->key = new_key;
	new->value = new_value;
	new->next = ht->array[index];
	ht->array[index] = new;
	return (1);
}

