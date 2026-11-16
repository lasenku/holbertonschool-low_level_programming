#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: the width of the grid
 * @height: the height of the grid
 *
 * Return: a pointer to the newly allocated grid, with every element
 * initialized to 0, or NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int h, w, k;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(height * sizeof(int *));
	if (grid == NULL)
		return (NULL);

	for (h = 0; h < height; h++)
	{
		grid[h] = malloc(width * sizeof(int));
		if (grid[h] == NULL)
		{
			for (k = 0; k < h; k++)
				free(grid[k]);
			free(grid);
			return (NULL);
		}
	}

	for (h = 0; h < height; h++)
		for (w = 0; w < width; w++)
			grid[h][w] = 0;

	return (grid);
}
