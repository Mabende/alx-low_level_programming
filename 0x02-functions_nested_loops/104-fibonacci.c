#include <stdio.h>

/**
 * main - main function
 *
 * Return: 0
 */

int main(void)
{
	int a = 1, b = 2, i;

	printf("%d, %d, ", a, b);
	for (i = 2; i < 98; i++)
	{
		int c = a + b;

		printf("%d", c);

		if (i != 97)
		{
			printf(", ");
		}
		a = b;
		b = c;
	}
	printf("\n");
	return (0);
}
