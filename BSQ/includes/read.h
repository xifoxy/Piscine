#ifndef READ_H
# define READ_H

# include <unistd.h>

# include "memory_free.h"
# include "memory_allocation.h"
# include "read_util.h"
# include "read_valid.h"
# include "struct.h"

int		parse_base_info(t_board *board, char *info);
char	*read_line(int fd);
int		read_map(t_board *board, char *line, int *idx);
t_board	*read_file(int fd);

#endif