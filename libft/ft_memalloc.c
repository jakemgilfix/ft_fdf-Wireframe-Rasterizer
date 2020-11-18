/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 20:06:21 by jgilfix           #+#    #+#             */
/*   Updated: 2019/06/14 20:08:45 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	allocates and returns a "fresh" memory area. The allocated
**					memory is initialized to 0. If the allocation fails, the
**					function returns NULL.
**
**	PARAMS:			1.	`size` : size (in bytes) of the memory area to be
**						allocated.
**
**	RETURN VALUE:	Returns a pointer to the allocated memory area
**
**	LIBC FUNCTIONS:	malloc()
*/

void	*ft_memalloc(size_t size)
{
	void	*new;

	if (!(new = malloc(size)))
		return (NULL);
	ft_bzero(new, size);
	return (new);
}
