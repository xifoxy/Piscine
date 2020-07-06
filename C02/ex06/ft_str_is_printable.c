/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:14:17 by sgang             #+#    #+#             */
/*   Updated: 2020/07/06 18:17:25 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isprint(char ch)
{
	return (ch >= ' ' && ch <= '~');
}

int	ft_str_is_printable(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
		if (!isprint(str[idx++]))
			return (0);
	return (1);
}
