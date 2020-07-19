/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:06:55 by sgang             #+#    #+#             */
/*   Updated: 2020/07/19 20:06:55 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*trim_left(char *str)
{
	while (*str && is_space(*str))
		++str;
	return (str);
}

void	trim_right(char *str)
{
	if (!*str)
		return ;
	while (*str)
		++str;
	--str;
	while (is_space(*str))
		--str;
	*(++str) = 0;
}

char	*trim_side(char *str)
{
	char *ret;
	char *st;
	char *nd;

	if (!*str)
		return (0);
	st = str;
	while (*st && is_space(*st))
		++st;
	nd = st;
	while (*nd && *(nd + 1) != 0)
		++nd;
	while (is_space(*nd))
		--nd;
	ret = (char*)malloc(nd - st + 2);
	ft_strcpy(ret, st, nd);
	return (ret);
}

char	*trim_allocated_str(char *str)
{
	char *ret;

	ret = trim_side(str);
	free(str);
	return (ret);
}
