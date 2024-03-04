/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodemetz <lodemetz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:50:05 by louis.demet       #+#    #+#             */
/*   Updated: 2024/01/28 19:01:45 by lodemetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_pad(uintptr_t pad, int fd, char *hex, int *count)
{
	if (pad >= 16)
		put_pad(pad / 16, fd, hex, count);
	put_c(hex[pad % 16], count);
}

void	put_p(void *ptr, int *count)
{
	uintptr_t	pad;

	pad = (uintptr_t)ptr;
	if (!pad)
	{
		put_s("(nil)", count);
		return ;
	}
	put_s("0x", count);
	put_pad(pad, 1, "0123456789abcdef", count);
}
