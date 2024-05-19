/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksellami <ksellami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:25:47 by ksellami          #+#    #+#             */
/*   Updated: 2024/05/17 14:39:10 by ksellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig, siginfo_t *info, void *unused)
{
	static char	c;
	static int	i;
	static int	pid;

	(void) unused;
	if (pid != 0 && pid != info->si_pid)
	{
		i = 0;
		c = 0;
	}
	c = (c << 1) | (sig == SIGUSR2);
	i++;
	if (i == 8)
	{
		write (1, &c, 1);
		i = 0;
		c = 0;
	}
	pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_sigaction = &ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write (1, "Pid is: ", 8);
	pid = getpid();
	ft_putnbr (pid);
	while (1)
		pause();
	return (0);
}
