#include "../includes/minitalk.h"

void    ft_error(int error_code)
{
    if (error_code == ERROR_ARGS)
        ft_putendl_fd("Error: wrong number of arguments", 2);
    else if (error_code == ERROR_PID)
        ft_putendl_fd("Error: invalid PID", 2);
    else if (error_code == ERROR_CHAR)
        ft_putendl_fd("Error: invalid character", 2);
    else if (error_code == ERROR_SIGNAL)
        ft_putendl_fd("Error: signal failed", 2);
    else if (error_code == ERROR_KILL)
        ft_putendl_fd("Error: kill failed", 2);
    exit(error_code);
}