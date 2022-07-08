/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahatay <ahatay@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:15:40 by ahatay            #+#    #+#             */
/*   Updated: 2022/06/03 10:18:18 by ahatay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (src == NULL)
		return ((size_t) NULL);
	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = malloc(ft_strlen(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}

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

void	ft_print_server_menu(int pid)
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
