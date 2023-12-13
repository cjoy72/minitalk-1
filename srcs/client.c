#include "../includes/minitalk.h"

static void ft_atob(int pid, char c);

int main(int argc, char *argv[])
{
    int i;
    int pid;

    if (argc != 3)
        ft_error(ERROR_ARGS);
    i = 0;
    pid = ft_atoi(argv[1]);
    while (argv[2][i])
    {
        ft_atob(pid, argv[2][i]);
        i++;
    }
}

static void ft_atob(int pid, char c)
{
    int bits;

    bits = 0;
    while (bits < 8)
    {
        if (c & (1 << bits))
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(500);
        bits++;
    }
}