/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:35:21 by sgang             #+#    #+#             */
/*   Updated: 2020/07/08 19:26:43 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_num(char ch)
{
	return (ch >= '0' && ch <= '9');
}

int		is_lower(char ch)
{
	return (ch >= 'a' && ch <= 'z');
}

int		is_upper(char ch)
{
	return (ch >= 'A' && ch <= 'Z');
}

int		is_word(char ch)
{
	return (is_num(ch) || is_lowr(ch) || is_upper(ch));
}

char	*ft_strcapitalize(char *str)
{
	int idx;

	idx = 1;
	if (is_lower(str[0]))
		str[idx] += -32;
	while (str[idx])
	{
		if (is_upper(str[idx]))
			str[idx] -= -32;
		if (is_word(str[idx - 1]))
			;
		else if (is_lower(str[idx]))
			str[idx] += -32;
		++idx;
	}
	return (str);
}
