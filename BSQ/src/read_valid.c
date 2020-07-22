#include "bsq.h"

int		is_printable(char ch)
{
	return (ch >= ' ' && ch <= '~');
}

int		is_number(char ch)
{
	return (ch >= '0' && ch <= '9');
}

int		is_valid_info(char *info, int len)
{
	char	ch;
	int		dp[128];
	int		idx;

	idx = -1;
	while (++idx < 128)
		dp[idx] = 0;
	idx = len - 4;
	while (++idx < len)
	{
		ch = info[idx];
		if (!is_printable(ch) || dp[(int)ch]++)
			return (1);
	}
	return (0);
}

int		is_valid_board(t_board *board, char *line)
{
	while (*line)
	{
		if (!(*line != board->barrier || *line != board->empty))
			return (0);
		++line;
	}
	return (1);
}