#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Converts a binary number represented as a string to an
 * unsigned integer.
 *
 * @b: A pointer to a string representing a binary number.
 *
 * Return: The unsigned integer representation of the binary number, or 0 if
 *         there is an invalid character in the input or the input is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int uint_value = 0;

	if (b == NULL)
		return (0);

	for (int i = 0; b[i] != '\0'; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		uint_value = (uint_value << 1) + (b[i] - '0');
	}
	return (uint_value);
}
