#include "main.h"

/**
 * sqrt_helper - searches for the natural square root of a number,
 * using recursion, starting from a given guess
 * @n: the number to find the square root of
 * @guess: the current candidate square root
 *
 * Return: guess if it is the natural square root of n, -1 if no
 * natural square root exists
 */
int sqrt_helper(int n, int guess)
{
	if (guess * guess == n)
		return (guess);

	if (guess * guess > n)
		return (-1);

	return (sqrt_helper(n, guess + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number,
 * using recursion
 * @n: the number to find the square root of
 *
 * Return: the natural square root of n, or -1 if it does not exist
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (sqrt_helper(n, 0));
}
