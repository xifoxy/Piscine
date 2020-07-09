/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:48:37 by sgang             #+#    #+#             */
/*   Updated: 2020/07/09 19:00:25 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int idx;

	idx = 0;
	while (idx < n && src[idx])
		dest[idx] = src[idx++];
	while (idx < n)
		dest[idx++] = 0;
	return (dest);
}
