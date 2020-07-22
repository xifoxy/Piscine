#include "bsq.h"

void	free_char(char *arr)
{
	free(arr);
}

void	free_char_2d(char **arr, int sz)
{
	int idx;

	idx = -1;
	while (++idx < sz)
		free_char(arr[idx]);
	free(arr);
}

void	free_t_board(t_board *info, int sz)
{
	free_char_2d(info->map, sz);
	free(info);
}

void	free_int(int *arr)
{
	free(arr);
}

void	free_int_2d(int **arr, int sz)
{
	int idx;

	idx = -1;
	while (++idx < sz)
		free_int(arr[idx]);
	free(arr);
}