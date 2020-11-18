/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 23:31:03 by jgilfix           #+#    #+#             */
/*   Updated: 2019/08/13 14:45:12 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	copies `len` bytes from string `src` to string `dest`. The
**					two strings may overlap; the copy is always done in a non-
**					destructive manner.
**
**	PARAMS:			1.	`dest` : destination string
**					2.	`src` : source string
**					3.	`len` : how many bytes to copy from `src` to `dest`
**
**	RETURN VALUE:	returns original value of `dest`
**
**	LIBC FUNCTIONS:	N/A
*/

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*buffer;

	buffer = (char *)malloc(len);
	return (ft_memcpy(dest, ft_memcpy(buffer, src, len), len));
}
