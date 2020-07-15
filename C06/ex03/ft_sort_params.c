/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xifoxy <xifoxy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 00:51:55 by xifoxy            #+#    #+#             */
/*   Updated: 2020/07/15 20:12:14 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort(int ac, char **ag)
{
	int		x;
	int		y;
	char	*temp;

	x = 0;
	while (++x < ac)
	{
		y = 1;
		while (++y < ac)
		{
			if (ft_strcmp(ag[y - 1], ag[y]) < 0)
			{
				temp = ag[y - 1];
				ag[y - 1] = ag[y];
				ag[y] = temp;
			}
		}
	}
}

int		main(int ac, char **ag)
{
	ft_sort(ac, ag);
	while (--ac)
	{
		while (*ag[ac])
			write(1, ag[ac]++, 1);
		write(1, "\n", 1);
	}
	return (0);
}
