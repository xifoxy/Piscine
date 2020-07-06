/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:04:08 by sgang             #+#    #+#             */
/*   Updated: 2020/07/06 18:16:13 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	islower(char ch)
{
	return (ch >= 'a' && ch <= 'z');
}

int	ft_str_is_lowercase(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
		if (!islower(str[idx++]))
			return (0);
	return (1);
}
