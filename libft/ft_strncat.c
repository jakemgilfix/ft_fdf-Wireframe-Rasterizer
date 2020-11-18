/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 00:12:46 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 09:39:27 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	appends not more than `n` characters of the null-terminated
**					string `src` to the end of the null-terminated string
**					`dest`, then adding a terminating '\0' character.
**					The source and destination strings should not overlap; if
**					they do, the resulting behavior is undefined.
**
**	PARAMS:			1.	`dest` : destination string
**					2.	`src`  : string to append to `dest`
**					3.	`n`    : number of characters of `src` to append to
**								 `dest`
**
**	RETURN VALUE:	returns `dest`
**
**	LIBC FUNCTIONS:	N/A
*/

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	len_d;
	size_t	len_s;

	len_d = ft_strlen(dest);
	len_s = ft_sizet_min(n, ft_strlen(src));
	dest = ft_strncpy(dest + len_d, src, len_s) - len_d;
	dest[len_d + len_s] = '\0';
	return (dest);
}
