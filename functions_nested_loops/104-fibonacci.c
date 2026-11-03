#include <stdio.h>

#define LIMIT 10000000000UL

/**
 * print_big - Prints a number split into high and low parts
 * @high: The high part of the number
 * @low: The low part (last 10 digits) of the number
 *
 * Return: Nothing
 */
void print_big(unsigned long high, unsigned long low)
{
	if (high > 0)
		printf("%lu%010lu", high, low);
	else
		printf("%lu", low);
}

/**
 * main - Prints the first 98 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	unsigned long a_high = 0, a_low = 1;
	unsigned long b_high = 0, b_low = 2;
	unsigned long n_high, n_low;

	print_big(a_high, a_low);
	printf(", ");
	print_big(b_high, b_low);

	for (i = 2; i < 98; i++)
	{
		n_low = a_low + b_low;
		n_high = a_high + b_high;
		if (n_low >= LIMIT)
		{
			n_low -= LIMIT;
			n_high += 1;
		}

		printf(", ");
		print_big(n_high, n_low);

		a_high = b_high;
		a_low = b_low;
		b_high = n_high;
		b_low = n_low;
	}

	printf("\n");

	return (0);
}
