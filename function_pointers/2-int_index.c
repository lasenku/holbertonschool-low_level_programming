#include "function_pointers.h"

/**
 * int_index - searches for the first element in an array for which
 * a given comparison function does not return 0
 * @array: the array to search
 * @size: the number of elements in the array
 * @cmp: pointer to the comparison function
 *
 * Return: the index of the first matching element, or -1 if no
 * element matches, if size is 0 or negative, or if array or cmp
 * is NULL
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
			return (i);
	}

	return (-1);
}
