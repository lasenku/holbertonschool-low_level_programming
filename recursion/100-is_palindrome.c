#include "main.h"

/**
 * str_len_helper - computes the length of a string, using recursion
 * @s: the string to measure
 *
 * Return: the length of the string
 */
int str_len_helper(char *s)
{
	if (*s == '\0')
		return (0);

	return (1 + str_len_helper(s + 1));
}

/**
 * palindrome_helper - checks recursively if the characters between
 * start and end (inclusive) mirror each other
 * @s: the string to check
 * @start: the current index from the beginning
 * @end: the current index from the end
 *
 * Return: 1 if the substring is a palindrome, 0 otherwise
 */
int palindrome_helper(char *s, int start, int end)
{
	if (start >= end)
		return (1);

	if (s[start] != s[end])
		return (0);

	return (palindrome_helper(s, start + 1, end - 1));
}

/**
 * is_palindrome - returns 1 if a string is a palindrome, 0 otherwise
 * @s: the string to check
 *
 * Return: 1 if s is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len;

	len = str_len_helper(s);

	return (palindrome_helper(s, 0, len - 1));
}
