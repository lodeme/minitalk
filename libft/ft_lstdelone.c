/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis.demetz <louis.demetz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:59:55 by lodemetz          #+#    #+#             */
/*   Updated: 2023/11/15 11:39:56 by louis.demet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name 
// ft_lstdelone

// Prototype 
// void ft_lstdelone(t_list *lst, void (*del)(void*));

// Turn in files
// -
// Parameters 
// lst: The node to free.
// del: The address of the function used to delete
// the content.

// Return value 
// None

// External functs. 
// free

// Description 
// Takes as a parameter a node and frees the memory of
// the node’s content using the function ’del’ given
// as a parameter and free the node. The memory of
// ’next’ must not be freed.

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
