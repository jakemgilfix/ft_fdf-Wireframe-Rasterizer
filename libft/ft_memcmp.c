/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 23:42:23 by jgilfix           #+#    #+#             */
/*   Updated: 2019/05/14 23:49:42 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	returns zero if the two strings are identical; otherwise,
**					returns the difference between the first two differing bytes
**					(treated as unsigned char values). Zero-length strings are
**					always identical. Portable code should only depend on the
**					SIGN of the returned value.
**
**	PARAMS:			1.	`s1` : string 1
**					2.	`s2` : string 2
**					3.	`n`  : how many bytes of `s1` and `s2` to compare
**
**	RETURN VALUE:	returns difference between first two differing bytes in
**					`s1` and `s2` (i.e., *s1-*s2)
**
**	LIBC FUNCTIONS:	N/A
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	while ((i < n) && (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]))
		i++;
	return ((i == n) ? 0 :
			(int)(((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]));
}
