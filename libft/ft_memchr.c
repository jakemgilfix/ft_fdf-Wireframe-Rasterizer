/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 23:36:55 by jgilfix           #+#    #+#             */
/*   Updated: 2019/06/21 21:33:25 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	locates the first occurence of `c` (converted to an
**					unsigned char) in string `s`, searching up to `n` bytes.
**
**	PARAMS:			1.	`s` : string to search
**					2.	`c` : character to search for
**					3.	`n` : how many bytes to search in `s`
**
**	RETURN VALUE:	returns pointer to the byte located, or NULL if no such byte
**					exists within `n` bytes.
**
**	LIBC FUNCTIONS:	N/A
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		if (((unsigned char *)s)[i++] == (unsigned char)c)
			return ((void *)s + --i);
	return (NULL);
}
