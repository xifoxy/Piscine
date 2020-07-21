/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 08:13:03 by sgang             #+#    #+#             */
/*   Updated: 2020/07/21 08:13:03 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list *ft_list_push_strs(int size, char **strs)
{
    t_list  *r;
    t_list  *t;
    int     i;

    r = 0;
    i = -1;
    while (++i < size)
    {
        t = r;
        r = ft_create_elem(strs[i]);
        r->next = t;
    }
    return (r);
}