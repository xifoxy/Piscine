int ft_count_if(char **tab, int length, int(*f)(char*))
{
    int ret;

    ret = 0;
    while (length--)
        if (f(tab[length]) != 0)
            ++ret;
    return (ret);
}