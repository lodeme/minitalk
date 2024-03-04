/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodemetz <lodemetz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:56:45 by lodemetz          #+#    #+#             */
/*   Updated: 2024/01/30 15:49:34 by lodemetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	decode(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				i;

	(void)context;
	if (sig == SIGUSR1)
	{
		c |= 1 << i;
		kill(info->si_pid, SIGUSR1);
	}
	else
		kill(info->si_pid, SIGUSR2);
	if (i++ == 7)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("Server process ID: %d\n", getpid());
	sig.sa_sigaction = &decode;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	while (1)
		pause();
	return (0);
}
