/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:00:16 by sgang             #+#    #+#             */
/*   Updated: 2020/07/06 18:15:44 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isnum(char ch)
{
	return (ch >= '0' && ch <= '9');
}

int	ft_str_is_numeric(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
		if (!isnum(str[idx++]))
			return (0);
	return (1);
}
