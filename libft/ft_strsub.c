/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:34:20 by jgilfix           #+#    #+#             */
/*   Updated: 2019/06/21 22:20:08 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	allocates and returns a "fresh" substring from the string
**					given as argument. The substring begins at index `start` and
**					is of size `len`. If `start` and `len` don't refer to a
**					valid substring, the behavior is undefined. If the
**					allocation fails, the function returns NULL.
**
**	PARAMS:			1.	`s`     : original string
**					2.	`start` : starting index of substring
**					3.	`len`   : the length of the substring
**
**	RETURN VALUE:	returns a copy of the substring
**
**	LIBC FUNCTIONS:	malloc() [via ft_strnew()]
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (!s || !(result = ft_strnew(len)))
		return (NULL);
	return (result = ft_strncpy(result, (char *)s + start, len));
}
