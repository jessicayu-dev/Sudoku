#include "sudoku.h"

int	g_board[9][9];

void	print_board(void)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	col = 0;
	while (row < 9)
	{
		col = 0;
		while (col < 9)
		{
			c = g_board[row][col] + '0';
			write(1, &c, 1);
			if (col != 8)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

int		char_to_int(char c)
{
	if (c == '.')
		return (0);
	else if (c >= '1' && c <= '9')
		return (c - '0');
	else
		return (-1);
}

int		initialize_board(int argc, char *argv[])
{
	int row;
	int col;
	int cntr;

	row = 1;
	cntr = 0;
	while (row < argc)
	{
		col = 0;
		while (argv[row][col])
		{
			if (char_to_int(argv[row][col]) == -1)
				return (0);
			g_board[row - 1][col] = char_to_int(argv[row][col]);
			cntr += char_to_int(argv[row][col]) > 0 ? 1 : 0;
			col++;
		}
		if (col != 9 || (row == 9 && cntr < 17))
			return (0);
		row++;
	}
	return (1);
}

int		is_board_invalid(void)
{
	int row_cntr;
	int col_cntr;

	row_cntr = 0;
	while (row_cntr < 9)
	{
		col_cntr = 0;
		while (col_cntr < 9)
		{
			if (!box_valid(row_cntr, col_cntr, g_board[row_cntr][col_cntr]) && \
					g_board[row_cntr][col_cntr] != 0)
				return (1);
			else if (!line_valid(row_cntr, col_cntr, \
					g_board[row_cntr][col_cntr]) && \
					g_board[row_cntr][col_cntr] != 0)
				return (1);
			col_cntr++;
		}
		row_cntr++;
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	if (argc != 10 || !initialize_board(argc, argv) || \
			is_board_invalid())
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (solve())
		print_board();
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
}
