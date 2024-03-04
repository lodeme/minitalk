/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodemetz <lodemetz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:50:05 by louis.demet       #+#    #+#             */
/*   Updated: 2024/01/28 19:01:30 by lodemetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned int u, char *hex, int *count)
{
	if (u >= 16)
		ft_puthex(u / 16, hex, count);
	put_c(hex[u % 16], count);
}

void	put_x(unsigned int u, int *count)
{
	ft_puthex(u, "0123456789abcdef", count);
}

void	put_cap_x(unsigned int u, int *count)
{
	ft_puthex(u, "0123456789ABCDEF", count);
}
