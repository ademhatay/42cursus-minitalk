# include <unistd.h>
# include <signal.h>

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

int     main(int ac, char **av)
{
	int
        return (1);
}
