#include "minitalk.h"

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
	ft_printf("Senin PID'in: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, ft_confirm);
		signal(SIGUSR2, ft_confirm);
		pause();
	}
	return (0);
}
