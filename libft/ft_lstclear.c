/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis.demetz <louis.demetz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:03:55 by lodemetz          #+#    #+#             */
/*   Updated: 2023/11/15 11:39:52 by louis.demet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name 
// ft_lstclear

// Prototype 
// void ft_lstclear(t_list **lst, void (*del)(void*));

// Turn in files 
// -

// Parameters 
// lst: The address of a pointer to a node.
// del: The address of the function used to delete
// the content of the node.

// Return value 
// None

// External functs. 
// free

// Description 
// Deletes and frees the given node and every
// successor of that node, using the function ’del’
// and free(3).
// Finally, the pointer to the list must be set to
// NULL.

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
