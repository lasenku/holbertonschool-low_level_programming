#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - creates a file and writes text content to it
 * @filename: the name of the file to create
 * @text_content: a NULL terminated string to write to the file,
 * or NULL to create an empty file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t len, w_count;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	len = 0;
	while (text_content[len] != '\0')
		len++;

	w_count = write(fd, text_content, len);
	if (w_count == -1 || w_count != len)
	{
		close(fd);
		return (-1);
	}

	close(fd);

	return (1);
}
