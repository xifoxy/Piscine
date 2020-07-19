/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:06:59 by sgang             #+#    #+#             */
/*   Updated: 2020/07/19 20:06:59 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_putstr(char *str)
{
	int len;

	len = ft_strlen(str);
	write(1, str, len);
}

void	err_msg(int err_no)
{
	if (err_no == 1)
		ft_putstr(ERROR);
	if (err_no == 2)
		ft_putstr(DICT_ERR);
}

void	print(char *str)
{
	if (!g_is_first)
		ft_putstr(" ");
	g_is_first = 0;
	ft_putstr(str);
}
