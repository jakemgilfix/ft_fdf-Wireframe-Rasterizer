/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:02:11 by jgilfix           #+#    #+#             */
/*   Updated: 2019/08/21 07:51:54 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	locates the first occurence of the null-terminated string
**					`to_find` in the null-terminated string `str`.
**
**	PARAMS:			1.	`str`     : string to search
**					2.	`to_find` : substring to search for within `str`
**
**	RETURN VALUE:	if `to_find` is an empty string, `str` is returned; if
**					`to_find` occurs nowhere in `str`, NULL is returned; else
**					a pointer to the first character in the first occurence
**					of `to_find` is returned.
**
**	LIBC FUNCTIONS:	N/A
*/

char	*ft_strstr(const char *str, const char *to_find)
{
	int		size_haystack;
	int		size_needle;
	int		i;

	size_haystack = (int)ft_strlen(str);
	size_needle = (int)ft_strlen(to_find);
	i = -1;
	while (++i <= (size_haystack - size_needle))
		if (!ft_strncmp(str + i, to_find, size_needle))
			return ((char *)(str + i));
	return (NULL);
}
