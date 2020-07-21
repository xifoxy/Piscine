int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

int get_sz(char **tab)
{
	int ret;

	ret = 0;
	while (tab[ret])
		++ret;
	return(ret);
}

void ft_sort_string_tab(char **tab)
{
	char	*temp;
	int		x;
	int		y;
	int		tab_sz;

	tab_sz = get_sz(tab);
	x = 0;
	while (++x < tab_sz)
	{
		y = 0;
		while (++y < tab_sz)
		{
			if (ft_strcmp(tab[y - 1], tab[y]) > 0)
			{
				temp = tab[y - 1];
				tab[y - 1] = tab[y];
				tab[y] = temp;
			}
		}
	}
}
