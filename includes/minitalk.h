/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egualand <egualand@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:29:57 by egualand          #+#    #+#             */
/*   Updated: 2023/12/27 13:46:34 by egualand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_ARGS 1
# define ERROR_PID 2
# define ERROR_CHAR 3
# define ERROR_SIGNAL 4
# define ERROR_KILL 5

void	ft_error(int error_code);
int		ft_isdigit(char c);
int		ft_atoi(const char *nptr);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
