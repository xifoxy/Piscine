/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 16:53:04 by sgang             #+#    #+#             */
/*   Updated: 2020/07/14 19:56:44 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	isoperator(char ch)
{
	return (ch == '-' || ch == '+');
}

int	white_space(char ch)
{
	return (ch == ' ' || (ch >= 9 && ch <= 13));
}

int	ft_strlen(char *base)
{
	unsigned char	ch;
	int				idx;
	int				chk[256];

	idx = 0;
	while (idx < 256)
	{
		chk[idx] = 0;
		++idx;
	}
	idx = 0;
	while (base[idx])
	{
		ch = base[idx];
		if (chk[(int)ch] || white_space(base[idx]))
			return (0);
		chk[(int)ch]++;
		++idx;
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
		if (*str++ == '-')
			mark *= -1;
	while (*str)
	{
		idx = ft_get_idx(*str++, len, base);
		if (idx == -1)
			break ;
		ret *= len;
		ret += idx;
	}
	return (ret * mark);
}
