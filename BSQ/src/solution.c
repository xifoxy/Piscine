#include "bsq.h"

t_square	*find_bsq(t_board *board, t_square *square, int x, int **dp)
{
	int	y;

	y = -1;
	while (++y < board->width)
	{
		if ((x == 0 || y == 0) && dp[x][y] > square->length)
			renew_square(square, x, y, dp[x][y]);
		if (x && y && dp[x][y] == 1)
			dp[x][y] = renew_dp(dp, x, y);
		if (x && y && square->length < dp[x][y])
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