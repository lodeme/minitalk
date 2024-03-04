/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodemetz <lodemetz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:56:45 by lodemetz          #+#    #+#             */
/*   Updated: 2024/01/30 13:29:27 by lodemetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	decode(int sig)
{
	static unsigned char	c;
	static int				i;

	if (sig == SIGUSR1)
		c |= 1 << i;
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
	sig.sa_handler = decode;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	while (1)
		pause();
	return (0);
}
