#ifndef MEMORY_ALLOCATION_H
# define MEMORY_ALLOCATION_H

# include <stdlib.h>

# include "struct.h"
# include "memory_free.h"
# include "read_util.h"

t_board		*allocation_t_board(void);
t_square	*allocation_t_square(void);
char		**allocation_char_2d(int sz);
char		*allocation_char(char *src, int *sz);
int			**allocation_int_2d(int height, int length);

#endif