#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the converted integer, or 0 if there are no numbers
 */
int _atoi(char *s)
{
	int i, sign, result, started;

	i = 0;
	sign = 1;
	result = 0;
	started = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-' && started == 0)
		{
			sign = -sign;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			result = result * 10 - (s[i] - '0');
		}
		else if (started == 1)
		{
			break;
		}
		i++;
	}

	if (sign == 1)
		result = -result;

	return (result);
}
