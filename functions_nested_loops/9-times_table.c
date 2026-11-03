#include "main.h"

/**
 * times_table - Prints the 9 times table
 *
 * Return: Nothing
 */
void times_table(void)
{
	int row;
	int col;
	int result;

	row = 0;
	while (row < 10)
	{
		col = 0;
		while (col < 10)
		{
			result = row * col;

			if (result < 10)
			{
				_putchar(result + '0');
			}
			else
			{
				_putchar(result / 10 + '0');
				_putchar(result % 10 + '0');
			}

			if (col < 9)
			{
				_putchar(',');
				_putchar(' ');
			}
			col++;
		}
		_putchar('\n');
		row++;
	}
}
