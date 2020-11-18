/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 23:17:05 by jgilfix           #+#    #+#             */
/*   Updated: 2019/07/23 12:56:51 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	lexicographically compares NOT MORE THAN `n` CHARACTERS of
**					the null-terminated strings `s1` and `s2`.
**
**	PARAMS:			1.	`s1` : string 1
**					2.	`s2` : string 2
**					3.	`n`  : maximum number of character pairs to compare
**
**	RETURN VALUE:	returns an integer representing the difference (`s1` - `s2`)
**					between the first differing characters in `s1` and `s2`
**
**	LIBC FUNCTIONS:	N/A
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (!s1 || !s2)
	{
		ft_error(ERROR_NULL_PTR);
		return (-1);
	}
	if (!n)
		return (0);
	i = 0;
	while (s1[i] && (s1[i] == s2[i]) && (i < (n - 1)))
		i++;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
