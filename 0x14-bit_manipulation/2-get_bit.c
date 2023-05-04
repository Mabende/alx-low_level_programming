#include "main.h"

/**
 * get_bit - Returns the value of a bit an index in an unsigned long int
 *
 * @n: The unsigned long integer to search for the bit value.
 * @index: The index of the bit to retrieve.
 *
 * Return: value of the bit at the  index, or -1 if the index is out of range.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	if (index > 63)
	{
		return (-1);
	}
	bit_val = (n >> index) & 1;

	return (bit_val);
}
