/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:57:00 by sgang             #+#    #+#             */
/*   Updated: 2020/07/06 17:20:39 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int g_num[10];

void	ft_print(int num, int depth)
{
	char ch;

	if (!depth)
		return ;
	ch = num % 10 + '0';
	ft_print(num / 10, depth - 1);
	write(1, &ch, 1);
}

void	sol(int idx, int sz, int depth, int num)
{
	if (depth == sz)
	{
		ft_print(num, depth);
		write(1, ", ", 2);
		return ;
	}
	while (idx < 9)
		sol(idx + 1, sz, depth + 1, num * 10 + g_num[idx++ + 1]);
}

void	ft_print_combn(int n)
{
	int i;
	int tmp;
	int last_num;

	i = 0;
	tmp = n;
	last_num = 0;
	while (i < 10)
		g_num[i++] = i;
	while (tmp)
		last_num = last_num * 10 + (10 - tmp--);
	sol(0, n - 1, 0, 0);
	ft_print(last_num, n);
}
