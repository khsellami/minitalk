/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksellami <ksellami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:26:40 by ksellami          #+#    #+#             */
/*   Updated: 2024/05/17 15:59:38 by ksellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	ft_send_char(char c, int pid);
void	ft_handler(int sig, siginfo_t *info, void *unused);
int		ft_atoi(char *str);
void	ft_putnbr(int nb);
int		valid_arg(char *str);
int		ft_isdigit(char c);

#endif
