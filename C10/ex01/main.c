#include <fcntl.h>
#include <errno.h>
#include <libgen.h>
#include <unistd.h>

void	putstr(char *str)
{
	int len;

	len = 0;
	while (str[len])
		++len;
	write(1, str, len);
}

void	err_msg(char *fi)
{
	putstr(basename(fi));
	putstr(": ");
	putstr(fi);
	putstr(": ");
	putstr(strerror(errno));
	putstr("\n");
	errno = 0;
}

void	ft_file_read(int fd, char *ag)
{
	int				sz;
	unsigned char	buf;

	while ((sz = read(fd, &buf, 1)))
	{
		if (errno)
		{
			err_msg(ag);
			return ;
		}
		write(1, &buf, 1);
	}
}

int		main(int ac, char **ag)
{	
	int fd;
	int idx;

	if (ac == 1)
		ft_file_read(0, ag[0]);	
	else
	{
		idx = 0;
		while (++idx < ac)
		{
			if (idx != 1)
				putstr("\n");
			if ((fd = open(ag[idx], O_RDONLY)) == -1)
			{
				err_msg(ag[idx]);
				continue ;
			}
			ft_file_read(fd, ag[idx]);
			close(fd);
		}
	}
	return (0);
}