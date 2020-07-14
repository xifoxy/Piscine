/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:25:15 by sgang             #+#    #+#             */
/*   Updated: 2020/07/13 22:29:19 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int ret;
	int idx;

	idx = 0;
	ret = 1;
	while (++idx <= nb)
		ret *= idx;
	return (ret);
}
