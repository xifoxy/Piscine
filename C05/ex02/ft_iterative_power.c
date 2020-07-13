/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:26:02 by sgang             #+#    #+#             */
/*   Updated: 2020/07/13 22:26:27 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int ret;
	int idx;

	idx = -1;
	ret = 1;
	while (++idx < power)
		ret *= nb;
	return (!nb ? 1 : ret);
}
