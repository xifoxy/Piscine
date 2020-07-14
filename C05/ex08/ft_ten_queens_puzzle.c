#include <unistd.h>
char g_buf[11];
int g_incre[19];
int g_decre[19];
int g_col[19];

int recursive(int depth)
{
    int idx;
    int ret;

    if (depth == 10)
    {
        write(1, g_buf, 11);
        return 1;
    }
    ret = 0;
    idx = -1;
    while (++idx < 10)
    {
        if (g_col[idx] || g_incre[idx + depth] || g_decre[10 - 1 + depth - idx])
            continue;
        g_col[idx] = 1;
        g_incre[idx + depth] = 1;
        g_decre[10 - 1 + depth - idx] = 1;
        g_buf[depth] = idx + '0';
        ret += recursive(depth + 1);
        g_col[idx] = 0;
        g_incre[idx + depth] = 0;
        g_decre[10 - 1 + depth - idx] = 0;
    }
    return ret;
}

int ft_ten_queens_puzzle(void)
{
    g_buf[10] = '\n';
    return recursive(0);
}
