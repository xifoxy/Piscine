/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xifoxy <xifoxy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 01:12:31 by xifoxy            #+#    #+#             */
/*   Updated: 2020/07/15 01:12:31 by xifoxy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *str_cat(char *d, char *s)
{
    while (*s)
        *d++ = *s++;
    return (d);
}

int     get_len(char *str)
{
    int i;

    i = 0;
    while (str[i])
        ++i;
    return (i);
}

char    *ft_strjoin(int size, char **strs, char *sep)
{
    char    *ret;
    char    *temp;
    int     str_len;
    int     sep_len;
    int     idx;

    if (!size)
    {
        ret = (char*)malloc(sizeof(char));
        *ret = 0;
        return (ret);
    }
    str_len = 0;
    idx = -1;
    while (++idx < size)
        str_len += get_len(strs[idx]);
    sep_len = get_len(sep);
    ret = (char*)malloc((size - 1) * sep_len + str_len + 1);
    temp = str_cat(ret, strs[0]);
    idx = 1;
    while (idx < size)
    {
        temp = str_cat(temp, sep);
        temp = str_cat(temp, strs[idx]);
        ++idx;
    }
    *temp = 0;
    return (ret);
}
