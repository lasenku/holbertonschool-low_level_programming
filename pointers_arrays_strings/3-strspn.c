#include "main.h"

/**
 * is_accepted - checks if a character exists in a string
 * @c: the character to check
 * @accept: the string of accepted characters
 *
 * Return: 1 if c is in accept, 0 otherwise
 */
int is_accepted(char c, char *accept)
{
	int j;

	j = 0;
	while (accept[j] != '\0')
	{
		if (accept[j] == c)
			return (1);
		j++;
	}
	return (0);
}

/**
 * _strspn - gets the length of a prefix substring
 * @s: the string to check
 * @accept: the string of accepted characters
 *
 * Return: the number of bytes in the initial segment of s which
 * consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i;

	i = 0;
	while (s[i] != '\0' && is_accepted(s[i], accept))
		i++;

	return (i);
}
