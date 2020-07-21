/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 01:24:53 by sgang             #+#    #+#             */
/*   Updated: 2020/07/22 01:25:50 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_sz(char **tab)
{
	int ret;

	ret = 0;
	while (tab[ret])
		++ret;
	return (ret);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	*temp;
	int		x;
	int		y;
	int		tab_sz;

	tab_sz = get_sz(tab);
	x = 0;
	while (++x < tab_sz)
	{
		y = 0;
		while (++y < tab_sz)
		{
			if (cmp(tab[y - 1], tab[y]) > 0)
			{
				temp = tab[y - 1];
				tab[y - 1] = tab[y];
				tab[y] = temp;
			}
		}
	}
}
