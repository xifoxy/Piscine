/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:50:12 by sgang             #+#    #+#             */
/*   Updated: 2020/07/09 20:04:44 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int idx;

	idx = 0;
	while (idx + 1 < size && src[idx])
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = 0;
	while (src[idx])
		++idx;
	return (idx);
}
