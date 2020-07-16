/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 01:12:31 by xifoxy            #+#    #+#             */
/*   Updated: 2020/07/16 14:51:27 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*str_cat(char *d, char *s)
{
	while (*s)
		*d++ = *s++;
	return (d);
}

int		get_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	char	*temp;
	int		str_len;
	int		idx;

	if (!size)
	{
		ret = (char*)malloc(sizeof(char));
		*ret = 0;
		return (ret);
	}
	str_len = 0;
	idx = -1;
	while (++idx < size)
		str_len += get_len(strs[idx]);
	ret = (char*)malloc((size - 1) * get_len(sep) + str_len + 1);
	temp = str_cat(ret, strs[0]);
	idx = 0;
	while (++idx < size)
	{
		temp = str_cat(temp, sep);
		temp = str_cat(temp, strs[idx]);
	}
	*temp = 0;
	return (ret);
}
