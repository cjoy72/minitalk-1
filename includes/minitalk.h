#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <signal.h>

# define ERROR_ARGS 1
# define ERROR_PID 2
# define ERROR_CHAR 3
# define ERROR_MALLOC 4
# define ERROR_SIGNAL 5
# define ERROR_KILL 6

int ft_atoi(const char *nptr);
void ft_putchar_fd(char c, int fd);
void ft_putendl_fd(char *s, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);

#endif
