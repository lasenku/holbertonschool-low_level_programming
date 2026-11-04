#include <stdio.h>

/**
 * main - finds and prints the largest prime factor of 612852475143
 *
 * Return: Always 0
 */
int main(void)
{
	long n = 612852475143;
	long f = 2;
	long largest = 0;

	while (f * f <= n)
	{
		if (n % f == 0)
		{
			largest = f;
			n /= f;
		}
		else
			f++;
	}
	if (n > 1)
		largest = n;
	printf("%ld\n", largest);
	return (0);
}
