/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:56:21 by sgang             #+#    #+#             */
/*   Updated: 2020/07/19 20:56:21 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*get_val(char *key)
{
	dic *tmp;

	tmp = g_dict;
	while (tmp)
	{
		if (ft_strcmp(tmp->key, key))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (0);
}

dic	*create_ele(char *key, char *val)
{
	dic *ret;

	ret = (dic*)malloc(sizeof(dic));
	ret->key = key;
	ret->value = val;
	ret->next = 0;
	return (ret);
}

void	push(char *key, char *val)
{
	dic *tmp;

	if (!g_dict)
		g_dict = create_ele(key, val);
	else
	{
		tmp = g_dict;
		g_dict = create_ele(key, val);
		g_dict->next = tmp;
	}
}

void	list_insert(char *str)
{
	char *key;
	char *val;
	char *ptr;
	char *tmp;

	tmp = str;
	ptr = str;
	while (*ptr != ':')
		++ptr;
	key = (char*)malloc(ptr - str + 1);
	ft_strcpy(key, str, ptr - 1);
	key = trim_allocated_str(key);
	val = ++ptr;
	str = val;
	while (*ptr)
		++ptr;
	val = (char*)malloc(ptr - val + 1);
	ft_strcpy(val, str, ptr - 1);
	val = trim_allocated_str(val);
	free(tmp);
	push(key, val);
}

void free_dict()
{
	dic *prev;
	while (g_dict != 0)
	{
		prev = g_dict;
		g_dict = g_dict->next;
		free(prev);
	}
}