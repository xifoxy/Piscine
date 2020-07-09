/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:52:18 by sgang             #+#    #+#             */
/*   Updated: 2020/07/09 19:03:33 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int	ft_str_is_alpha(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
		if (!is_alpha(str[idx++]))
			return (0);
	return (1);
}
