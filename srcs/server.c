#include "../includes/minitalk.h"

void ft_btoa(int c);

int main(int argc, char *argv[])
{
    if (argc != 1)
        ft_error(ERROR_ARGS);
    ft_putnbr_fd(getpid(), 1);
    ft_putchar_fd('\n', 1);
    while (1)
    {
        signal(SIGUSR1, &ft_btoa);
        signal(SIGUSR2, &ft_btoa);
        pause();
    }
}

void ft_btoa(int signal)
{
    static int c;
    static int bits;

    if (signal == SIGUSR1)
        c |= (1 << bits);
    bits++;
    if (bits == 8)
    {
        ft_putchar_fd(c, 1);
        c = 0;
        bits = 0;
    }
}