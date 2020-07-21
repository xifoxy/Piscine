#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <libgen.h>
#include <errno.h>
#include <stdio.h>

int g_sz;
char *g_buff;

void	putstr(char *fi)
{
	int len;
	
	len = 0;
	while (fi[len])
		++len;
	write(1, fi, len);
}

void	err_msg(char *b_fi, char *fi)
{
	putstr(basename(b_fi));
	putstr(": ");
	putstr(fi);
	putstr(": ");
	putstr(strerror(errno));
	putstr("\n");
	errno = 0;
}

void	ft_file_read(int fd)
{
	int	idx;
	int mod;

	idx = -1;
	if (g_sz == 0){
		while (read(fd, g_buff, 1))
			if (errno)
				return ;
		return ;
	}
	while (read(fd, &g_buff[++idx % g_sz], 1))
		if (errno)
			return ;
	mod = idx % g_sz;
	if (idx >= g_sz)
		write(1, g_buff + mod, g_sz - mod);
	write(1, g_buff, mod);
}

void	ft_tail(int ac, char **ag)
{
	int idx;
	int fd;

	idx = 2;
	while (++idx  < ac)
	{
		if ((fd = open(ag[idx], O_RDONLY)) == -1)
		{
			err_msg(ag[0], ag[idx]);
			continue ;
		}
		if (idx != 3 && idx <= ac - 1)
			putstr("\n");
		if (ac > 4){
			putstr("==> ");
			putstr(ag[idx]);
			putstr(" <==\n");
		}
		ft_file_read(fd);
		close(fd);
	}
}

int		main(int ac, char **ag)
{
	char *temp;

	temp = ag[2];
	g_sz = 0;
	while(*temp)
		g_sz = g_sz * 10 + (*temp++ - '0');
	g_buff = (char *)malloc(sizeof(char) * g_sz);
	ac == 3 ? ft_file_read(0) : ft_tail(ac, ag);
	free(g_buff);
	return (0);
}
