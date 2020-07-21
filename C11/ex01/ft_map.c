#include <stdlib.h>

int *ft_map(int *tab, int length, int(*f)(int))
{
    int *ret;
    int idx;

    ret = (int*)malloc(sizeof(int) * length);
    idx = -1;
    while(++idx < length)
        ret[idx] = f(tab[idx]);
    return (ret);
}