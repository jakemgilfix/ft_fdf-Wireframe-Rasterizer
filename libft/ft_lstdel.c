/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 22:24:31 by jgilfix           #+#    #+#             */
/*   Updated: 2019/07/22 22:27:39 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	takes as a parameter the address of a pointer to a link and
**					frees the memory of this link and all its successors, using
**					the functions `del` and `free`. The pointer to the link is
**					then set to NULL.
**
**	PARAMS:			1.	`alst` : pointer to pointer to beginning of list
**					2.	`del`  : delete function
**
**	RETURN VALUE:	N/A
**
**	LIBC FUNCTIONS:	N/A
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (!alst || !*alst || !del)
		return (ft_error(ERROR_NULL_PTR));
	while (*alst)
	{
		temp = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = temp;
	}
}
