#ifndef SOLUTION_UTIL_H
# define SOLUTION_UTIL_H

# include "memory_allocation.h"
# include "struct.h"

int		**fill_board(t_board *board);
void	renew_square(t_square *square, int x, int y, int sz);
int		get_min(int a, int b, int c);
int		renew_dp(int **dp, int x, int y);

#endif