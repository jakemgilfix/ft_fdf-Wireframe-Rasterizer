/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 22:29:49 by jgilfix           #+#    #+#             */
/*   Updated: 2019/07/22 22:32:41 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	iterates the list pointed to by `lst` and applies the
**					function `f` to each link.
**
**	PARAMS:			1.	`lst` : pointer to beginning of list
**					2.	`f`   : function to apply to each of the list's nodes
**
**	RETURN VALUE:	N/A
**
**	LIBC FUNCTIONS:	N/A
*/

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*temp;

	if (!lst || !f)
		return (ft_error(ERROR_NULL_PTR));
	while (lst)
	{
		temp = lst->next;
		f(lst);
		lst = temp;
	}
}
