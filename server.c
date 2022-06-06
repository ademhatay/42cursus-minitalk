/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahatay <ahatay@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:20:07 by ahatay            #+#    #+#             */
/*   Updated: 2022/06/03 10:20:10 by ahatay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_convert_char(char *str)
{
	int				pow;
	unsigned char	c;
	size_t			i;

	pow = 1;
	c = 0;
	i = ft_strlen(str) - 1;
	while (i + 1 != 0)
	{
		c += pow * (str[i] - '0');
		pow = pow * 2;
		i--;
	}
	write(1, &c, 1);
}

static void	ft_confirm(int signal)
{
	static char	*bits;
	static int	bitcount;

	bitcount++;
	if (bits == NULL)
	{
		bits = ft_strdup("");
		bitcount = 1;
	}
	if (signal == SIGUSR2)
		bits[bitcount - 1] = '0';
	else
		bits[bitcount - 1] = '1';
	if (bitcount == 8)
	{
		ft_convert_char(bits);
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
