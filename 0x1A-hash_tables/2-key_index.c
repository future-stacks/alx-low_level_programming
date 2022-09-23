#include "hash_tables.h"

/**
  * key_index - function that creates index of a key
  * @key: string value to be hashed
  * @size: array size of the hash table
  *
  * Return: key_index of unsigned long int data type
  */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}

