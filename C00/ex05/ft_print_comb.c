/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 14:55:23 by sgang             #+#    #+#             */
/*   Updated: 2020/07/08 17:14:32 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char str[5];

	str[0] = '0' - 1;
	str[3] = ',';
	str[4] = ' ';
	while (++str[0] <= '6')
	{
		str[1] = str[0];
		while (++str[1] <= '8')
		{
			str[2] = str[1];
			while (++str[2] <= '9')
			{
				write(1, str, 5);
			}
		}
	}
	write(1, "789", 3);
}
