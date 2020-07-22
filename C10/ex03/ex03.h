#ifndef EX03_H
# define EX03_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>

extern int      g_idx;
extern int      g_mode;
extern int      g_address;
extern char     *g_buff_prev;
extern char     *g_buff_cur;
extern char     *g_base_name;


void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_err_msg(char *file);
void	ft_trans_hexa(char *buff, int len);
void    ft_print_char(char *s, int len);

#endif