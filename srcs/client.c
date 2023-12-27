/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:30:27 by egualand          #+#    #+#             */
/*   Updated: 2023/12/27 13:46:23 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	ft_check_args(int argc, char *argv[]);
static void	ft_atob(int pid, char c);

int	main(int argc, char *argv[])
{
	int	i;
	int	pid;

	ft_check_args(argc, argv);
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		ft_atob(pid, argv[2][i]);
		i++;
	}
	if (argv[2][i - 1] != '\n')
		ft_atob(pid, '\n');
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

static void	ft_atob(int pid, char c)
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
