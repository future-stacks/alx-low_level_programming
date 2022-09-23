#include "hash_tables.h"

/**
  * shash_table_create - function that creates a hash table
  * @size: size of the hash table to be created
  *
  * Return: pointer to a hash table or NULL if an error occurs
  */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_node_t **array;
	shash_table_t *table;
	unsigned long int i;

	table = (shash_table_t *) malloc(sizeof(shash_table_t));
	if (table == NULL)
		return (NULL);

	array = (shash_node_t **) malloc(sizeof(shash_node_t *) * size);

	if (array == NULL)
	{
		free(table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		array[i] = NULL;

	table->size = size;
	table->array = array;
	table->shead = NULL;
	table->stail = NULL;

	return (table);
}

/**
  * shash_table_set - function that adds an element to the hash table
  * @ht: pointer to hash table
  * @key: key of the new element
  * @value: value of the new element
  *
  * Return: 1 on success, 0 on failure
  */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new, *current;
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
	new = malloc(sizeof(shash_node_t));
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
	place_node(ht, new);
	return (1);
}

/**
  * place_node - a function that places a node in a hash table sorted list
  * @ht: pointer to the hash table
  * @new: pointer to the new node to be placed sortedly
  *
  * Return: void
  */
void place_node(shash_table_t *ht, shash_node_t *new)
{
	shash_node_t *current;

	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, new->key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		current = ht->shead;
		while (current->snext &&
				(strcmp(current->snext->key, new->key) < 0))
			current = current->snext;
		new->sprev = current;
		new->snext = current->snext;
		if (current->snext == NULL)
			ht->stail = new;
		else
			current->snext->sprev = new;
		current->snext = new;
	}
}

/**
  * shash_table_get - function that retrieves a value associated with a key
  * @ht: hash table to lookup
  * @key: lookup key
  *
  * Return: key value if found else NULL
  */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *address;

	if (!ht || !ht->array || !key || (strlen(key) == 0))
		return (NULL);

	index = key_index((unsigned char *) key, ht->size);

	if (index >= ht->size)
		return (NULL);

	address = ht->shead;

	while (address != NULL && strcmp(address->key, key) != 0)
		address = address->snext;

	if (address != NULL)
		return (address->value);

	return (NULL);
}

/**
  * shash_table_print - prints the hash table using the sorted linked list
  * @ht: hash table
  *
  * Return: void
  */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *address;

	if (ht == NULL || ht->shead == NULL)
		return;

	address = ht->shead;
	printf("{");
	while (address)
	{
		printf("'%s': '%s'", address->key, address->value);
		address = address->snext;
		if (address)
			printf(", ");
	}
	printf("}\n");
}

/**
  * shash_table_print_rev - print the hash tables in reverse of sorted list
  * @ht: hash table
  *
  * Return: void
  */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *address;

	if (ht == NULL || ht->shead == NULL)
		return;

	address = ht->stail;
	printf("{");
	while (address)
	{
		printf("'%s': '%s'", address->key, address->value);
		address = address->sprev;
		if (address)
			printf(", ");
	}
	printf("}\n");
}

/**
  * shash_table_delete - function, deletes hash tables and all its elements.
  * @ht: hash table
  *
  * Return: void
  */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *current, *next;

	if (ht == NULL)
		return;

	current = ht->shead;

	for ( ; current != NULL; current = next)
	{
		next = current->snext;
		free(current->key), free(current->value);
		free(current);
	}
	if (ht->array)
		free(ht->array);
	free(ht);
}

