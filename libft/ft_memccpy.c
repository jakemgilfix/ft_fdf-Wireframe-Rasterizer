/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 23:25:40 by jgilfix           #+#    #+#             */
/*   Updated: 2019/07/22 21:23:47 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	copies bytes from string `src` to string `dest`. If the
**					character `c` occurs in the string `src`, the copy stops and
**					a pointer to the byte after the copy of `c` in the string
**					`dest` is returned. Otherwise, `n` bytes are copied, and a
**					NULL pointer is returned.
**
**	PARAMS:			1.	`dest` : destination memory area
**					2.	`src`  : source memory area
**					3.	`c`    : character that stops the copying process
**					4.	`n`    : how many bytes to copy from `src` to `dest`
**
**	RETURN VALUE:	returns (if found) a pointer to the byte after the copy of
**					`c` in the string `dest`; otherwise returns NULL pointer
**
**	LIBC FUNCTIONS:	N/A
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;
	size_t			i;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_ptr[i] = (unsigned char)src_ptr[i];
		if (dest_ptr[i++] == (unsigned char)c)
			return ((void *)(dest + i));
	}
	return (NULL);
}
