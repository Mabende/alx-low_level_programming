#include "main.h"
/**
 * _isalpha - the function checks for alphabetic character.
 * @c: single alphabet input
 * Return: 1 if c is an alphabet (lower or uppercase), 0 otherwise.
 */
int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	return (1);
	return (0);
}
