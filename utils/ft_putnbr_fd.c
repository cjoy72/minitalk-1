/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:07:14 by egualand          #+#    #+#             */
/*   Updated: 2023/12/27 13:46:00 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	array[12];
	int		i;

	num = (long)n;
	i = 0;
	if (num == 0)
		write(fd, "0", 1);
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	while (num > 0)
	{
		array[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (--i >= 0)
		write(fd, array + i, 1);
}
