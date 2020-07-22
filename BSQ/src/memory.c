#include "total.h"

void	free_t_board(t_board *info, int sz)
{
	int idx;
	int	hei;

	idx = -1;
	while (++idx < sz)
		free(info->map[idx]);
	free(info->map);
	free(info);
}

t_board	*allocation_t_board(void)
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

char	**allocation_char_2d(int sz)
{
	char **board;

	if (!(board = (char **)malloc(sizeof(char *) * sz)))
		exit(0);
	return (board);
}

char	*allocation_char(char *src, int *sz)
{
	char *ret;

	*sz = *sz ? *sz << 1 : 2;
	if (!(ret = (char *)malloc(*sz)))
		exit(0);
	if (sz == 2)
		return (ret);
	ft_strncpy(ret, src, *sz);
	free(src);
	return (ret);
}