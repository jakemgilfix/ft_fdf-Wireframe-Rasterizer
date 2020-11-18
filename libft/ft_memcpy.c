/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 23:21:24 by jgilfix           #+#    #+#             */
/*   Updated: 2019/08/13 15:53:49 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	copies `n` bytes from memory area `src` to memory area
**					`dest`. If `dest` and `src` overlap, behavior is undefined;
**					such applications should instead use ft_memmove().
**
**	PARAMS:			1.	`dest` : destination memory area
**					2.	`src`  : source memory area
**					3.	`n`    : how many bytes to copy from `src` to `dest`
**
**	RETURN VALUE:	returns original value of `dest`
**
**	LIBC FUNCTIONS:	N/A
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned char		*s;
	unsigned long long	*d_l;
	unsigned long long	*s_l;

	if (!dest || !src)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n % 8)
	{
		n--;
		*d++ = *s++;
	}
	d_l = (unsigned long long *)d;
	s_l = (unsigned long long *)s;
	while (n)
	{
		n -= 8;
		*d_l++ = *s_l++;
	}
	return (dest);
}
