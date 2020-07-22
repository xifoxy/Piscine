#include <unistd.h>
#include <libgen.h>
#include <stdlib.h>
#include <fcntl.h>
#include <error.h>
#include <stdio.h>

int		g_mode;
int		g_idx;
int		g_address;
char	*g_buff_prev;
char	*g_buff_cur;
char	*g_base_name;

void	ft_read_file(char *file, int fd)
{
	int flag;

	flag = 1;
	while (read(fd, &g_buff_cur[g_idx++], 1))
	{
		flag = 0;
		if (errno)
		{
			ft_err_msg(file);
			break;
		}
		if (g_idx == 16)
			print();
	}
	if (flag)
	{
		errno = 9;
		ft_err_msg(file);
	}
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

	idx = 0;
	while (read(0, &g_buff_cur[idx % 16], 1))
		if (idx && idx == 16)
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