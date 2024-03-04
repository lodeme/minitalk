/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis.demetz <louis.demetz@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:30:23 by louis.demet       #+#    #+#             */
/*   Updated: 2023/11/15 11:40:03 by louis.demet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_lstmap

// Prototype 
// t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// Turn in files -

// Parameters 
// lst: The address of a pointer to a node.
// f: The address of the function used to iterate on
// the list.
// del: The address of the function used to delete
// the content of a node if needed.

// Return value 
// The new list.
// NULL if the allocation fails.

// External functs. malloc, free

// Description 
// Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node. Creates a new
// list resulting of the successive applications of
// the function ’f’. The ’del’ function is used to
// delete the content of a node if needed.

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (0);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, new_node);
	}
	return (new_lst);
}
