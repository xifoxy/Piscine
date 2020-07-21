/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 09:18:41 by sgang             #+#    #+#             */
/*   Updated: 2020/07/21 09:18:41 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*c;
	t_list	*p;
	void	*temp;
	
	if (!begin_list)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	p = *begin_list;
	c = p->next;
	while (c && (cmp(c->data, data) < 0))
	{
		p = c;
		c = c->next;
	}
	p->next = ft_create_elem(data);
	p->next->next = c;
}