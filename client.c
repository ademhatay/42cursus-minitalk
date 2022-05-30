#include "minitalk.h"

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

int    main(int argc, char **argv)
{
    int        pid;
    char    *bits;

    if (argc != 3)
    {
        ft_putendl("wrong number of arguments");
        return (0);
    }
    pid = ft_atoi(argv[1]);
    bits = ft_to_bit(argv[2], 0, 0);
    if (bits == NULL)
    {
        ft_putendl("allocation went wrong");
        return (0);
    }
    ft_send_msg(pid, bits);
    free(bits);
}
