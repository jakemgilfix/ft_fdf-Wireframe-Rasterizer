/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 22:10:56 by jgilfix           #+#    #+#             */
/*   Updated: 2019/07/22 23:07:26 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	Allocates and returns a "fresh" link. The variables
**					`content` and `content_size` of the new link are initialized
**					by COPYING the parameters of the function. If the parameter
**					`content` is NULL, the variable `content` is initialized to
**					NULL and the variable `content_size` is intialized to 0 even
**					if the parameter `content_size` isn't. The variable `next`
**					is initialized to NULL. If the allocation fails, the
**					function returns NULL.
**
**	PARAMS:			1.	`content`        : content for "fresh" link
**					2.	`content_size`   : size of `content`
**
**	RETURN VALUE:	Returns the new list
**
**	LIBC FUNCTIONS:	malloc()
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->next = NULL;
	new->content_size = content ? content_size : 0;
	new->content = content ? ft_strnew(content_size - 1) : NULL;
	if (content)
		(void)ft_memcpy(new->content, content, new->content_size);
	return (new);
}
