/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:01:44 by sgang             #+#    #+#             */
/*   Updated: 2020/07/21 09:01:44 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *cur;

	cur = *begin_list1;
	if (!cur)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (cur->next)
		cur = cur->next;
	cur->next = begin_list2;
}
