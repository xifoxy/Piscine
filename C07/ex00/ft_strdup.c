/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 01:12:22 by xifoxy            #+#    #+#             */
/*   Updated: 2020/07/16 14:47:29 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		idx;
	char	*ret;

	idx = 0;
	while (src[idx])
		++idx;
	ret = (char*)malloc(idx + 1);
	ret[idx] = 0;
	while (--idx >= 0)
		ret[idx] = src[idx];
	return (ret);
}
