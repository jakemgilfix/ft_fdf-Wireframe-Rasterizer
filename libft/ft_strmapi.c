/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:19:37 by jgilfix           #+#    #+#             */
/*   Updated: 2019/06/21 22:16:08 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	applies the function `f` to each character of the string
**					given as argument to create a "fresh" new string resulting
**					from the successive applications of `f`, passing the index
**					within `s` as first argument to `f`.
**
**	PARAMS:			1.	`s` : string to apply `f` to
**					2.	`f` : function to apply to string `s`
**
**	RETURN VALUE:	N/A
**
**	LIBC FUNCTIONS:	malloc() [via ft_memalloc()]
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	if (!s || !(result = ft_memalloc(ft_strlen((char *)s) + 1)))
		return (NULL);
	i = 0;
	while (s[i++])
		result[i - 1] = f(i - 1, s[i - 1]);
	return (result);
}
