/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 21:28:33 by xifoxy            #+#    #+#             */
/*   Updated: 2020/07/15 23:39:57 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long idx;

	if (nb < 2)
		return (0);
	if (nb < 4)
		return (1);
	if (nb % 2 || nb % 3)
		return (0);
	idx = 5;
	while (idx * idx <= nb)
		if (nb % idx == 0)
			return (0);
	return (1);
}
