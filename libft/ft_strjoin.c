/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:42:33 by jgilfix           #+#    #+#             */
/*   Updated: 2019/06/21 22:22:03 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	allocates and returns a "fresh" string ending with '\0'
**					resulting from the concatenation of `s1` and `s2`. If the
**					allocation fails, the function returns NULL.
**
**	PARAMS:			1.	`s1` : string 1
**					2.	`s2` : string to add to the end of `s1`
**
**	RETURN VALUE:	returns the resulting concatenated string.
**
**	LIBC FUNCTIONS:	malloc() [via ft_strnew()]
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;

	if (!s1 || !s2 || !(result = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(result, s1);
	ft_strcat(result, s2);
	return (result);
}
