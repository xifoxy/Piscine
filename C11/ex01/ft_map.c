/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 01:03:29 by sgang             #+#    #+#             */
/*   Updated: 2020/07/22 02:45:15 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int *ret;
	int idx;

	ret = (int*)malloc(sizeof(int) * length);
	idx = -1;
	while (++idx < length)
		ret[idx] = f(tab[idx]);
	return (ret);
}
