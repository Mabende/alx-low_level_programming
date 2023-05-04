#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @n: first number
 * @t: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int t)
{
	unsigned int count = 0;
	unsigned long int exclusive = n ^ t;

	while (exclusive != 0)
	{
		count++;
		exclusive &= (exclusive - 1);
	}

	return (count);
}
