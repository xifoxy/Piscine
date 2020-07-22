/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 01:08:46 by sgang             #+#    #+#             */
/*   Updated: 2020/07/22 02:51:11 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int bef;
	int cur;
	int idx;

	idx = -1;
	bef = 0;
	while (++idx + 1 < length)
	{
		cur = f(tab[idx], tab[idx + 1]);
		if (cur == 0)
			continue;
		if (bef == 0)
			bef = cur;
		else if ((bef < 0 && cur > 0) || (bef > 0 && cur < 0))
			return (0);
	}
	return (1);
}
