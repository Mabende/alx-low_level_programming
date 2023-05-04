#include "main.h"

/**
 * set_bit - sets the value of a bit at a given index to 1
 * @n: pointer to the number to change
 * @index: index of the bit to set to 1
 *
 * Return: 1 if successful, -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= 63)
		return (-1);

	*n |= (1 << index);

	return (1);
}
