#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a partially or fully allocated grid
 * @grid: the grid to free
 * @rows: the number of rows already allocated
 *
 * Return: void
 */
void free_grid(int **grid, int rows)
{
	int i;

	for (i = 0; i < rows; i++)
		free(grid[i]);
	free(grid);
}

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
	int h, w;

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
			free_grid(grid, h);
			return (NULL);
		}
	}

	for (h = 0; h < height; h++)
		for (w = 0; w < width; w++)
			grid[h][w] = 0;

	return (grid);
}
