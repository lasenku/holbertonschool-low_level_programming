#include "main.h"

/**
 * print_number - prints an integer
 * @n: the integer to print
 *
 * Return: void
 */
void print_number(int n)
{
	unsigned int num, div;

	if (n < 0)
	{
		_putchar('-');
		num = -n;
	}
	else
		num = n;

	div = 1;
	while (num / div > 9)
		div *= 10;

	while (div > 0)
	{
		_putchar((num / div) % 10 + '0');
		div /= 10;
	}
}
