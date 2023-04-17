#include "main.h"

/**
 * create_file -function that creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails -1.
 *         Otherwise 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	mode_t mode = S_IRUSR | S_IWUSR;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNIC, mode);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		if (write(fd, text_content, strlen(text_content)) == -1)
		{
			close(fd);
		}
	}
	close(fd);
	return (1);
}
