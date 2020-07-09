/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 16:53:04 by sgang             #+#    #+#             */
/*   Updated: 2020/07/09 17:06:29 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	isoperator(char ch)
{
	return (ch == '-' || ch == '+');
}

int	white_space(char ch)
{
	return (ch == ' ' || (ch >= 9 && ch <= 13) || isoperator(ch));
}

int	ft_strlen(char *base)
{
	int idx;
	int chk[256];

	idx = 0;
	while (idx < 256)
		chk[idx++] = 0;
	idx = 0;
	while (base[idx])
	{
		if (chk[base[idx]] || white_space(base[idx]))
			return (0);
		chk[base[idx++]]++;
	}
	return (idx);
}

int	ft_get_idx(char ch, int len, char *base)
{
	int idx;

	idx = 0;
	while (idx < len)
	{
		if (ch == base[idx])
			return (idx);
		++idx;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int ret;
	int idx;
	int mark;
	int len;

	ret = 0;
	mark = 1;
	idx = 0;
	len = ft_strlen(base);
	if (len <= 1)
		return (0);
	while (white_space(*str))
		++str;
	while (isoperator(*str))
	{
		if (*str == '-')
			mark *= -1;
		++str;
	}
	while (*str)
	{
		idx = ft_get_idx(*str++, len, base);
		ret *= len;
		ret += idx;
	}
	return (ret * mark);
}
