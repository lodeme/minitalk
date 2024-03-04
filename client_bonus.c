/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodemetz <lodemetz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:08:00 by lodemetz          #+#    #+#             */
/*   Updated: 2024/01/30 16:03:11 by lodemetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	acknowledge_signal(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("1", 1);
	else
		ft_printf("0", 1);
}

void	send_string(int server_pid, char *str)
{
	int	i;

	while (*str)
	{
		i = 0;
		while (i < 8)
		{
			if ((*str & (1 << i)) != 0)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			i++;
			usleep(400);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (!(argc == 3))
		exit(1);
	signal(SIGUSR1, acknowledge_signal);
	signal(SIGUSR2, acknowledge_signal);
	send_string(ft_atoi(argv[1]), argv[2]);
	return (0);
}
