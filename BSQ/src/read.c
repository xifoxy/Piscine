#include "bsq.h"

int		parse_base_info(t_board *board, char *info)
{
	int ret;
	int len;

	ret = 0;
	len = ft_strlen(info);
	if (!info || len <= 3 || !(board->height = ft_atoi(info, len - 3)) || is_valid_info(info, len))
		free(board);
	else
	{
		board->empty = info[len - 3];
		board->barrier = info[len - 2];
		board->full = info[len - 1];
		ret = 1;
	}
	free_char(info);	
	return (ret);
}

char	*read_line(int fd)
{
	char	*line;
	char	ch;
	int		idx;
	int		sz;

	line = 0;
	idx = 0;
	sz = 0;
	
	line = allocation_char(line, &sz);
	while (read(fd, &ch, 1))
	{
		if (ch == '\n')
		{
			line[idx] = 0;
			break;
		}
		if (idx + 1 == sz)
			line = allocation_char(line, &sz);
		line[idx++] = ch;
	}
	if (!idx)
		free_char(line);
	return (idx ? line : 0);
}

int		read_map(t_board *board, char *line, int *idx)
{
	int len;

	len = ft_strlen(line);
	if (board->width == 0)
		board->width = len;
	if ((*idx) == board->height || !is_valid_board(board, line) || board->width != len)
	{
		free_char(line);
		free_t_board(board, *idx);
		return (0);
	}
	board->map[(*idx)++] = line;
	return (1);
}

t_board	*read_file(int fd)
{
	t_board	*board;
	char 	*line;
	int		idx;

	idx = 0;
	board = allocation_t_board();
	line = read_line(fd);
	if (!line || !parse_base_info(board, line))
		return (0);
	board->map = allocation_char_2d(board->height);
	while ((line = read_line(fd)))
		if (!read_map(board, line, &idx))
			return (0);
	if (idx != board->height)
	{
		free_t_board(board, idx);
		return (0);
	}
	return (board);
}