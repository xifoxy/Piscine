/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 08:23:13 by sgang             #+#    #+#             */
/*   Updated: 2020/07/21 08:23:13 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_reverse(t_list **begin_list)
{
    t_list *cur;
    t_list *pre;
    t_list *t;

    if (!*begin_list || !(*begin_list)->next)
        return ;
    cur = (*begin_list)->next;
    pre = *begin_list;
    pre->next = 0;
    while (cur->next)
    {
        t = cur->next;
        cur->next = pre;
        pre = cur;
        cur = t;
    }
    cur->next = pre;
    *begin_list = cur;
}