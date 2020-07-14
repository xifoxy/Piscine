/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 23:44:37 by sgang             #+#    #+#             */
/*   Updated: 2020/07/14 16:42:12 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recursive(int nb)
{
	char ch;

	if (!nb)
		return ;
	ch = '0';
	ch += (nb < 0 ? -(nb % 10) : (nb % 10));
	recursive(nb / 10);
	write(1, &ch, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
		write(1, "-", 1);
	if (!nb)
		write(1, "0", 1);
	recursive(nb);
}
