/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 20:10:31 by jgilfix           #+#    #+#             */
/*   Updated: 2019/06/21 22:08:43 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	allocates and returns a "fresh" string ending with '\0'.
**					Each character of the string is initialized to '\0'. If the
**					allocation fails, function returns NULL.
**
**	PARAMS:			1.	`size` : length of string (not including terminating \0)
**
**	RETURN VALUE:	returns the string allocated and initialized to '\0'.
**
**	LIBC FUNCTIONS:	malloc() [via ft_memalloc()]
*/

char	*ft_strnew(size_t size)
{
	return ((char *)ft_memalloc(size + 1));
}
