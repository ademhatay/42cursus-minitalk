# include <unistd.h>
# include <signal.h>
#include <stdlib.h>

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

void	ft_count(int *i, int *neg, const char *str)
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

int	ft_atoi(const char *str)
{
	int	i;
	int	multiplicator;
	int	num;
	int	neg;

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


void	ft_control_av(char*str)
{
	ft_putstr("\x1b[31mERROR\x1b[0m: You Have Entered ");
	ft_putstr(str);
	ft_putendl("Argument...");
	ft_putendl("\x1b[32mCorrect\x1b[0m Usage should be...");
	ft_putendl("\t\t\x1b[36m./client <PID> `message`\t\t\x1b[0m");
}


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' )
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*c;
	int		len;

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

static void	ft_send_msg(int pid, char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(80);
	}
}

static char	*ft_to_bit(char *s, size_t i, size_t j)
{
	char	*ret;
	int		c;
	int		bytes;

	i = ft_strlen(s);
	ret = ft_calloc(i * 8 + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (i + 1 != 0)
	{
		c = s[i - 1];
		bytes = 8;
		while (bytes > 0)
		{
			if (c % 2 == 1)
				ret[ft_strlen(s) * 8 - j - 1] = '1';
			else
				ret[ft_strlen(s) * 8 - j - 1] = '0';
			c = c / 2;
			j++;
			bytes--;
		}
		i--;
	}
	return (ret);
}


int     main(int ac, char **av)
{
	int	pid;
	char	*bits;

	if (ac < 3)
		ft_control_av("Missing ");
	else if (ac > 3)
		ft_control_av("Too Many ");
	pid = ft_atoi(av[1]);
	bits = ft_to_bit(av[2], 0, 0);
	if (bits == NULL)
	{
		ft_putendl("Required space could not be allocated from memory");
		return (0);
	}
	ft_send_msg(pid, bits);
	free(bits);	
}
