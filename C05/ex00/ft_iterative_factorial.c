/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:25:15 by sgang             #+#    #+#             */
/*   Updated: 2020/07/14 19:59:35 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int ret;
	int idx;

	if (nb < 0)
		return (0);
	idx = 0;
	ret = 1;
	while (++idx <= nb)
		ret *= idx;
	return (ret);
}
