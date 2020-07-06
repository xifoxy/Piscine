/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:16:06 by sgang             #+#    #+#             */
/*   Updated: 2020/07/06 17:18:16 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int temp;
	int i;
	int j;
	int least;

	i = 0;
	while (i < size)
	{
		least = i;
		j = i;
		while (++j < size)
			if (tab[j] < tab[least])
				least = j;
		temp = arr[least];
		arr[least] = arr[i];
		arr[i++] = temp;
	}
}
