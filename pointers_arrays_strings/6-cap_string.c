#include "main.h"

/**
 * is_separator - checks if a character is a word separator
 * @c: the character to check
 *
 * Return: 1 if c is a separator, 0 otherwise
 */
int is_separator(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == ',' || c == ';' ||
	    c == '.' || c == '!' || c == '?' || c == '"' || c == '(' ||
	    c == ')' || c == '{' || c == '}')
		return (1);
	return (0);
}

/**
 * cap_string - capitalizes all words of a string
 * @str: the string to capitalize
 *
 * Return: a pointer to the resulting string str
 */
char *cap_string(char *str)
{
	int i;
	int start_of_word;

	i = 0;
	start_of_word = 1;
	while (str[i] != '\0')
	{
		if (start_of_word && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 'a' + 'A';

		if (is_separator(str[i]))
			start_of_word = 1;
		else
			start_of_word = 0;

		i++;
	}

	return (str);
}
