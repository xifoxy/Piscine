#ifndef READ_VALID_H
# define READ_VALID_H

# include "struct.h"

int		is_printable(char ch);
int		is_number(char ch);
int		is_valid_info(char *info, int len);
int		is_valid_board(t_board *board, char *line);

#endif