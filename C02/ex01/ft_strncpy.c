/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:48:37 by sgang             #+#    #+#             */
/*   Updated: 2020/07/15 00:33:39 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int idx;

	idx = 0;
	while (idx < n && src[idx])
	{
		dest[idx] = src[idx];
		++idx;
	}
	while (idx < n)
	{
		dest[idx] = 0;
		++idx;
	}
	return (dest);
}
