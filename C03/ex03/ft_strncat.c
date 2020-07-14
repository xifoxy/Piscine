/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 23:18:53 by sgang             #+#    #+#             */
/*   Updated: 2020/07/14 16:34:35 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char *s1;

	s1 = dest;
	while (*dest++)
		;
	dest--;
	while (nb--)
		if (!(*dest++ = *src++))
			return (s1);
	*dest = 0;
	return (s1);
}
