/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:30:37 by egualand          #+#    #+#             */
/*   Updated: 2023/12/27 13:46:14 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	ft_check_args(int argc, char *argv[]);
static void	ft_btoa(int c);

int	main(int argc, char *argv[])
{
	(void)argv;
	ft_check_args(argc, argv);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		if (signal(SIGUSR1, &ft_btoa) == SIG_ERR)
			ft_error(ERROR_SIGNAL);
		if (signal(SIGUSR2, &ft_btoa) == SIG_ERR)
			ft_error(ERROR_SIGNAL);
		pause();
	}
}

static void	ft_check_args(int argc, char *argv[])
{
	(void)argv;
	if (argc != 1)
		ft_error(ERROR_ARGS);
}

static void	ft_btoa(int signal)
{
	static int	c;
	static int	bits;

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
