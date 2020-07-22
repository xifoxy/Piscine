#include "total.h"

int		ft_atoi(char *str, int len)
{
	int ret;
	int idx;

	idx = -1;
	ret = 0;
	if (*str == '0')
		return (ret);
	while (++idx < len - 3)
	{
		if (!is_number(str[idx]))
			return (0);
		ret *= 10;
		ret += (str[idx] - '0');
	}
	return (ret);
}

void	ft_strncpy(char *dest, char *src, int sz)
{
	int idx;
	
	idx = -1;
	while (++idx < sz)
		*(dest++) = *(src++);
}

int		ft_strlen(char *s)
{
	int len;
	
	len = 0;
	while (s[len])
		++len;
	return (len);
}

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_putstr(char *str, int len)
{
	
	write(1, str, len);
}