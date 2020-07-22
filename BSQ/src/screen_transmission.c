#include "bsq.h"

void	painting(t_board *board, t_square *square)
{
	int		x;
	int		y;
	char	full;

	full = board->full;
	x = square->height - square->length;
	while (++x <= square->height)
	{
		y = square->width - square->length;
		while (++y <= square->width)
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
		ft_putchar('\n');
	}
}