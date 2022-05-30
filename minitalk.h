#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void    ft_putchar(const char c);
void    ft_putstr(const char *str);
void    ft_putnbr(int nb);
void    ft_putendl(const char *str);
size_t    ft_strlen(const char *str);
size_t    ft_strlcpy(char *dst, const char *src, size_t dstsize);
char    *ft_strdup(const char *s1);
void    ft_count(int *i, int *neg, const char *str);
int    ft_atoi(const char *str);
void    ft_control_av(char*str);
void    *ft_calloc(size_t count, size_t size);
void    ft_print_server_menu(int pid);

#endif

