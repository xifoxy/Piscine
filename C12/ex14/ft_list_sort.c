/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:03:17 by sgang             #+#    #+#             */
/*   Updated: 2020/07/21 09:03:17 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_sort(t_list **begin_list, int (*cmp)())
{
    t_list *t;
    t_list *c;

    if (!(*begin_list) || !begin_list)
        return ;
    c = *begin_list;
    while (c->next)
    {
        if ((*cmp)(c->next->data, c->data) < 0)
        {
            t = c->data;
            c->data = c->next->data;
            c->next->data = t;
            c = *begin_list;
        }
        else
            c = c->next;
        
    }
}