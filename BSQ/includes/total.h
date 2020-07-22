#ifndef DATA_H
# define DATA_H

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
	char		empty;
	char		full;
	char		barrier;
	int			width;
	int			height;
	char		**map;
}				t_board;

# define MAP_ERR "map error\n"

// string.c
void	ft_strncpy(char *dest, char *src, int sz);
int		ft_strlen(char *s);
void	ft_putchar(char ch);
void	ft_putstr(char *str);
int		ft_atoi(char *str, int len);

// valid.c
int		is_printable(char ch);
int		is_numer(char ch);
int		is_valid_info(char *info, int len);
int		is_valid_board(t_board *board, char *line);

// memory.c
void	free_t_board(t_board *info, int sz);
t_board	*allocation_t_board(void);
char	**allocation_char_2d(int sz);
char	*allocation_char(char *src, int *sz);

// bsq.c
void	bsq(char *file);
void	init(int ac, char **ag);

#endif