#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX
 * standard output
 * @filename: the name of the file to read
 * @letters: the number of letters to read and print
 *
 * Return: the actual number of letters read and printed, or 0 on
 * failure (NULL filename, file cannot be opened or read, or write
 * fails or is incomplete)
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer;
	ssize_t r_count, w_count;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}

	r_count = read(fd, buffer, letters);
	if (r_count == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	w_count = write(STDOUT_FILENO, buffer, r_count);
	if (w_count == -1 || w_count != r_count)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	free(buffer);
	close(fd);

	return (w_count);
}
