int ft_is_sort(int *tab, int length, int(*f)(int, int))
{
    int bef;
    int cur;
    int idx;

    idx = 0;
    bef = 0;
    while (idx + 1 < length)
    {
        cur = f(tab[idx], tab[idx + 1]);
        if (cur == 0)
            continue;
        if (bef == 0)
            bef = cur;
        else if ((bef < 0 && cur > 0) || (bef > 0 && cur < 0))
            return (0);
    }
    return (1);
}