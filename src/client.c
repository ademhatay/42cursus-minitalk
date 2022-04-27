#include "minitalk.h"

static void	ft_send_msg(int pid, char*str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(80);
	}
}

static char	*ft_to_bit(char *str, size_t i, size_t j)
{
	char	*ret;
	int		c;
	int		bytes;

	i = strlen(str);
	ret = calloc(i * 8 + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (i + 1 != 0)
	{
		c = str[i - 1];
		bytes = 8;
		while (bytes > 0)
		{
			if (c % 2 == 1)
				ret[strlen(str) * 8 - j - 1] = '1';
			else
				ret[strlen(str) * 8 - j - 1] = '0';
			c = c / 2;
			j++;
			bytes--;
		}
		i--;
	}
	return (ret);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*bits;

	if (ac < 3)
	{
		ft_printf("Eksik Arguman Girdiniz...");
		return (0);
	}
	else if (ac > 3)
	{
		ft_printf("Fazla Arguman Girdiniz...");
		return (0);
	}
	pid = atoi(av[1]);
	bits = ft_to_bit(av[2], 0, 0);
	if (bits == NULL)
	{
		ft_printf("Gerekli alan hafizadan tahsis edilemedi...");
		return (0);
	}
	ft_send_msg(pid, bits);
	free(bits);
}
