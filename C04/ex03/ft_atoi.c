/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 15:50:09 by sgang             #+#    #+#             */
/*   Updated: 2020/07/14 17:41:38 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_white_space(char ch)
{
	return ((ch >= 9 && ch <= 13) || ch == ' ');
}

int	ft_atoi(char *str)
{
	long long	ret;
	int			mark;

	ret = 0;
	mark = 1;
	while (is_white_space(*str))
		++str;
	while ((*str == '-' || *str == '+'))
	{
		if (*str == '-')
			mark *= -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
	{
		ret = (ret * 10) + (*str++ - '0');
	}
	return (ret * mark);
}
