/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 08:12:57 by sgang             #+#    #+#             */
/*   Updated: 2020/07/21 08:12:57 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_push_back(t_list **begin_list, void *data)
{
    t_list *d;
    t_list *p;
    d = ft_create_elem(data);
    if(!*begin_list)
    {
        *begin_list = d;
        return ;
    }
    p = *begin_list;
    while (p->next)
        p = p->next;
    p->next = d;    
}