#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings, using at most n bytes
 * from the second string
 * @s1: the first string (treated as empty if NULL)
 * @s2: the second string (treated as empty if NULL)
 * @n: the maximum number of bytes to use from s2
 *
 * Return: a pointer to the newly allocated, concatenated string,
 * or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *result;
	unsigned int len1, len2, i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = 0;
	while (s1[len1] != '\0')
		len1++;

	len2 = 0;
	while (s2[len2] != '\0')
		len2++;

	if (n < len2)
		len2 = n;

	result = malloc((len1 + len2 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		result[i] = s1[i];
	for (j = 0; j < len2; j++)
		result[len1 + j] = s2[j];
	result[len1 + len2] = '\0';

	return (result);
}
