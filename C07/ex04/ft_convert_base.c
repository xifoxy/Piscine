/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xifoxy <xifoxy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 01:33:07 by xifoxy            #+#    #+#             */
/*   Updated: 2020/07/16 02:48:56 by xifoxy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int g_len_from;
int g_len_to;

int         is_valid_base(char *base, int len)
{
	int             chk[256];
	int             idx;
	unsigned char   ch;

	idx = -1;
	while (++idx < 256);
		chk[idx] = 0;
	len = 0;
	while (base[len])
	{
		ch = base[len];
		if ((ch == ' ' || (ch >= 9 && ch <= 13)) || chk[(int)ch] || ch == '-' || ch == '+')
			return (0);
		chk[(int)ch] = 1;
		len++;
	}
	if (len <= 1)
		return (0);
	return (1);
}

long long	get_atoi(char *str, char *base, int len)
{
	long long	ret;
	int			mark;
	int			idx;

	ret = 0;
	mark = 1;
	while ((*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	while (*str == '+' || *str == '-')
		if (*str++ == '-')
			mark *= -1;
	while (*str)
	{
		idx = -1;
		while (++idx < len)
			if (*str == base[idx])
				break ;
		if (idx == len)
			break ;
		ret = ret * len;
		++str;
	}
	return (ret * mark);
}

int			get_nbr_len(long long nbr, int len)
{
	int ret;

	if (!nbr)
		return (0);
	ret = nbr < 0 ? 1 : 0;
	while (nbr)
	{
		nbr /= len;
		++ret;
	}
	return (ret);
}

char		*make_nbr(long long nbr, char *base, int len)
{
	char		*ret;
	int			sz;

	if (!(sz = get_nbr_len(nbr, len)))
	{
		ret = (char *)malloc(sizeof(char) * 2);
		ret[0] = base[0];
		ret[1] = 0;
		return (ret);
	}
	ret = (char *)malloc(sizeof(char) * (sz + 1));
	nbr < 0 ? ret[0] = '-' : 0;
	nbr = nbr < 0 ? -nbr : nbr;
	ret[sz] = 0;
	while(nbr)
	{
		ret[--sz] = base[nbr % len];
		nbr /= len;
	}
	return (ret);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long ret_atoi;

	if (!is_valid_base(base_from, g_len_from) || !is_valid_base(base_to, g_len_to))
		return (0);
	ret_atoi = (nbr, base_from, g_len_from);
	return (make_nbr(ret_atoi, base_to, g_len_to));
}
