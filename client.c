/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahatay <ahatay@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:20:18 by ahatay            #+#    #+#             */
/*   Updated: 2022/06/03 10:20:19 by ahatay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_message(int pid, char *bits)
{
	size_t	i;

	i = 0;
	while (bits[i] != '\0')
	{
		if (bits[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(80);
	}
}

static char	*ft_convert_bit(char *str, size_t i, size_t j)
{
	char	*ret;
	int		c;
	int		bytes;

	i = ft_strlen(str);
	ret = ft_calloc(i * 8, sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (i != 0)
	{
		c = str[i - 1];
		bytes = 8;
		while (bytes > 0)
		{
			if (c % 2 == 1)
				ret[ft_strlen(str) * 8 - j - 1] = '1';
			else
				ret[ft_strlen(str) * 8 - j - 1] = '0';
			c = c / 2;
			j++;
			bytes--;
		}
		i--;
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*bits;

	if (argc != 3)
	{
		ft_putendl("wrong number of arguments");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	bits = ft_convert_bit(argv[2], 0, 0);
	if (bits == NULL)
	{
		ft_putendl("allocation went wrong");
		return (0);
	}
	ft_send_message(pid, bits);
	free(bits);
}
