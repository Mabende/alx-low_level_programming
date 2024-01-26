#include <stdio.h>
#include <string.h>

/**
 * generate_key - geneate key based on username
 * @username: filename
 * @key: keygen
 *
 * Return: NULL
 */
void generate_key(const char *username, char *key)
{

	snprintf(key, 20, "KEY_%s", username);
}
/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char key[20];

	if (argc != 2)
	{
	printf("Usage: %s username\n", argv[0]);
	return (1);
	}

	generate_key(argv[1], key);

	printf("Generated key for %s: %s\n", argv[1], key);

	return (0);
}

