#ifndef H_H
# define H_H

#define ERR_DIV "Stop : division by zero"
#define ERR_MOD "Stop : modulo by zero"

int     mul(int a, int b);
int     div(int a, int b);
int     mod(int a, int b);
int     sum(int a, int b);
int     sub(int a, int b);
void	putstr(char *str);
int     is_valid(char o);
void	recursive(int nb);
void	ft_putnbr(int nb);

# endif