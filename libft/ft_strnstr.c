/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 23:11:29 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 09:39:45 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	locates the first occurence of the null-terminated string
**					`to_find` in the null-terminated string `str`, where not
**					more than `n` characters are searched. Characters that
**					appear after a '\0' character are not searched.
**
**	PARAMS:			1.	`str`     : string to search
**					2.	`to_find` : substring to search for within `str`
**					3.	`n`		  : maximum search distance
**
**	RETURN VALUE:	if `to_find` is an empty string, `str` is returned; if
**					`to_find` occurs nowhere in `str`, NULL is returned; else
**					a pointer to the first character in the first occurence
**					of `to_find` is returned.
**
**	LIBC FUNCTIONS:	N/A
*/

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	int	size_needle;
	int	size_haystack;
	int i;
	int j;

	if (!str || !to_find)
		return (NULL);
	size_needle = ft_strlen(to_find);
	size_haystack = ft_strlen(str);
	if (!size_needle)
		return ((char *)str);
	i = -1;
	while (++i <= ft_int_min((int)n, (size_haystack - size_needle)))
	{
		j = -1;
		while (++j < size_needle && ((i + j) < (int)n))
		{
			if (to_find[j] != str[i + j])
				break ;
			if (j == (size_needle - 1))
				return ((char *)(str + i));
		}
	}
	return (0);
}
