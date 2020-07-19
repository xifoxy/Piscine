/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 20:06:29 by sgang             #+#    #+#             */
/*   Updated: 2020/07/19 20:06:29 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define ERROR "Error\n"
# define DICT_ERR "Dict Error\n"
# define DEFAULT_DICT "diction/number.dict"
# define VALID_NUM_LEN 39
# define MAX_LEN 1024

typedef struct		_dic
{
	char			*key;
	char			*value;
	struct _dic     *next;
}					dic;

extern dic *g_dict;
extern int g_read_error;
extern int g_input_num_error;
extern int g_is_first;
extern int g_eof;

void				list_insert(char *str);
char				*get_val(char *key);
dic 				*create_ele(char *key, char *val);
void				push(char *key, char *val);
void				free_dict();

int					build_dict(int ac, char **ag);
int					init(char *filename);
char				*read_file(int fd);
char				*read_num(void);


char				*trim_allocated_str(char *str);
char				*trim_left(char *str);
void				trim_right(char *str);
char				*trim_side(char *str);

int					ft_strlen(char *str);
void				ft_strcpy(char *dst, char *begin, char *end);
int					ft_strcmp(char *s1, char *s2);


void				print(char *str);
void				ft_putstr(char *str);
void				err_msg(int err_no);

int					is_space(char ch);
int					is_num(char ch);
int					is_valid_num(char *str);
int					is_valid_key_value(char *str);

void				unit_process(int idx);
void				rush(int ac, char **ag);
void				convert_num(char *num);
char				*build_unit_str(int cnt);
int					num_process(int idx, char *num, char *tmp);

#endif
