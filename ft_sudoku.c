#include "sudoku.h"

int		line_valid(int row, int col, int nbr)
{
	int row_cntr;
	int col_cntr;

	row_cntr = 0;
	col_cntr = 0;
	while (row_cntr < 9)
	{
		if (g_board[row_cntr][col] == nbr && \
				row_cntr != row && col_cntr != col)
			return (0);
		row_cntr++;
	}
	while (col_cntr < 9)
	{
		if (g_board[row][col_cntr] == nbr && \
				row_cntr != row && col_cntr != col)
			return (0);
		col_cntr++;
	}
	return (1);
}

int		box_valid(int row, int col, int nbr)
{
	int min_row;
	int min_col;
	int row_cntr;
	int col_cntr;

	min_row = (row / 3) * 3;
	min_col = (col / 3) * 3;
	row_cntr = min_row;
	while (row_cntr < (min_row + 3))
	{
		col_cntr = min_col;
		while (col_cntr < (min_col + 3))
		{
			if (g_board[row_cntr][col_cntr] == nbr &&
					row_cntr != row && col_cntr != col)
				return (0);
			col_cntr++;
		}
		row_cntr++;
	}
	return (1);
}

int		find_cell(int *row, int *col)
{
	int row_cntr;
	int col_cntr;

	row_cntr = 0;
	while (row_cntr < 9)
	{
		col_cntr = 0;
		while (col_cntr < 9)
		{
			if (g_board[row_cntr][col_cntr] == 0)
			{
				*row = row_cntr;
				*col = col_cntr;
				return (1);
			}
			col_cntr++;
		}
		row_cntr++;
	}
	return (0);
}

int		solve(void)
{
	int row;
	int col;
	int nbr;

	if (!find_cell(&row, &col))
		return (1);
	nbr = 1;
	while (nbr <= 9)
	{
		if (box_valid(row, col, nbr) && line_valid(row, col, nbr))
		{
			g_board[row][col] = nbr;
			if (solve())
				return (1);
			g_board[row][col] = 0;
		}
		nbr++;
	}
	return (0);
}
