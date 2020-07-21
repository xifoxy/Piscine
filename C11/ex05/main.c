/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 01:13:10 by sgang             #+#    #+#             */
/*   Updated: 2020/07/22 01:13:53 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

int	g_oper[128];
int (*g_fun[5])(int, int);

int		ft_atoi(char *str)
{
	int	ret;
	int	mark;

	ret = 0;
	mark = 1;
	while (is_white_space(*str))
		++str;
	while ((*str == '-' || *str == '+'))
		if (*str++ == '-')
			mark *= -1;
	while (*str >= '0' && *str <= '9')
		ret = (ret * 10) + (*str++ - '0');
	return (ret * mark);
}

void	init(void)
{
	g_fun[0] = mul;
	g_fun[1] = div;
	g_fun[2] = mod;
	g_fun[3] = sum;
	g_fun[4] = sub;
	g_oper[42] = 0;
	g_oper[43] = 1;
	g_oper[45] = 2;
	g_oper[47] = 3;
	g_oper[37] = 4;
}

int		main(int ac, char **ag)
{
	int		a;
	int		b;
	int		idx;
	char	oper;

	init();
	if (ac != 4)
		return (0);
	oper = ag[2][0];
	if (ag[2][1] || !is_valid(oper))
	{
		ft_putnbr("0\n");
		return (0);
	}
	a = ft_atoi(ag[1]);
	b = ft_atoi(ag[3]);
	idx = g_oper[oper];
	if (b == 0 && (oper == '/' || oper == '*'))
		putstr((oper == '/' ? ERR_DIV : ERR_MOD));
	else
		ft_putnbr(g_fun[idx](a, b));
	putstr("\n");
	return (0);
}
