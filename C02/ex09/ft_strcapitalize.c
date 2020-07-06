/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:35:21 by sgang             #+#    #+#             */
/*   Updated: 2020/07/06 18:44:21 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		islower(char ch)
{
	return (ch >= 'a' && ch <= 'z');
}

int		isfirst(char ch)
{
	return (islower(ch) || (ch >= 'A' && ch <= 'Z'));
}

char	*ft_strcapitalize(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
	{
		if (islower(str[idx]) && (idx == 0 || !isfirst(str[idx - 1])))
			str[idx] += -32;
		++idx;
	}
	return (str);
}
