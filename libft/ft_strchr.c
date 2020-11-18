/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 00:23:17 by jgilfix           #+#    #+#             */
/*   Updated: 2019/06/19 21:43:08 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	locates the first occurence of `c` (converted to a char) in
**					the string `s`. The terminating '\0' character is considered
**					part of the string; therefore, if `c` is '\0', this will
**					locate the terminating '\0'.
**
**	PARAMS:			1.	`s` : string to search
**					2.	`c` : character to search for in `s`
**
**	RETURN VALUE:	returns a pointer to the located character, or NULL if the
**					character does not appear in the string.
**
**	LIBC FUNCTIONS:	N/A
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == c)
			return ((char *)--s);
	return ((*s == (char)c) ? (char *)s : NULL);
}
