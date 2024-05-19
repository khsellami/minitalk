/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksellami <ksellami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:25:40 by ksellami          #+#    #+#             */
/*   Updated: 2024/05/17 14:38:01 by ksellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_char(char c, int pid)
{
	int	i;
	int	bit;
	int	v;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
			v = kill(pid, SIGUSR1);
		else
			v = kill(pid, SIGUSR2);
		if (v == -1)
			(write(2, "Error\n", 6), exit(1));
		usleep (800);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac == 3)
	{
		if (!valid_arg(av[1]))
			(write(2, "Error\n", 6), exit(1));
		pid = ft_atoi(av[1]);
		if (pid < 1)
			(write(2, "Error\n", 6), exit(1));
		while (av[2][i])
			ft_send_char(av[2][i++], pid);
		ft_send_char('\n', pid);
	}
	else
		write(1, "Invalid arguments\n", 19);
	return (0);
}
//00011010
//
