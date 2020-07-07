/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:31:06 by sgang             #+#    #+#             */
/*   Updated: 2020/07/07 20:59:52 by sgang            ###   ########.fr       */
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
	char str[7];

	str[0] = '0';
	str[1] = '0';
	str[2] = ' ';
	str[5] = ',';
	str[6] = ' ';
	while (str[1] != '9' || str[0] != '9')
	{
		str[3] = str[0];
		if (str[1] == '9')
			udt(str, 3, 4);
		else
			str[4] = str[1] + 1;
		while (str[4] != '9' || str[3] != '9')
		{
			write(1, str, 7);
			udt(str, 3, 4);
		}
		udt(str, 0, 1);
		write(1, str, 7);
	}
	write(1, "99 99", 5);
}
