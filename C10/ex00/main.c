/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 23:21:29 by sgang             #+#    #+#             */
/*   Updated: 2020/07/19 23:21:29 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	int len;

	len = ft_strlen(str);
	write(1, str, len);
}

int		main(int ac, char **ag)
{
	char	ch;
	int		fd;
	int		ret;

	if (ac == 1)
		ft_putstr("File name missing.\n");
	else if (ac == 2)
	{
		fd = open(ag[1], O_RDONLY);
		if (fd == -1)
			ft_putstr("Cannot read file.\n");
		else
		{
			while ((ret = read(fd, &ch, 1)))
				write(1, &ch, 1);
			close(fd);
		}
	}
	else
		ft_putstr("Too many arguments.\n");
	return (0);
}