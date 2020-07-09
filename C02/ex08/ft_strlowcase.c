/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:29:45 by sgang             #+#    #+#             */
/*   Updated: 2020/07/09 19:03:46 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_upper(char ch)
{
	return (ch >= 'A' && ch <= 'Z');
}

char	*ft_strlowcase(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
	{
		if (is_upper(str[idx]))
			str[idx] -= -32;
		++idx;
	}
	return (str);
}
