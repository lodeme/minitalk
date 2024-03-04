/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodemetz <lodemetz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:50:05 by louis.demet       #+#    #+#             */
/*   Updated: 2024/01/28 19:01:50 by lodemetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_i(int i, int *count)
{
	if (i == INT_MIN)
	{
		put_s("-2147483648", count);
		return ;
	}
	if (i < 0)
	{
		i = -i;
		put_c('-', count);
	}
	if (i >= 10)
		put_i(i / 10, count);
	put_c(i % 10 + '0', count);
}