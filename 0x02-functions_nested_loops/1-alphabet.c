#include "main.h"
/**
  * print_alphabet - a void function to print alphabet
  *
  * Description: a function that prints the alphabet, in lowercase,
  * followed by a new line.
  *
  * Return: no return value
  */
void print_alphabet(void)
{
	char c = 'a';

	while (c <= 'z')
	{
		_putchar(c);
		c++;
	}
	_putchar('\n');
}

