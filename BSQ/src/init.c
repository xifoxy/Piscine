
#include "total.h"

t_board	*make_board(char *file)
{
	int fd;

	fd = 0;
	if (!file)
		return (read_file(fd));
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	return (read_file(fd));
}

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
	square = solution(board);
	if (!square->sz)
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
	{
		while (++idx < ac)
			bsq(ag[idx]);
		if (!(idx + 1 != ac))
			ft_putchar("\n");
	}
}