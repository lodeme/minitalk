/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis.demetz <louis.demetz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:41:10 by louis.demet       #+#    #+#             */
/*   Updated: 2023/11/15 11:39:59 by louis.demet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name
// ft_lstiter

// Prototype 
// void ft_lstiter(t_list *lst, void (*f)(void *));

// Turn in files 
// -

// Parameters 
// lst: The address of a pointer to a node.
// f: The address of the function used to iterate on
// the list.

// Return value 
// None

// External functs. 
// None

// Description 
// Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node.

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst-> next;
	}
}
