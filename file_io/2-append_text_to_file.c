#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: the name of the file
 * @text_content: a NULL terminated string to add at the end of the
 * file, or NULL to add nothing
 *
 * Return: 1 on success, -1 on failure (NULL filename, file does not
 * exist, no write permission, or write fails)
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t len, w_count;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
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
