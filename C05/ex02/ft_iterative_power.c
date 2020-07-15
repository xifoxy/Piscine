/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:26:02 by sgang             #+#    #+#             */
/*   Updated: 2020/07/15 23:28:38 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int ret;

	if (power < 1)
		return (power < 0 ? 0 : 1);
	ret = nb;
	while (--power)
		ret *= nb;
	return (ret);
}
