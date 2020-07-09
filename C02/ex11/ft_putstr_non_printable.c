/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:30:48 by sgang             #+#    #+#             */
/*   Updated: 2020/07/09 20:05:17 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_print(char ch)
{
	return (ch >= ' ' && ch <= '~');
}

void	hprint(char ch)
{
	ch += '0';
	if (ch > '9')
		ch += 39;
	write(1, &ch, 1);
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
			hprint((int)str[idx] / 16);
			hprint((int)str[idx] % 16);
		}
		else
			write(1, &str[idx], 1);
		++idx;
	}
}
