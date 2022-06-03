#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * sign);
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
