/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:06:48 by sgang             #+#    #+#             */
/*   Updated: 2020/07/19 20:06:48 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

dic *g_dict;
char *g_num;
int g_unit3;
int g_unit2;
int g_is_first;
int g_input_num_error;
int g_read_error;

char	*build_unit_str(int cnt)
{
	char	*ret;
	int		i;

	ret = (char*)malloc(cnt + 2);
	ret[cnt + 1] = 0;
	ret[0] = '1';
	i = cnt;
	while (i > 0)
		ret[i--] = '0';
	return (ret);
}

void	unit_process(int idx)
{
	char	*unit_str;

	if (g_unit3 && idx % 3 == 0)
	{
		unit_str = build_unit_str(idx);
		print(get_val(unit_str));
		free(unit_str);
		g_unit3 = 0;
	}
	else if (g_unit2 && idx % 3 == 2)
		print(get_val("100"));
}

int		num_process(int idx, char *num, char *tmp)
{
	int ret;

	ret = 0;
	if (*num != '0')
	{
		g_unit3 = 1;
		g_unit2 = 1;
		tmp[0] = *num;
		if (idx % 3 == 2)
		{
			if (*num == '1' && *(num + 1) != '0')
			{
				tmp[1] = *(num + 1);
				++ret;
			}
			else
				tmp[1] = '0';
		}
		else
			tmp[1] = 0;
		print(get_val(tmp));
	}
	else
		g_unit2 = 0;
	return (ret);
}

void	convert_num(char *num)
{
	int		idx;
	char	*tmp;
	int		offset;

	if (num[0] == '0')
		print(get_val("0"));
	else
	{
		tmp = (char*)malloc(3);
		tmp[2] = 0;
		g_unit3 = 0;
		g_unit2 = 0;
		idx = ft_strlen(num);
		while (idx)
		{
			unit_process(idx);
			offset = num_process(idx, num, tmp);
			num += (1 + offset);
			idx -= (1 + offset);
		}
		free(tmp);
	}
	ft_putstr("\n");
}

void	rush(int ac, char **ag)
{
	int err_no;

	err_no = build_dict(ac, ag);
	if (err_no)
	{
		err_msg(err_no);
		return ;
	}
	if (ac == 2)
		g_num = trim_side(ag[1]);
	else
		g_num = trim_side(ag[2]);
	if (!g_input_num_error && !is_valid_num(g_num))
		err_msg(2);
	else if (!g_input_num_error)
	{
		// if (ft_strlen(g_num) > VALID_NUM_LEN)
		// 	err_msg(2);
		// else
			convert_num(g_num);
	}
	free(g_num);
}
