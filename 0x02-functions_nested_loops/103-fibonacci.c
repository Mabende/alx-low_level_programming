#include <stdio.h>

/**
 * main - prints the sum of even valued terms
 *
 * Return: always 0
 */

int main(void)
{
	int a = 1, b = 2, c, sum = 0;

	while (b <= 4000000)
	{
		if (b % 2 == 0)
		{
			sum += b;
		}
		c = a + b;
		a = b;
		b = c;
	}

	printf("%d\n", sum);
	return (0);
}
