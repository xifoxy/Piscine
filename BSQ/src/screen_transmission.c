#include "total.h"

void	painting(t_board *board, t_square *square)
{
	int		x;
	int		y;
	char	full;

	full = board->full;
	x = square->x - square->sz;
	while (++x <= square->x)
	{
		y = square->y - square->sz;
		while (++y <= square->y)
			board->map[x][y] = full;
	}
}

void	print(t_board *board, t_square *square)
{
	int idx;
	
	idx = -1;
	painting(board, square);
	while (++idx < board->height)
	{
		ft_putstr(board->map[idx], board->width);
		ft_putstr('\n');
	}
}