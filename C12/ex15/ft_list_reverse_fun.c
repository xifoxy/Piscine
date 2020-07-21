/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:12:34 by sgang             #+#    #+#             */
/*   Updated: 2020/07/21 09:12:34 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_reverse_fun(t_list *begin_list)
{
    t_list  *st;
    t_list  *nd;
    void    *temp;

    nd = 0;
    while (begin_list != nd)
    {
        st = begin_list;
        while (st->next != nd)
        {
            temp = st->data;
            st->data = st->next->data;
            st->next->data = temp;
            st = st->next;
        }
        nd = st;
    }
}