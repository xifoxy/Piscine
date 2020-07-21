/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 14:26:15 by sgang             #+#    #+#             */
/*   Updated: 2020/07/21 14:26:15 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree *btree_create_node(void *item);
{
    t_btree *ret;

    ret = (t_btree *)malloc(sizeof(t_btree));
    ret->item = data;
    ret->left = 0;
    ret->right = 0;
    return (ret);
}