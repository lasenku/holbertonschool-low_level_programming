#include "main.h"

/**
 * char_in_set - checks if a character exists in a string
 * @c: the character to check
 * @accept: the string of bytes to search for
 *
 * Return: 1 if c is in accept, 0 otherwise
 */
int char_in_set(char c, char *accept)
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
 * _strpbrk - searches a string for any of a set of bytes
 * @s: the string to search
 * @accept: the string of bytes to search for
 *
 * Return: a pointer to the byte in s that matches one of the bytes
 * in accept, or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (char_in_set(s[i], accept))
			return (s + i);
		i++;
	}

	return (NULL);
}
