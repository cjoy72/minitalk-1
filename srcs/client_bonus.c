/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaroi <cbaroi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:30:21 by egualand          #+#    #+#             */
/*   Updated: 2024/05/19 23:46:08 by cbaroi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	ft_check_args(int argc, char *argv[]);
static void	ft_atob(int pid, int c);
static void	ft_receive_confirmation(int signal);

int			g_confirmation_received = 0;

int	main(int argc, char *argv[])
{
	int	i;
	int	pid;

	ft_check_args(argc, argv);
	i = 0;
	pid = ft_atoi(argv[1]);
	if (signal(SIGUSR1, &ft_receive_confirmation) == SIG_ERR)
		ft_error(ERROR_SIGNAL);
	while (argv[2][i])
	{
		if (!((argv[2][i] > 0 && argv[2][i] < 8)
			|| argv[2][i] == 127
			|| (argv[2][i] > 13 && argv[2][i] < 32)))
			ft_atob(pid, argv[2][i]);
		i++;
	}
	if (argv[2][i - 1] != '\n')
		ft_atob(pid, '\n');
	ft_atob(pid, '\0');
	while (!g_confirmation_received)
		pause();
	return (0);
}

static void	ft_check_args(int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc != 3)
		ft_error(ERROR_ARGS);
	i = 0;
	while (argv[1][i])
	{
		j = 0;
		while (argv[1][j])
		{
			if (!ft_isdigit(argv[1][j]))
				ft_error(ERROR_PID);
			j++;
		}
		i++;
	}
}

static void	ft_atob(int pid, int c)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if (c & (1 << bits))
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error(ERROR_KILL);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error(ERROR_KILL);
		}
		usleep(100);
		bits++;
	}
}

static void	ft_receive_confirmation(int signal)
{
	if (signal == SIGUSR1)
	{
		g_confirmation_received = 1;
		ft_putstr_fd("Message of confirmation received by the server.\n", 1);
	}
}
