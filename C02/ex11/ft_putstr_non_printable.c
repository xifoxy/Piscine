/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:30:48 by sgang             #+#    #+#             */
/*   Updated: 2020/07/10 02:07:11 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_print(char ch)
{
	return (ch >= ' ' && ch <= '~');
}

void	hprint(unsigned char ch)
{
	ch += '0';
	ch += (ch > '9' ? 39 : 0);
	write(1, &ch, 1);
}

void	trans_hex(unsigned char ch)
{
	hprint((int)ch / 16);
	hprint((int)ch % 16);
}

void	ft_putstr_non_printable(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
	{
		if (!is_print(str[idx]))
		{
			write(1, "\\", 1);
			trans_hex(str[idx]);
		}
		else
			write(1, &str[idx], 1);
		++idx;
	}
}
