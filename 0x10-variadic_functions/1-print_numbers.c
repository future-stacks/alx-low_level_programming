#include "variadic_functions.h"

/**
 * print-numbers - print numbers followed bt a string separator
 * @separator: string to be printed between numbers
 * @n: number of arguments
 *
 * Return: None
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list valist;
	unsigned int i;

	va_start(valist, n);
	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(p, int));
		if (separator && i < n - 1)
			printf("%s", separator);
	}
	printf("\n");

	va_end(p);
}
