/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 21:37:19 by sgang             #+#    #+#             */
/*   Updated: 2020/07/08 23:00:53 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char g_str[16];

void	ft_print(char ch)
{
	write(1, &ch, 1);
}

void	ft_translation_hex(char ch)
{
	ch += '0';
	ch += ch > '9' ? 39 : 0;
	ft_print(ch);
}

void	ft_make_addr(long long ptr, int cnt)
{
	char ch;

	if (!ptr)
	{
		while (cnt < 16)
		{
			++cnt;
			write(1, "0", 1);
		}
		return ;
	}
	ft_make_addr(ptr / 16, cnt + 1);
	ft_translation_hex(ptr % 16);
}

void	ft_translation_addr(unsigned char *ptr, unsigned int len)
{
	unsigned int idx;

	idx = 0;
	while (idx < len)
	{
		if (!(idx % 2))
			ft_print(' ');
		if (ptr[idx] >= ' ' && ptr[idx] <= '~')
			g_str[idx] = ptr[idx];
		else
			g_str[idx] = '.';
		ft_translation_hex(ptr[idx] / 16);
		ft_translation_hex(ptr[idx] % 16);
		++idx;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int idx;
	unsigned int len;
	unsigned char *ptr;

	idx = 0;
	while (size)
	{
		if (size / 16)
			len = 16;
		else
			len = size;
		ptr = (unsigned char*)arr + idx;
		ft_make_addr((long long)ptr, 0);
		ft_print(':');
		ft_translation_addr(ptr, len);
		ft_print(' ');
		write(1, g_str, len);
		ft_print('\n');
		size += -len;
		i -= -16;
	}
	return (addr);
}
