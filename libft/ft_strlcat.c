/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 00:15:02 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 09:39:10 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	appends string `src` to the end of string `dest`. It will
**					append at most `size` - ft_strlen(`dest`) characters. It
**					will then null-terminate, unless `size` is 0 or the original
**					`dest` string was longer than `size`.
**					Consider this a safer, less error-prone version of
**					ft_strncat().
**
**	PARAMS:			1.	`dest` : destination string
**					2.	`src`  : string to append to `dest`
**					3.	`size` : the full size of the destination buffer
**
**	RETURN VALUE:	returns `dest`
**
**	LIBC FUNCTIONS:	N/A
*/

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	j = 0;
	while (((i + 1) < size) && src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (ft_strlen(src) + ft_sizet_min(size, (i - j)));
}
