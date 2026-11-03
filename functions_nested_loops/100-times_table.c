#include "main.h"

/**
 * print_num - Prints a number (0 to 225) without padding
 * @num: The number to print
 *
 * Return: Nothing
 */
static void print_num(int num)
{
	if (num >= 100)
	{
		_putchar(num / 100 + '0');
		_putchar((num / 10) % 10 + '0');
		_putchar(num % 10 + '0');
	}
	else if (num >= 10)
	{
		_putchar(num / 10 + '0');
		_putchar(num % 10 + '0');
	}
	else
		_putchar(num + '0');
}

/**
 * print_sep - Prints a comma and padding before a number
 * @num: The number that will follow the separator
 *
 * Return: Nothing
 */
static void print_sep(int num)
{
	_putchar(',');
	_putchar(' ');
	if (num < 100)
		_putchar(' ');
	if (num < 10)
		_putchar(' ');
}

/**
 * print_times_table - Prints the n times table, starting with 0
 * @n: The size of the table
 *
 * Return: Nothing
 */
void print_times_table(int n)
{
	int row, col;

	if (n < 0 || n > 15)
		return;

	for (row = 0; row <= n; row++)
	{
		for (col = 0; col <= n; col++)
		{
			if (col != 0)
				print_sep(row * col);
			print_num(row * col);
		}
		_putchar('\n');
	}
}
