/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodemetz <lodemetz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:47:51 by louis.demet       #+#    #+#             */
/*   Updated: 2024/01/28 19:12:21 by lodemetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Remove stdio from h file
// TODO: Test all functions against francinette
// TODO: Test case where letter after % is not format specifier

#include "libft.h"

void	select_specifier(char *str, va_list args, int *count)
{
	if (*str == 'c')
		put_c(va_arg(args, int), count);
	else if (*str == 's')
		put_s(va_arg(args, char *), count);
	else if (*str == 'p')
		put_p(va_arg(args, void *), count);
	else if (*str == 'i' || *str == 'd')
		put_i(va_arg(args, int), count);
	else if (*str == 'u')
		put_u(va_arg(args, unsigned int), count);
	else if (*str == 'x')
		put_x(va_arg(args, unsigned int), count);
	else if (*str == 'X')
		put_cap_x(va_arg(args, unsigned int), count);
	else
		put_c(*str, count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			select_specifier((char *)++str, args, &count);
		else
			put_c(*str, &count);
		str++;
	}
	va_end(args);
	return (count);
}
