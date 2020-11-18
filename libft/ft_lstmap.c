/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 22:32:47 by jgilfix           #+#    #+#             */
/*   Updated: 2019/07/22 22:55:43 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	iterates the list pointed to by `lst` and applies the
**					function `f` to each link to create a "fresh" list resulting
**					from the successive applications of `f`. If the allocation
**					fails, the function returns NULL.
**
**	PARAMS:			1.	`lst` : pointer to beginning of list
**					2.	`f`   : function to apply to each of the list's nodes
**
**	RETURN VALUE:	Returns the new list
**
**	LIBC FUNCTIONS:	N/A
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *link))
{
	t_list	*new;

	if (lst)
	{
		new = f(lst);
		new->next = ft_lstmap(lst->next, f);
		return (new);
	}
	return (NULL);
}
