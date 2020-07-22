#ifndef STRUCT_H
# define STRUCT_H

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

#endif