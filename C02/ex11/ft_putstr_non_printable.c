/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:30:48 by sgang             #+#    #+#             */
/*   Updated: 2020/07/06 21:18:37 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		isprint(unsigned char ch)
{
	return (ch >= ' ' && ch <= '~');
}

void	hprint(unsigned char ch)
{
	ch = ch > '9' ? 39 : 0;
	write(1, &ch, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
	{
		if (!isprint(str[idx]))
		{
			write(1, '\\', 1);
			hprint(std[idx] / 16);
			hprint(std[idx] % 16);
		}
		else
			write(1, &str[idx], 1);
		++idx;
	}
}
