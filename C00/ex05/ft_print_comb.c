/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 20:00:08 by sgang             #+#    #+#             */
/*   Updated: 2020/07/06 03:26:41 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	int num;
	char buff[5];

	buff[3] = ',';
	buff[4] = ' ';
	num = -1;
	while (num < 6)
	{
		buff[0] = ++num + '0';
		buff[1] = buff[1];
		while (++buff[1] < '9')
		{
			buff[2] = buff[1];
			while (++buff[2] <= '9')
			{
				write(1, buff, 5);	
			}
		}
    }
	write(1, "789", 3);
}
