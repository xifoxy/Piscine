#include "bsq.h"

t_board		*allocation_t_board(void)
{
	t_board *ret;

	if (!(ret = (t_board *)malloc(sizeof(t_board))))
		exit(0);
	ret->barrier = 0;
	ret->empty = 0;
	ret->full = 0;
	ret->width = 0;
	ret->height = 0;
	ret->map = 0;
	return (ret);
}

t_square	*allocation_t_square(void)
{
	t_square *ret;

	if (!(ret = (t_square *)malloc(sizeof(t_square))))
		exit(0);
	ret->height = 0;
	ret->width = 0;
	ret->length = -1;
	return (ret);
}

char		**allocation_char_2d(int sz)
{
	char **board;

	if (!(board = (char **)malloc(sizeof(char *) * sz)))
		exit(0);
	return (board);
}

char		*allocation_char(char *src, int *sz)
{
	char *ret;

	*sz = *sz ? *sz << 1 : 2;
	if (!(ret = (char *)malloc(*sz)))
		exit(0);
	if (*sz == 2)
		return (ret);
	ft_strncpy(ret, src, *sz);
	free_char(src);
	return (ret);
}

int			**allocation_int_2d(int height, int length)
{
	int	**ret;
	int	idx;

	idx = -1;
	if (!(ret = (int **)malloc(sizeof(int *) * height)))
		exit(0);
	while (++idx < height)
		if (!(ret[idx] = (int *)malloc(sizeof(int) * length)))
			exit(0);
	return (ret);
}