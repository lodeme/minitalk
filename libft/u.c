/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodemetz <lodemetz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:50:05 by louis.demet       #+#    #+#             */
/*   Updated: 2024/01/28 19:01:39 by lodemetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_u_putnbr(unsigned int u, int *count)
{
	if (u >= 10)
		ft_u_putnbr(u / 10, count);
	put_c(u % 10 + '0', count);
}

void	put_u(unsigned int u, int *count)
{
	ft_u_putnbr(u, count);
}
