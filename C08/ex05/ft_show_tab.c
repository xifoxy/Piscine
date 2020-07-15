/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xifoxy <xifoxy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 01:25:15 by xifoxy            #+#    #+#             */
/*   Updated: 2020/07/16 01:25:15 by xifoxy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void    ft_print_size(int sz)
{
    char ch;

    if (!sz)
        return ;
    ch = '0' + sz % 10;
    get_size(sz / 10);
    write(1, &ch, 1);
}

void    ft_print_struct(struct s_stock_str info)
{
    write(1, info.str, info.size);
    write(1, "\n", 1);
    if (info.size)
        ft_print_size(info.size);
    else
        write(1, "0", 1);
    write(1, "\n", 1);
    write(1, info.copy, info.size);
    write(1, "\n", 1);
}

void    ft_show_tab(struct s_stock_str *par)
{
    int i;

    i = 0;
    while(par[i].str)
    {
        ft_print_struct(par[i]);
        ++i;      
    }
}