#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct  s_square
{
	int 		width;
	int 		height;
	int 		length;
}				t_square;

typedef struct  s_board
{
	char		**map;
	char		empty;
	char		full;
	char		barrier;
	int			width;
	int			height;
}				t_board;

# define MAP_ERR "Map Error\n"
# define ERR_LEN 10

// init.
t_board		*make_board(char *file);
void		bsq(char *file);
void		init(int ac, char **ag);

// memory_allocation.c
t_board		*allocation_t_board(void);
t_square	*allocation_t_square(void);
char		**allocation_char_2d(int sz);
char		*allocation_char(char *src, int *sz);
int			**allocation_int_2d(int height, int length);

// memory_free.c
void		free_char(char *arr);
void		free_char_2d(char **arr, int sz);
void		free_t_board(t_board *info, int sz);
void		free_int(int *arr);
void		free_int_2d(int **arr, int sz);

// read.c
int			parse_base_info(t_board *board, char *info);
char		*read_line(int fd);
int			read_map(t_board *board, char *line, int *idx);
t_board		*read_file(int fd);

// read_valid.c
int			is_printable(char ch);
int			is_number(char ch);
int			is_valid_info(char *info, int len);
int			is_valid_board(t_board *board, char *line);

// screen_transmission.c
void		painting(t_board *board, t_square *square);
void		print(t_board *board, t_square *square);

// solution
t_square	*find_bsq(t_board *board, t_square *square, int x, int **dp);
t_square	*solution(t_board *board);


// solution_util.c
int			**fill_board(t_board *board);
void		renew_square(t_square *square, int x, int y, int sz);
int			get_min(int a, int b, int c);
int			renew_dp(int **dp, int x, int y);

// string.c
int			ft_atoi(char *str, int len);
void		ft_strncpy(char *dest, char *src, int sz);
int			ft_strlen(char *s);
void		ft_putchar(char ch);
void		ft_putstr(char *str, int len);

t_board		*make_board(char *file)
{
	int fd;

	fd = 0;
	if (!file)
		return (read_file(fd));
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	return (read_file(fd));
}

void		bsq(char *file)
{
	t_board		*board;
	t_square	*square;

	if (!file)
		board = make_board(0);
	else
		board = make_board(file);
	if (!board)
	{
		ft_putstr(MAP_ERR, ERR_LEN);
		return ;
	}
	square = solution(board);
	if (!(square->length))
		ft_putstr(MAP_ERR, ERR_LEN);
	else
		print(board, square);
	free_t_board(board, board->height);
	free(square);
}

void		init(int ac, char **ag)
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
			ft_putchar('\n');
	}
}


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

t_square	*find_bsq(t_board *board, t_square *square, int x, int **dp)
{
	int	y;

	y = -1;
	while (++y < board->width)
	{
		if ((x == 0 || y == 0) && square->length < dp[x][y])
			renew_square(square, x, y, dp[x][y]);
		if (x && y)
			dp[x][y] = renew_dp(dp, x, y);
		if (x && y && square->length < dp[x][y])
			renew_square(square, x, y, dp[x][y]);
	}
	return (square);
}

t_square	*solution(t_board *board)
{
	int			idx;
	int			**dp;
	t_square	*square;
	
	idx = -1;
	square = allocation_t_square();
	dp = fill_board(board);
	while (++idx < board->height)
		find_bsq(board, square, idx, dp);
	free_int_2d(dp, board->height);
	return (square);
}

int			**fill_board(t_board *board)
{
	int		**ret;
	int 	x;
	int		y;

	x = -1;
	ret = allocation_int_2d(board->height, board->width);
	while (++x < board->height)
	{
		y = -1;
		while (++y < board->width)
			if (board->map[x][y] == board->empty)
				ret[x][y] = 1;
			else
				ret[x][y] = 0;			
	}
	return (ret);
}

void	renew_square(t_square *square, int x, int y, int sz)
{
	square->length = sz;
	square->height = x;
	square->width = y;
}

int		get_min(int a, int b, int c)
{
	int min;

	min = a > b ? b : a;
	min = min > c ? c : min;
	return (min);
}

int		renew_dp(int **dp, int x, int y)
{
	return (get_min(dp[x - 1][y], dp[x][y - 1], dp[x - 1][y - 1]) + 1);
}

int		ft_atoi(char *str, int len)
{
	int ret;
	int idx;

	idx = -1;
	ret = 0;
	if (*str == '0')
		return (ret);
	while (++idx < len)
	{
		if (!is_number(str[idx]))
			return (0);
		ret *= 10;
		ret += (str[idx] - '0');
	}
	return (ret);
}

void	ft_strncpy(char *dest, char *src, int sz)
{
	int idx;
	
	idx = -1;
	while (++idx < sz)
		*(dest++) = *(src++);
}

int		ft_strlen(char *s)
{
	int len;
	
	len = 0;
	while (s[len])
		++len;
	return (len);
}

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_putstr(char *str, int len)
{
	write(1, str, len);
}

int main(int ac, char **ag)
{
	init(1, 0);
	return (0);
}