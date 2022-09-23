#include "hash_tables.h"

/**
  * hash_table_get - function that retrieves a value associated with a key
  * @ht: hash table to lookup
  * @key: lookup key
  *
  * Return: key value if found else NULL
  */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	char *value;
	unsigned long int index;
	hash_node_t *address;

	if (!ht || !ht->array || !key || (strlen(key) == 0))
		return (NULL);

	index = key_index((unsigned char *) key, ht->size);

	if (index >= ht->size)
		return (NULL);

	address = ht->array[index];

	value = find_value(address, key);

	return (value);
}


/**
  * find_value - function that finds the value of a key in a linked list
  * @head: head node of a linked list at an index
  * @key: key whose value is to be looked up
  *
  * Return: value on success or NULL on failure
  */
char *find_value(hash_node_t *head, const char *key)
{
	if (head == NULL)
		return (NULL);

	while (head)
	{
		if (strcmp(head->key, key) == 0)
			return (head->value);

		head = head->next;
	}

	return (NULL);
}

