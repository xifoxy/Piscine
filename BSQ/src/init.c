
#include "total.h"

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
	free(info);	
	return (ret);
}

char	*get_line(int fd)
{
	char	*line;
	char	ch;
	int		idx;
	int		sz;

	idx = 0;
	sz = 0;
	line = allocation_char(line, &sz);
	while (read(fd, &ch, 1))
	{
		if (ch == "\n")
		{
			line[idx] = 0;
			break;
		}
		if (idx + 1 == sz)
			line = allocation_char(line, &sz);
		line[idx] = ch;
	}
	if (!idx)
		free(line);
	return (idx ? line : 0);
}

int		read_map(t_board *board, char *line, int *idx)
{
	int len;

	len = ft_strlen(line);
	if (board->width == 0)
		board->width = len;
	if (++(*idx) == board->height || is_valid_board(board, line) || board->width != len)
	{
		free(line);
		free_t_board(board, *idx);
		return (0);
	}
	board->map[(*idx)] = line;
	return (1);
}

t_board	*read_file(int fd)
{
	t_board	*board;
	char 	*line;
	int		idx;

	idx = -1;
	board = allocation_t_board();
	line = get_line(fd);
	if (!line || !parse_base_info(board, line))
		return (0);
	board->map = allocation_char_2d(board->height);
	while ((line = get_line(fd)))
		if (!read_map(&idx, board, line))
			return (0);
	if (idx != board->height)
	{
		free_t_board(board, idx);
		return (0);
	}
	return (board);
}

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

void print(t_board board, t_square square)
{
	
}