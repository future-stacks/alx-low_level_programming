#include "lists.h"

void execute_before_main(void) __attribute__ ((constructor));

/**
 * execute_before_main - a function that is called before main
 * Description: This function prints a string.
 * Return: void
 */
void execute_before_main(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
