/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:26:42 by sgang             #+#    #+#             */
/*   Updated: 2020/07/13 22:26:47 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (!nb || !power)
		return (1);
	if (nb < 0)
		return (0);
	return (nb * ft_recursive_power(nb, pwoer - 1));
}