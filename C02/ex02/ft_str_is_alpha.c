/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:52:18 by sgang             #+#    #+#             */
/*   Updated: 2020/07/08 17:52:26 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isalpha(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int	ft_str_is_alpha(char *str)
{
	int idx;

	idx = 0;
	while (str[idx])
		if (!isalpha[idx++])
			return (0);
	return (1);
}
