/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 08:13:08 by sgang             #+#    #+#             */
/*   Updated: 2020/07/21 08:13:08 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
    t_list *prev;
    
    while (begin_list)
    {
        prev = begin_list;
        free_fct(begin_list->data);
        begin_list = begin_list->next;
        free(begin_list);
    }
}
