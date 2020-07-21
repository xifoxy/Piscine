/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:57:00 by sgang             #+#    #+#             */
/*   Updated: 2020/07/09 15:46:03 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char g_buf[10];

void	sol(int prev, int depth, int n)
{
	int i;

	if (depth == n)
	{
		write(1, g_buf, n);
		write(1, ", ", 2);
		return ;
	}
	i = prev;
	while (++i < 10)
	{
		g_buf[depth] = '0' + i;
		sol(i, depth + 1, n);
	}
}

void	ft_print_combn(int n)
{
	int i;

	i = -1;
	while (++i < 10 - n)
	{
		g_buf[0] = '0' + i;
		sol(i, 1, n);
	}
	i = -1;
	while (++i < n)
		g_buf[i] = '0' + (10 - n + i);
	write(1, g_buf, n);
}
