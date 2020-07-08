/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:31:06 by sgang             #+#    #+#             */
/*   Updated: 2020/07/08 16:46:36 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	udt(char *str, int st, int ed)
{
	if (str[ed] == '9')
	{
		str[ed] = '0';
		str[st]++;
	}
	else
		str[ed]++;
}

void	ft_print_comb2(void)
{
	char str[8];

	str[0] = '0';
	str[1] = '0';
	str[2] = ' ';
	str[5] = ',';
	str[6] = ' ';
	while (str[0] != '9' || str[1] != '8')
	{
		str[3] = str[0];
		if (str[1] == '9')
			udt(str, 3, 4);
		else
			str[4] = str[1] + 1;
		while (str[3] != '9' || str[4] != '9')
		{
			write(1, str, 7);
			udt(str, 3, 4);
		}
		write(1, str, 7);
		udt(str, 0, 1);
	}
	write(1, "98 99", 5);
}
