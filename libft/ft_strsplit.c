/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 18:40:51 by jgilfix           #+#    #+#             */
/*   Updated: 2019/07/22 21:14:10 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	Allocates and returns an array of "fresh" strings (ending
**					w/ '\0') obtained by splitting the string `str` using the
**					character `c` as a delimiter. If the allocation fails, the
**					function returns NULL.
**
**	PARAMS:			1.	`str` : string to split
**					2.  `c`   : delimiter
**
**	RETURN VALUE:	Returns list of "words" in `str`
**
**	LIBC FUNCTIONS:	malloc(), free()[?]
*/

char	**ft_strsplit(char const *s, char c)
{
	char lol[2];

	lol[0] = c;
	lol[1] = '\0';
	return (ft_split(s, lol));
}
