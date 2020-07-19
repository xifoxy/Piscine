/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:06:36 by sgang             #+#    #+#             */
/*   Updated: 2020/07/19 20:06:36 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		is_space(char c)
{
	return (c == ' ' || (9 <= c && c <= 13));
}

int		is_num(char c)
{
	return ('0' <= c && c <= '9');
}

int		is_valid_num(char *str)
{
	if (!str || (*str == '0' && *(str + 1)))
		return (0);
	while (*str)
	{
		if (!is_num(*str))
			return (0);
		++str;
	}
	return (1);
}

int		is_valid_key_value(char *str)
{
	int colon;
	int key;
	int val;

	colon = 0;
	key = 0;
	val = 0;
	while (*str)
	{
		if (*str == ':')
			++colon;
		if (!is_space(*str))
		{
			if (colon)
				++val;
			else
				++key;
		}
		++str;
	}
	return (colon == 1 && key && val);
}
