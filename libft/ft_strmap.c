/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:15:29 by jgilfix           #+#    #+#             */
/*   Updated: 2019/06/21 22:15:31 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	applies the function `f` to each character of the string
**					given as argument to create a "fresh" new string resulting
**					from the successive applications of `f`.
**
**	PARAMS:			1.	`s` : string to apply `f` to
**					2.	`f` : function to apply to string `s`
**
**	RETURN VALUE:	N/A
**
**	LIBC FUNCTIONS:	malloc() [via ft_memalloc()]
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	char	*ptr2;
	char	*result;

	if (!s || !(result = ft_memalloc(ft_strlen((char *)s) + 1)))
		return (NULL);
	ptr = (char *)s;
	ptr2 = result;
	while (*ptr)
		*ptr2++ = f(*ptr++);
	return (result);
}
