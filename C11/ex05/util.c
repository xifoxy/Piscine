void	putstr(char *str)
{
	int len;

	len = 0;
	while (str[len])
		++len;
	write(1, str, len);
}

int     is_valid(char o)
{
    return (o == '*' || o == '/' 
    || o == '%' || o ==  '+' || o == '-');
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
		putstr("-");
	if (!nb)
		putstr("0");
	recursive(nb);
}

void	recursive(int nb)
{
	char ch;

	if (!nb)
		return ;
	ch = '0';
	ch += (nb < 0 ? -(nb % 10) : (nb % 10));
	recursive(nb / 10);
	putstr(ch);
}