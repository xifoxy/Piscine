/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xifoxy <xifoxy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 03:00:03 by xifoxy            #+#    #+#             */
/*   Updated: 2020/07/16 03:00:03 by xifoxy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int g_buf[256];

int		chk_gbuf(unsigned char idx)
{
	return (g_buf[(int)idx]);
}

void	ft_strcpy(char *dest, char *from, char *to)
{
	while (from < to)
		*dest++ = *from++;
	*dest = 0;
}

void	make_chk(char *cset)
{
	unsigned char	ch;
	int				idx;

	idx = 0;
	while (cset[idx])
	{
		ch = cset[idx];
		g_buf[(int)ch] = 1;
		++idx;
	}
}

int		get_word(char *str)
{
	int	ret;
	int	idx;

	idx = 0;
	ret = 0;
	while (*str)
	{
		if (!chk_gbuf(*str))
		{
			while (*str && !chk_gbuf(*str))
				++str;
			++ret;
		}
		++str;
	}
	return (ret);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	char	*from;
	int		idx;

	make_chk(charset);
	ret = (char **)malloc(sizeof(char*) * get_word(str) + 1);
	idx = 0;
	while (*str)
	{
		if (!chk_gbuf(*str))
		{
			from = str;
			while (*str && !chk_gbuf(*str))
				++str;
			ret[idx] = (char *)malloc(str - from + 1);
			ft_strcpy(ret[idx], from, str);
			++idx;
		}
		++str;
	}
	ret[idx] = 0;
	return (ret);
}