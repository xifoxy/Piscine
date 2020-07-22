#ifndef READ_UTIL_H
# define READ_UTIL_H

# include <unistd.h>

# include "read_util.h"

int		ft_atoi(char *str, int len);
void	ft_strncpy(char *dest, char *src, int sz);
int		ft_strlen(char *s);
void	ft_putchar(char ch);
void	ft_putstr(char *str, int len);

#endif