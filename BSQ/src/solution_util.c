#include "total.h"

int			**fill_board(t_board *board)
{
	int		**ret;
	int 	x;
	int		y;

	x = -1;
	ret = allocation_int_2d(board->height, board->width);
	while (++x < board->height)
	{
		y = -1;
		while (++y < board->width)
			if (board->map[x][y] == board->empty)
				ret[x][y] = 1;
			else
				ret[x][y] = 0;			
	}
	return (ret);
}

void	renew_square(t_square *square, int x, int y, int sz)
{
	square->sz = sz;
	square->x = x;
	square->y = y;
	return (square);
}

int		get_min(int a, int b, int c)
{
	int min;

	min = a > b ? b : a;
	min = min > c ? c : min;
	return (min);
}

int		renew_dp(int **dp, int x, int y)
{
	return (get_min(dp[x - 1][y], dp[x][y - 1], dp[x - 1][y - 1]) + 1);
}