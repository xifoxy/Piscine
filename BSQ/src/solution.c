#include "total.h"

void	*find_bsq(t_board *board, t_square *square, int x, int **dp)
{
	int	y;
	int len;

	y = -1;
	while (++y < board->width)
	{
		if ((x == 0 || y == 0) && square->sz < dp[x][y])
			renew_square(square, x, y, dp[x][y]);
		if (x && y)
			dp[x][y] = renew_dp(dp, x, y);
		if (x && y && square->sz < dp[x][y])
			renew_square(square, x, y, dp[x][y]);
	}
	return (square);
}

t_square	*solution(t_board *board)
{
	int			idx;
	int			**dp;
	t_square	*square;
	
	idx = -1;
	square = allocation_t_square();
	dp = fill_board(board);
	while (++idx < board->height)
		find_bsq(board, square, idx, dp);
	free_int_2d(dp, board->height);
	return (square);
}