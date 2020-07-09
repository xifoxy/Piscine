/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:14:17 by sgang             #+#    #+#             */
/*   Updated: 2020/07/09 19:02:29 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_print(char ch)
{
	return (ch >= ' ' && ch <= '~');
}

int	ft_str_is_printable(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
		if (!is_print(str[idx++]))
			return (0);
	return (1);
}
