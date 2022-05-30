#include "minitalk.h"


static void	ft_convert(char *s)
{
	int				pow;
	unsigned char	c;
	size_t			i;

	pow = 1;
	c = 0;
	i = ft_strlen(s) - 1;
	while (i + 1 != 0)
	{
		c += pow * (s[i] - '0');
		pow = pow * 2;
		i--;
	}
	write(1, &c, 1);
}

static void	ft_confirm(int sig)
{
	static char	*bits;
	static int	bitcount;
    
    
	bitcount++;
	if (bits == NULL)
	{
		bits = ft_strdup("");
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
