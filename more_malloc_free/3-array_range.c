#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers containing all the
 * values from min to max, inclusive
 * @min: the minimum value (included)
 * @max: the maximum value (included)
 *
 * Return: a pointer to the newly created array, or NULL if min > max
 * or if malloc fails
 */
int *array_range(int min, int max)
{
	int *arr;
	int size, i;

	if (min > max)
		return (NULL);

	size = max - min + 1;
	arr = malloc(size * sizeof(int));
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		arr[i] = min + i;

	return (arr);
}
