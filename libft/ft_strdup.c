/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagilfix <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:32:06 by jagilfix          #+#    #+#             */
/*   Updated: 2019/06/21 21:38:11 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	allocates sufficient memory for a copy of the string `src`,
**					does the copy, and returns a pointer to it. The pointer may
**					subsequently be used as an argument to the function free().
**
**	PARAMS:			1.	`src` : string to duplicate
**
**	RETURN VALUE:	returns a pointer to a duplicate of `str`
**
**	LIBC FUNCTIONS:	malloc()
*/

char	*ft_strdup(const char *src)
{
	char	*dest;

	if (!src || !(dest = (char *)malloc((ft_strlen(src) + 1) * sizeof(char))))
		return (NULL);
	dest = ft_strcpy(dest, src);
	return (dest);
}
