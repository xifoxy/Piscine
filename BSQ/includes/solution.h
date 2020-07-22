#ifndef SOLUTION_H
# define SOLUTION_H

# include "solution_util.h"
# include "struct.h"
# include "memory_allocation.h"

t_square	*find_bsq(t_board *board, t_square *square, int x, int **dp);
t_square	*solution(t_board *board);

#endif