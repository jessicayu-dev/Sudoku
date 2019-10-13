#ifndef FT_SUDOKU_H

# define FT_SUDOKU_H

# include <unistd.h>

int			solve(void);
extern int	g_board[9][9];
int			line_valid(int row, int col, int nbr);
int			box_valid(int row, int col, int nbr);
#endif
