/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:01:41 by jgilfix           #+#    #+#             */
/*   Updated: 2019/06/21 21:44:16 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	copies at most `n` bytes of the string `src` to `dest`
**					If `src` is less than `n` characters long, the remainder of
**					`dest` is filled with '\0' characters. Otherwise, `dest` is
**					NOT terminated.
**					The source and destination strings should not overlap; if
**					they do, the behavior is undefined.
**
**	PARAMS:			1.	`dest` : destination string
**					2.	`src`  : source string
**					3.	`n`    : number of bytes of `src` to copy to `dest`
**
**	RETURN VALUE:	returns `dest`
**
**	LIBC FUNCTIONS:	N/A
*/

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int		i;
	size_t	src_len;

	i = -1;
	src_len = ft_strlen(src);
	while ((size_t)(++i) < n)
		dest[i] = ((size_t)i < src_len) ? src[i] : 0;
	return (dest);
}
