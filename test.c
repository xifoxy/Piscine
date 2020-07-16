/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <xifoxy.ru@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 08:13:55 by okim              #+#    #+#             */
/*   Updated: 2020/07/16 22:18:36 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_base(char *base)
{
	int	i;
	int j;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		len_of_str(char *str)
{
	int	len;
	len = 0;
	while (str[len])
		len++;
	return (len);
}
void	print_base(int nbr, char *base, int len_base)
{
	if (nbr / len_base < 1)
	{
		write(1, &base[nbr], 1);
	}
	else
	{
		print_base(nbr / len_base, base, len_base);
		write(1, &base[nbr % len_base], 1);
	}
}
void	ft_putnbr_base(int nbr, char *base)
{
	int	len_of_base;
	if (check_base(base))
		return ;
	len_of_base = len_of_str(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		print_base(nbr / len_of_base * -1, base, len_of_base);
		write(1, &base[nbr % len_of_base * -1], 1);
		return ;
	}
	print_base(nbr, base, len_of_base);
}

int main(){
	ft_putnbr_base(-255, "0123456789abcdef");
}
