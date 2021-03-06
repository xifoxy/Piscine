/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 08:13:05 by sgang             #+#    #+#             */
/*   Updated: 2020/07/21 08:13:05 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct		list
{
	struct list		*next;
	void			*data;
}					t_list;

t_list				*ft_create_elem(void *data);

#endif
