#include "main.h"

/**
 * _puts - prints a string to stdout
 * @str: pointer to the string to print
 */
void _puts(char *s)
{
	while (*s)
		_putchar(*s++);

	_putchar('\n');
}
