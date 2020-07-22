#include "total.h"

void	bsq(char *file)
{
	t_board		*board;
	t_square	*square;

	if (!file)
		board = make_board(0);
	else
		board = make_board(file);
	if (!board)
	{
		ft_putstr(MAP_ERR);
		return ;
	}
	square = find_square(board);
	if (square->length)
		ft_putstr(MAP_ERR);
	else
		pritn(board, square);
	free_t_board(board, board->height);
	free(square);
}

void	init(int ac, char **ag)
{
	int idx;

	idx = 0;
	if (ac == 1)
		bsq(0);
	else
		while (++idx < ac)
			bsq(ag[idx]);
}