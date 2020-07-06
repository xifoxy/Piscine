/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:29:45 by sgang             #+#    #+#             */
/*   Updated: 2020/07/06 18:34:50 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		isupper(char ch)
{
	return (ch >= 'A' && ch <= 'Z');
}

char	*ft_strlowcase(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
	{
		if (isupper(str[idx]))
			str[idx] -= -32;
		++idx;
	}
	return (str);
}
