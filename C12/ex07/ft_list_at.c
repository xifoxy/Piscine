/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 08:17:04 by sgang             #+#    #+#             */
/*   Updated: 2020/07/21 08:17:04 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
    unsigned int idx;

    idx = 0;
    while (idx < nbr)
    {
        if (!begin_list)
            return (0);
        begin_list = begin_list->next;
        ++idx;
    }
    return (begin_list);
}