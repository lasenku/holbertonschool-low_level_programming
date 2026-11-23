#include <stdio.h>

/**
 * is_all_digits - checks if a string contains only digit characters
 * @s: the string to check
 *
 * Return: 1 if s contains only digits, 0 otherwise
 */
int is_all_digits(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * str_to_int - converts a string of digits to an integer
 * @s: the string to convert
 *
 * Return: the integer value of the string
 */
int str_to_int(char *s)
{
	int i, result;

	result = 0;
	for (i = 0; s[i] != '\0'; i++)
		result = result * 10 + (s[i] - '0');
	return (result);
}

/**
 * main - adds positive numbers passed as command line arguments
 * @argc: the number of arguments passed to the program
 * @argv: the array of arguments
 *
 * Return: 0 on success, 1 if an argument is not a valid number
 */
int main(int argc, char *argv[])
{
	int i, sum;

	sum = 0;
	for (i = 1; i < argc; i++)
	{
		if (!is_all_digits(argv[i]))
		{
			printf("Error\n");
			return (1);
		}
		sum += str_to_int(argv[i]);
	}

	printf("%d\n", sum);

	return (0);
}
