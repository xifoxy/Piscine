/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 01:12:27 by xifoxy            #+#    #+#             */
/*   Updated: 2020/07/16 14:47:58 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *ret;
	int *temp;

	if (min >= max || !(ret = (int*)malloc(sizeof(int) * (max - min))))
		return (0);
	temp = ret;
	while (min < max)
		*(temp++) = min++;
	return (ret);
}
