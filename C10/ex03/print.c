#include "ex03.h"

void	ft_print()
{
	if (ft_strcmp(g_buff_cur, g_buff_prev))
		ft_putstr("*\n");
	else
	{
		ft_print_address(7 + g_mode, g_address);
		ft_trans_hexa(g_buff_cur, 8 * (g_idx / 8) + g_idx);
		ft_trans_hexa(g_buff_cur + 8, g_idx - 8);
		if (g_mode)
			ft_print_char(g_buff_cur, g_idx);
		ft_putstr("\n");
		free(g_buff_prev);
		g_buff_prev = g_buff_cur;
		g_buff_cur = (char *)malloc(17);
	}
	g_address += g_idx;
	g_idx = 0;
}

void	ft_print_address(int add_sz, int address)
{
	unsigned char ch;

	ch = '0' + (address % 16);
	ch += ch > '9' ? 39 : 0;
	if (!address)
	{
		while (address--)
			ft_putstr("0");
		if (g_mode)
			ft_putstr("0");
		return ;
	}
	ft_print_address(address - 1, address / 16);
	ft_putstr(ch);
}

void	ft_print_address(int add_sz, int address)
{
	unsigned char ch;

	ch = '0' + (address % 16);
	ch += ch > '9' ? 39 : 0;
	if (!address)
	{
		while (add_sz--)
			ft_putstr("0");
		if (g_mode)
			ft_putstr("0");
		return ;
	}
	ft_print_address(add_sz - 1, address / 16);
	ft_putstr(ch);
}

void	ft_print_char(char *s, int len)
{
	int idx;

	idx = -1;
	ft_putstr("  |");
	while (++idx < len)
	{
		if (*s >= ' ' && *s <= '~')
			ft_putstr(*s);
		else 
			ft_putstr(".");
	}
	ft_putstr("|");
}

void	ft_trans_hexa(char *buff, int len)
{
	char	ch;
	int		idx;

	idx = -1;
	if (g_mode)
		ft_putstr(" ");
	while (++idx < len && idx < 8)
	{
		ft_putstr(" ");
		ch = (buff[idx] / 16) + '0';
		ch += ch > '9' ? 39 : 0;
		ft_putstr(ch);
		ch = (buff[idx] % 16) + '0';
		ch += ch > '9' ? 39 : 0;
		ft_putstr(ch);
	}
	while (idx ++ < 8)
		ft_putstr("   ");
}

void	ft_err_msg(char *file)
{
	ft_putstr(basename(g_base_name));
	ft_putstr(": ");
	ft_putstr(file);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	errno = 0;
}