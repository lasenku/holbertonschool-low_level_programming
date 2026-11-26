#include "main.h"
#include <stdio.h>
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
 * open_files - opens file_from for reading and file_to for writing,
 * exiting with the appropriate error code and message on failure
 * @file_from: the name of the file to read from
 * @file_to: the name of the file to write to
 * @fd_from: pointer to store the file_from file descriptor
 * @fd_to: pointer to store the file_to file descriptor
 *
 * Return: void
 */
void open_files(char *file_from, char *file_to, int *fd_from, int *fd_to)
{
	*fd_from = open(file_from, O_RDONLY);
	if (*fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}

	*fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (*fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99);
	}
}

/**
 * copy_content - copies the content from one file descriptor to
 * another, 1024 bytes at a time, exiting with the appropriate error
 * code and message on failure
 * @fd_from: the file descriptor to read from
 * @fd_to: the file descriptor to write to
 * @file_from: the name of the source file (for error messages)
 * @file_to: the name of the destination file (for error messages)
 *
 * Return: void
 */
void copy_content(int fd_from, int fd_to, char *file_from, char *file_to)
{
	char buffer[BUFFER_SIZE];
	ssize_t r_count, w_count;

	r_count = read(fd_from, buffer, BUFFER_SIZE);
	while (r_count > 0)
	{
		w_count = write(fd_to, buffer, r_count);
		if (w_count == -1 || w_count != r_count)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
		r_count = read(fd_from, buffer, BUFFER_SIZE);
	}

	if (r_count == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
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

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	open_files(argv[1], argv[2], &fd_from, &fd_to);
	copy_content(fd_from, fd_to, argv[1], argv[2]);

	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}
