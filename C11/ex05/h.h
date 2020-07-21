/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 01:14:13 by sgang             #+#    #+#             */
/*   Updated: 2020/07/22 02:42:56 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_H
# define H_H

# include <unistd.h>

# define ERR_DIV "Stop : division by zero"
# define ERR_MOD "Stop : modulo by zero"

int		mul(int a, int b);
int		div(int a, int b);
int		mod(int a, int b);
int		sum(int a, int b);
int		sub(int a, int b);
void	putstr(char *str);
int		is_valid(char o);
void	recursive(int nb);
void	ft_putnbr(int nb);

#endif
