#include <stdio.h>
#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: unsigned long integer
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;

	mask <<= ((sizeof(unsigned long int) * 8) - 1);

	while (mask > 0)
	{
		if (n & mask)
			_putchar('1');
		else
			_putchar('0');
		mask >>= 1;
	}
}
