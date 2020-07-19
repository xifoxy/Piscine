/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:06:34 by sgang             #+#    #+#             */
/*   Updated: 2020/07/19 20:06:34 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		g_eof;
int		g_fd;
char	*g_line;

char	*read_num(void)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char*)malloc(MAX_LEN + 1);
	while ((read(0, &ret[i], 1)))
	{
		if (i == MAX_LEN)
		{
			free(ret);
			g_input_num_error = 1;
			err_msg(2);
			return (0);
		}
		if (ret[i] == '\n')
		{
			ret[i] = 0;
			break ;
		}
		++i;
	}
	return (trim_allocated_str(ret));
}


char	*read_file(int fd)
{
	int		idx;
	char	*ret;

	idx = 0;
	ret = (char*)malloc(MAX_LEN + 1);
	while ((read(fd, &ret[idx], 1)))
	{
		g_eof = 0;
		if (idx == MAX_LEN)
		{
			free(ret);
			g_read_error = 1;
			return (0);
		}
		if (ret[idx] == '\n')
		{
			ret[idx] = 0;
			break ;
		}
		++idx;
	}
	return (ret);
}

int		init(char *filename)
{
	int	ret;

	ret = 0;
	if ((g_fd = open(filename, O_RDONLY)) == -1)
		return (1);
	g_eof = 1;
	while ((g_line = read_file(g_fd)) && !ret)
	{
		if (g_eof++)
			break ;
		if (!*g_line)
			continue ;
		if (is_valid_key_value(g_line))
			list_insert(g_line);
		else
			ret = 2;
	}
	close(g_fd);
	ret = g_read_error ? 2 : ret;
	return (ret);
}

int	build_dict(int ac, char **ag)
{
	int msg;

	msg = 0;
	if (ac > 3)
		msg = 1;
	else if (ac == 2)
		msg = init(DEFAULT_DICT);
	else
		msg = init(ag[1]);
	return (msg);
}

