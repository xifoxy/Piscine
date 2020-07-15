/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:25:15 by sgang             #+#    #+#             */
/*   Updated: 2020/07/15 21:43:49 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int ret;

	if (nb < 0)
		return (0);
	if (!nb)
		return (1);
	ret = 1;
	while (nb)
		ret *= (nb--);
	return (ret);
}
