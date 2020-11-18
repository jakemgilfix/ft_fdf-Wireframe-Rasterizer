/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:58:11 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 09:24:09 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	computes the length of string `str`.
**
**	PARAMS:			1.	`str` : string to compute length of
**
**	RETURN VALUE:	returns length of string `str` (i.e., the index of the
**					terminating '\0' character)
**
**	LIBC FUNCTIONS:	N/A
*/

size_t	ft_strlen(const char *str)
{
	const char	*ptr;

	ptr = str;
	while (*ptr)
		ptr++;
	return ((size_t)(ptr - str));
}
