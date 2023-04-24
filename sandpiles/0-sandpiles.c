#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * toppling_round - Performs one round of toppling
 *
 * @grid: Input sandpile
 */
void toppling_round(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				grid[i][j] -= 4;
				if (i > 0)
					grid[i - 1][j] += 1;
				if (j > 0)
					grid[i][j - 1] += 1;
				if (i < 2)
					grid[i + 1][j] += 1;
				if (j < 2)
					grid[i][j + 1] += 1;
			}
		}
	}
}

/**
 * sandpiles_sum - Sums two sandpiles
 *
 * @grid1: First grid
 * @grid2: Second grid
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	char stable = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}

	while (!stable)
	{
		stable = 1;
		for (i = 0; i < 3; i++)
		{
			if (!stable)
				break;
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					printf("=\n");
					print_grid(grid1);
					toppling_round(grid1);
					stable = 0;
					break;
				}
			}
		}
	}
}
