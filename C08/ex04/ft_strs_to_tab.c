/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xifoxy <xifoxy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 00:57:00 by xifoxy            #+#    #+#             */
/*   Updated: 2020/07/16 00:57:00 by xifoxy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					get_len(char *str)
{
	int len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

void				ft_strcpy(char *dest, char *dest2, char *src)
{
	while (*src)
	{
		*dest++ = *src;
		*dest2++ = *src++;
	}
	*dest = 0;
	*dest2 = 0;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *ret;
	int         idx;

	if (!(ret = (t_stock_str*)malloc(sizeof(t_stock_str) * (ac + 1))))
		return (0);
	idx = -1;
	while (++idx < ac)
	{
		ret[idx].size = get_len(av[idx]);
		ret[idx].str = (char *)malloc(sizeof(char) * (ret[idx].size + 1));
		ret[idx].copy = (char *)malloc(sizeof(char) * (ret[idx].size + 1));
		ft_strcpy(ret[idx].str, ret[idx].copy, av[idx]);
	}
	ret[idx].str = 0;
	return (ret);
}
