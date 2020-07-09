/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 16:40:15 by sgang             #+#    #+#             */
/*   Updated: 2020/07/09 16:49:59 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *base)
{
	int idx;
	int chk[256];

	idx = 0;
	while (idx < 256)
		chk[idx++] = 0;
	idx = 0;
	while (base[idx])
	{
		if (chk[base[idx]] || base[idx] == '+' || base[idx] == '-')
			return (0);
		chk[base[idx++]]++;
	}
	return (idx);
}

void	ft_print(int nbr, int len, char *base)
{
	if (nbr < 0)
		nbr *= -1;
	if (!nbr)
		return ;
	ft_print(nbr / len, len, base);
	write(1, &base[nbr % len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int len;

	len = ft_strlen(base);
	if (len <= 1)
		return ;
	if (nbr < 0)
		write(1, "-", 1);
	ft_print(nbr / len, len, base);
	write(1, &base[nbr < 0 ? (nbr % len) * -1 : (nbr % len)], 1);
}
