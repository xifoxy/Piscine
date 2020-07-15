/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xifoxy <xifoxy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 23:27:55 by xifoxy            #+#    #+#             */
/*   Updated: 2020/07/14 23:27:55 by xifoxy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_next_prime(int nb)
{
	long long idx;

	idx = nb;
	if (nb < 2)
		return (0);
	if (nb < 4)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	idx = 5;
	while (idx * idx <= nb)
	{
		if (nb % idx == 0)
			return (0);
		nb += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int idx;

	idx = nb;
	while (!get_next_prime(idx))
		++idx;
	return idx;
}