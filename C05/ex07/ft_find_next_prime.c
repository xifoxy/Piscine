/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xifoxy <xifoxy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:27:55 by xifoxy            #+#    #+#             */
/*   Updated: 2020/07/15 23:14:47 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long idx;

	if (nb < 2)
		return (0);
	if (nb < 4)
		return (1);
	if (!(nb % 2) || !(nb % 3))
		return (0);
	idx = 3;
	while (idx * idx <= nb){
		if (!(nb % 2) || !(nb % 3) || !(nb % idx))
			return (0);
		idx += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int idx;

	idx = nb;
	while (!ft_is_prime(idx))
		++idx;
	return (idx);
}
