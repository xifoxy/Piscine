/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:25:55 by sgang             #+#    #+#             */
/*   Updated: 2020/07/09 19:02:54 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_lower(char ch)
{
	return (ch >= 'a' && ch <= 'z');
}

char	*ft_strupcase(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
	{
		if (is_lower(str[idx]))
			str[idx] += -32;
		++idx;
	}
	return (str);
}
