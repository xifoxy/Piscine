/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xifoxy <xifoxy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 01:12:27 by xifoxy            #+#    #+#             */
/*   Updated: 2020/07/15 01:12:27 by xifoxy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int *ft_range(int min, int max)
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