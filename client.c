/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodemetz <lodemetz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:08:00 by lodemetz          #+#    #+#             */
/*   Updated: 2024/01/30 12:43:30 by lodemetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	send_string(ft_atoi(argv[1]), argv[2]);
	return (0);
}
