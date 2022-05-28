# include <unistd.h>
# include <signal.h>
#include <stdlib.h>
#include <string.h>

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

// converts binary to ascii and prints it

static void	ft_convert(char *s)
{
	int				pow;
	unsigned char	c;
	size_t			i;

	pow = 1;
	c = 0;
	i = strlen(s) - 1;
	while (i + 1 != 0)
	{
		c += pow * (s[i] - '0');
		pow = pow * 2;
		i--;
	}
	write(1, &c, 1);
}

// reads every bit and appends it to bits
// if its a 8 bit it prints the char to the console

static void	ft_confirm(int sig)
{
	static char	*bits;
	static int	bitcount;
    
    
	bitcount++;
	if (bits == NULL)
	{
		bits = strdup("");
		bitcount = 1;
	}
	if (sig == SIGUSR2)
		bits[bitcount - 1] = '0';
	else
		bits[bitcount - 1] = '1';
	if (bitcount == 8)
	{
		ft_convert(bits);
		free(bits);
		bits = NULL;
	}
}



int	main(void)
{
	int	pid;

	pid = getpid();
	ft_print_server_menu(pid);
	while (42)
	{
		signal(SIGUSR1, ft_confirm);
		signal(SIGUSR2, ft_confirm);
		pause();
	}
	return (1);
}
