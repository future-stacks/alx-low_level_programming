#include "variadic_functions.h"

/**
 * print_strings - a function to print strings followed by a new line
 * Description: print strings followed by a new line
 * @separator: string to be printed between numbers
 * @n: number of arguments
 * Return: None
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list valist;
	unsigned int i;

	char *s;

	va_start(valist, n);
	for (i = 0; i < n; i++)
	{
		s = va_arg(valist, char *);
		if (s == NULL)
			printf("(nil)");
		else
			printf("%s", s);
		if (i != (n - 1) && separator != NULL)
			printf("%s", separator);
	}
	printf("\n");

	va_end(valist);
}
