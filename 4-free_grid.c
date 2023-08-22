#include "main.h"

/**
 * free_grid - frees 2d array
 * @grid: input
 * @height: height of grid
 *
 * Return: void
 *
 */
void free_grid(char **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
