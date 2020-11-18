/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 00:01:34 by jgilfix           #+#    #+#             */
/*   Updated: 2019/08/13 14:23:20 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	appends a copy of the null-terminated string `src` to the
**					end of the null-terminated string `dest`, then adding a
**					terminating '\0' character. The string `dest` must have
**					sufficient space to hold the result.
**					The source and destination strings should not overlap; if
**					they do, the resulting behavior is undefined.
**
**	PARAMS:			1.	`dest` : destination string
**					2.	`src`  : string to append to `dest`
**
**	RETURN VALUE:	returns `dest`
**
**	LIBC FUNCTIONS:	N/A
*/

char	*ft_strcat(char *dest, const char *src)
{
	size_t	len;

	len = ft_strlen(dest);
	return (ft_strcpy(dest + len, src) - len);
}
