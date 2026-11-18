#include "main.h"

/**
 * check_divisors - checks recursively if n has a divisor between
 * 2 and d (inclusive)
 * @n: the number to check
 * @d: the current divisor to test
 *
 * Return: 0 if a divisor is found (n is not prime), 1 if no divisor
 * is found up to d (n is prime so far)
 */
int check_divisors(int n, int d)
{
	if (d * d > n)
		return (1);

	if (n % d == 0)
		return (0);

	return (check_divisors(n, d + 1));
}

/**
 * is_prime_number - returns 1 if the input integer is a prime
 * number, otherwise returns 0
 * @n: the number to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);

	return (check_divisors(n, 2));
}
