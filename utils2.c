#include "minitalk.h"

void    ft_count(int *i, int *neg, const char *str)
{
    *i = 0;
    *neg = 1;
    while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
        *i += 1;
    if (str[*i] == '+' || str[*i] == '-')
    {
        if (str[*i] == '-')
            *neg *= -1;
        *i += 1;
    }
    while (str[*i] >= '0' && str[*i] <= '9')
        *i += 1;
}

int    ft_atoi(const char *str)
{
    int    i;
    int    multiplicator;
    int    num;
    int    neg;

    multiplicator = 1;
    num = 0;
    ft_count(&i, &neg, str);
    while (i > 0 && str[i - 1] >= '0' && str[i - 1] <= '9')
    {
        num += (str[i - 1] - '0') * multiplicator;
        multiplicator *= 10;
        i--;
    }
    return (num * neg);
}

void    *ft_calloc(size_t count, size_t size)
{
    char    *c;
    int        len;

    len = count * size;
    c = malloc(len);
    if (c == NULL)
        return (NULL);
    while (len > 0)
    {
        c[len - 1] = 0;
        len--;
    }
    return (c);
}

void    ft_print_server_menu(int pid)
{
        ft_putchar('\n');
        ft_putendl("\t\t\t\x1b[32mMINITALK\x1b[0m\t");
        ft_putendl("\t\t\x1b[32m=========================\t\t\x1b[0m");
        ft_putendl("\t\t     script by \x1b[36mahatay\x1b\t\n");
        ft_putendl("\t\t\x1b[31mthis project made with love.\x1b\t");
        ft_putendl("\t\t\x1b[32m=========================\t\t\x1b[0m");
        ft_putstr("\t    \x1b[34mnumber for connect to Client: \x1b[0m");
        ft_putnbr(pid);
        ft_putchar('\n');
        ft_putendl("\t\t\x1b[32m=========================\t\t\x1b[0m\n");
}
