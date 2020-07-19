/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:06:52 by sgang             #+#    #+#             */
/*   Updated: 2020/07/19 20:06:52 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strcpy(char *dst, char *begin, char *end)
{
	while (begin <= end)
		*(dst++) = *(begin++);
	*dst = 0;
}

int		ft_strlen(char *str)
{
	int ret;

	ret = 0;
	while (str[ret])
		++ret;
	return (ret);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 == *s2);
}
