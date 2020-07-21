#include <unistd.h>
#include <libgen.h>
#include <stdlib.h>
#include <fcntl.h>
#include <error.h>
#include <stdio.h>

int g_mode;
int g_address;
char *g_buff_prev;
char *g_buff_cur;
char *g_base_name;

void	ft_putstr(char *str)
{
	int len;

	len = 0;
	while (str[len])
		++len;
	write(1, str, len);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
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

void ft_print_char(char *s, int len)
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

void	ft_print(int wcnt)
{
	if (ft_strcmp(g_buff_cur, g_buff_prev))
		ft_putstr("*\n");
	else
	{
		ft_print_address(7 + g_mode, g_address);
		ft_trans_hexa(g_buff_cur, 8 * (wcnt / 8) + wcnt);
		ft_trans_hexa(g_buff_cur + 8, wcnt - 8);
		if (g_mode)
			ft_print_char(g_buff_cur, wcnt);
		ft_putstr("\n");
		free(g_buff_prev);
		g_buff_prev = g_buff_cur;
		g_buff_cur = (char *)malloc(17);
	}
	g_address += wcnt;
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

void	ft_read_file(char *file, int fd)
{
	int idx;

	idx = -1;
	while (read(fd, &g_buff_cur[++idx % 16], 1))
	{
		if (errno)
		{
			ft_err_msg(file);
			break;
		}
		if (idx && !(idx % 16))
			ft_print(16);
	}
	if (idx % 16)
		ft_print(idx % 16);

}

void	ft_hexdump_file(int ac, char **ag)
{
	int idx;
	int fd;

	idx = g_mode ? 1 : 0;
	while (++idx < ac)
	{
		if ((fd = open(ag[idx], O_RDONLY) == -1))
		{
			ft_err_msg(ag[idx]);
			continue;
		}
		ft_read_file(ag[idx], fd);
	}
}

void	ft_hexdump_std(void)
{
	int idx;

	idx = -1;
	while (read(0, &g_buff_cur[++idx % 16], 1))
		if (idx && !(idx % 16))
			ft_print(16);
}

void	init(int ac, char **ag)
{
	g_base_name = ag[0];
	g_buff_cur = (char *)malloc(17);
	g_buff_prev = (char *)malloc(17);
	if (ac > 1 && ag[1][0] == '-' && ag[1][1] == 'C')
		g_mode = 1;
	if (ac == 1 || (ac == 2 && g_mode))
		ft_hexdump_std();
	else
		ft_hexdump_file(ac, ag);
	free(g_buff_cur);
}

int		main(int ac, char **ag)
{
	(void)ac;
	init(ac, ag);
	return (0);
}