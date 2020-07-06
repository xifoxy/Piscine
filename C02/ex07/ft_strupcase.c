/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:25:55 by sgang             #+#    #+#             */
/*   Updated: 2020/07/06 18:29:16 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		islower(char ch)
{
	return (ch >= 'a' && ch <= 'z');
}

char	*ft_strupcase(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
	{
		if (islower(str[idx]))
			str[idx] += -32;
		++idx;
	}
	return (str);
}
