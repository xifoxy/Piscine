/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:06:51 by sgang             #+#    #+#             */
/*   Updated: 2020/07/09 19:02:03 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_upper(char ch)
{
	return (ch >= 'A' && ch <= 'Z');
}

int	ft_str_is_uppercase(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
		if (!is_upper(str[idx++]))
			return (0);
	return (1);
}
