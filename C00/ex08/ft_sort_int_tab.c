/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang </var/mail/sgang>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 23:18:24 by sgang             #+#    #+#             */
/*   Updated: 2020/07/04 23:51:42 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_sort_int_tab(int *tab, int size)
{
	int temp;
	
	int i;
	int j;
	int least;
	i = 0;
	while(i < size)
	{
		least = j = i;
		while(++j < size)
			if(tab[j] < tab[least])
				least = j;
		temp = arr[least];
		arr[least] = arr[i];
		arr[i++] = temp;
	}
}

