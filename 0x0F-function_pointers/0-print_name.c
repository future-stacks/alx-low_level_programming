#include "function_pointers.h"

/**
 * print_name - print a name string
 * @name: name of the person
 * @f: pointer to a function
 *
 * Return: None
 */
void print_name(char *name, void (*f)(char *));
{
	if (name != NULL && f != NULL)
		f(name);
}
