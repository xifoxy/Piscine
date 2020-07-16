/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 01:12:29 by xifoxy            #+#    #+#             */
/*   Updated: 2020/07/16 14:48:51 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int ret;
	int *temp;

	if (max <= min)
		return (0);
	ret = max - min;
	if (!(*range = (int*)malloc(sizeof(int) * ret)))
		return (-1);
	temp = *range;
	while (max > min)
		*temp++ = min++;
	return (ret);
}
