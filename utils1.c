#include "minitalk.h"

void    ft_putchar(const char c)
{
        write(1, &c, 1);
}

void    ft_putstr(const char *str)
{
        while (*str)
        {
                ft_putchar(*str);
                str++;
        }
}

void    ft_putnbr(int nb)
{
        if (nb == -2147483648)
        {
                ft_putchar('-');
                ft_putchar('2');
                ft_putnbr(147483648);
                return ;
        }
        else if (nb >= 10)
        {
                ft_putnbr(nb / 10);
                ft_putnbr(nb % 10);
        }
        else if (nb < 0)
        {
                nb = -nb;
                ft_putchar('-');
                ft_putnbr(nb);
        }
        else
                ft_putchar(nb + '0');
}

void    ft_putendl(const char *str)
{
        if(str)
        {
                ft_putstr(str);
                ft_putchar('\n');
        }
}

size_t    ft_strlen(const char *str)
{
    size_t    i;

    i = 0;
    while (str[i] != '\0' )
        i++;
    return (i);
}

size_t    ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t    i;

    if (src == NULL)
        return ((size_t) NULL);
    if (dstsize == 0)
        return (ft_strlen(src));
    i = 0;
    while (i < dstsize - 1 && src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (ft_strlen(src));
}

char    *ft_strdup(const char *s1)
{
    char    *s2;

    s2 = malloc(ft_strlen(s1) + 1);
    if (s2 == NULL)
        return (NULL);
    ft_strlcpy(s2, s1, ft_strlen(s1) + 1);
    return (s2);
}
