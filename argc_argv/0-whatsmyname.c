#include <stdio.h>

/**
 * main - prints the name of the program, followed by a new line
 * @argc: the number of arguments passed to the program
 * @argv: the array of arguments, where argv[0] is the program name
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	(void)argc;

	printf("%s\n", argv[0]);

	return (0);
}
