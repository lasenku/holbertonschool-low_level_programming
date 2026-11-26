#include "main.h"
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * close_fd - closes a file descriptor, exiting with code 100 on failure
 * @fd: the file descriptor to close
 *
 * Return: void
 */
void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: the number of arguments
 * @argv: the arguments: program name, file_from, file_to
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t r_count, w_count;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}

	r_count = read(fd_from, buffer, BUFFER_SIZE);
	while (r_count > 0)
	{
		w_count = write(fd_to, buffer, r_count);
		if (w_count == -1 || w_count != r_count)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
		r_count = read(fd_from, buffer, BUFFER_SIZE);
	}

	if (r_count == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}
