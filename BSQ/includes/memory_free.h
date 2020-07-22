#ifndef MEMORY_FREE_H
# define MEMORY_FREE_H

# include <stdlib.h>
# include "struct.h"

void	free_char(char *arr);
void	free_char_2d(char **arr, int sz);
void	free_t_board(t_board *info, int sz);
void	free_int(int *arr);
void	free_int_2d(int **arr, int sz);

#endif