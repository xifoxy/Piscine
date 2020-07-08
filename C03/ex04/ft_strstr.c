/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 23:24:54 by sgang             #+#    #+#             */
/*   Updated: 2020/07/08 23:38:51 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *src;
	char *find;

	if (!*to_find)
		return (str);
	while (*str)
	{
		src = str;
		find = to_find;
		while (*find && (*src == *find))
		{
			src -= -1;
			find -= -1;
		}
		if (!(*find))
			return (str);
		str -= -1;
	}
	return (0);
}
