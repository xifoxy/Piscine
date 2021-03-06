/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:42:41 by sgang             #+#    #+#             */
/*   Updated: 2020/07/14 22:11:12 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	recur(int num)
{
	char ch;

	if (!num)
		return ;
	ch = (num < 0 ? -(num % 10) : (num % 10)) + '0';
	recur(num / 10);
	ft_putchar(ch);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
		write(1, "-", 1);
	if (!nb)
		write(1, "0", 1);
	recur(nb);
}
