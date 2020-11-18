/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:37:14 by jgilfix           #+#    #+#             */
/*   Updated: 2019/08/22 10:52:22 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	writes `len` bytes of value `val` (converted to an unsigned
**					char) to the string `dest`.
**
**	PARAMS:			1.	`dest` : destination string
**					2.	`val`  : value to write to the string `dest`
**					3.	`len`  : how many bytes to write
**
**	RETURN VALUE:	N/A
**
**	LIBC FUNCTIONS:	N/A
*/

void	*ft_memset(void *dest, int val, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)dest;
	while (len--)
		*ptr++ = (unsigned char)val;
	return (dest);
}
