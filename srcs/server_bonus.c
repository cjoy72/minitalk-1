#include "../includes/minitalk.h"

static void ft_check_args(int argc, char *argv[]);
static void ft_btoa(int signal, siginfo_t *info, void *context);

int main(int argc, char *argv[])
{
    struct sigaction    action;

    (void)argv;
    ft_check_args(argc, argv);
    ft_putnbr_fd(getpid(), 1);
    ft_putchar_fd('\n', 1);
    action.sa_sigaction = ft_btoa;
    action.sa_flags = SA_SIGINFO | SA_RESTART;
    sigemptyset(&action.sa_mask);
    while (1)
    {
        if (sigaction(SIGUSR1, &action, NULL) == -1)
            ft_error(ERROR_SIGNAL);
        if (sigaction(SIGUSR2, &action, NULL) == -1)
            ft_error(ERROR_SIGNAL);
        pause();
    }
}

static void ft_check_args(int argc, char *argv[])
{
    (void)argv;
    if (argc != 1)
        ft_error(ERROR_ARGS);
}

static void ft_btoa(int signal, siginfo_t *info, void *context)
{
    static int  c;
    static int  bits;

    (void)context;
    if (signal == SIGUSR1)
        c |= (1 << bits);
    bits++;
    if (bits == 8)
    {
        if (c == 0)
            kill(info->si_pid, SIGUSR1);
        ft_putchar_fd(c, 1);
        c = 0;
        bits = 0;
    }
}
