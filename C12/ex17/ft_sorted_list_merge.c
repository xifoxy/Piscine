/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:39:07 by sgang             #+#    #+#             */
/*   Updated: 2020/07/21 09:39:07 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_list.h"

void    ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
    if (!begin_list2)
        return ;
    if (!*begin_list1)
    {
        *begin_list1 = begin_list2;
        return ;
    }
    
}