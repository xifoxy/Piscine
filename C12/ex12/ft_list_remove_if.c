/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 08:58:58 by sgang             #+#    #+#             */
/*   Updated: 2020/07/21 08:58:58 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void    freee(t_list *bye ,void (*free_fct)(void *))
{
    free_fct(bye->data);
    free(bye);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
    t_list *cur;
    t_list *pre;
    t_list *t;

    pre = 0;
    cur = *begin_list;
    while (cur)
    {
        if ((*cmp)(cur->data, data_ref) == 0)
        {
            if (cur == *begin_list)
                *begin_list = cur->next;
            else
                pre->next = cur->next;
            t = cur;
            cur = cur->next;
            free_fct(t);
            free(t);
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
}