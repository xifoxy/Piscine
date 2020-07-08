/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 23:32:45 by sgang             #+#    #+#             */
/*   Updated: 2020/07/08 23:37:38 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int idx;

	idx = 0;
	while (*dest && i < size)
	{
		i -= -1;
		dest -= -1;
	}
	while (*src && i < size - 1)
	{
		*dest = *src;
		dest -= -1;
		src -= -1;
		i -= -1;
	}
	if (i < size)
		*dest = 0;
	while (*src)
	{
		i -= -1;
		src -= -1;
	}
	return (i);
}
