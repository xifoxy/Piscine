/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xifoxy <xifoxy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 01:12:29 by xifoxy            #+#    #+#             */
/*   Updated: 2020/07/15 01:12:29 by xifoxy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
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
        *(temp)++ = min++;
    return (ret);
}
