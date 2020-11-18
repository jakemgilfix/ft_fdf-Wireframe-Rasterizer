/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 22:20:42 by jgilfix           #+#    #+#             */
/*   Updated: 2019/07/22 22:24:17 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	takes as a parameter the address of a pointer to a link and
**					frees the memory of the link's content using the function
**					`del` given as a parameter, then frees the link's memory.
**					The memory of `next` is NOT freed under any circumstance.
**					Finally, the pointer to the link that was just freed is set
**					to NULL.
**
**	PARAMS:			1.	`alst` : pointer to pointer to beginning of list
**					2.	`del`  : delete function
**
**	RETURN VALUE:	N/A
**
**	LIBC FUNCTIONS:	N/A
*/

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !*alst || !del)
		return (ft_error(ERROR_NULL_PTR));
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
