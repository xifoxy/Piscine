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
	char		**map;
	char		empty;
	char		full;
	char		barrier;
	int			width;
	int			height;
}				t_board;

# define MAP_ERR "map error\n"
// free.c
void		free_char(char *arr);
void		free_char_2d(char **arr, int sz);
void		free_int(int *arr);
void		free_int_2d(int **arr, int sz);
void		free_t_board(t_board *info, int sz);

// init.c
void		bsq(char *file);
void		init(int ac, char **ag);
t_board		*make_board(char *file);

// string.c
void		ft_strncpy(char *dest, char *src, int sz);
int			ft_strlen(char *s);
void		ft_putchar(char ch);
void		ft_putstr(char *str);
int			ft_atoi(char *str, int len);

// valid.c
int			is_printable(char ch);
int			is_numer(char ch);
int			is_valid_info(char *info, int len);
int			is_valid_board(t_board *board, char *line);


// memory.c
t_board		*allocation_t_board(void);
char		**allocation_char_2d(int sz);
char		*allocation_char(char *src, int *sz);

// read.c
int			parse_base_info(t_board *board, char *info);
char		*read_line(int fd);
int			read_map(t_board *board, char *line, int *idx);
t_board		*read_file(int fd);

// solution.c
int			**fill_board(t_board *board);
t_square	*find_bsq(t_board *board, t_square *square, int x, int **dp);
t_square	*solution(t_board *board);

#endif