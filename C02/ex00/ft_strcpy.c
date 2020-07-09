/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:36:36 by sgang             #+#    #+#             */
/*   Updated: 2020/07/09 20:07:44 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int idx;

	idx = 0;
	while (src[idx])
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = 0;
	return (dest);
}
