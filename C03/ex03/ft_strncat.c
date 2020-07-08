/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 23:18:53 by sgang             #+#    #+#             */
/*   Updated: 2020/07/08 23:27:14 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	while (*dest++)
		;
	dest--;
	while (nb--)
		if (!(*dest++ = *src++))
			return (dest);
	*dest = 0;
	return (dest);
}
