/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:23:18 by jgilfix           #+#    #+#             */
/*   Updated: 2019/07/01 17:08:56 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	lexicographical comparison between `s1` and `s2`. If the 2
**					strings are identical, the function returns 1; otherwise,
**					it returns 0.
**
**	PARAMS:			1.	`s1` : first string to compare
**					2.	`s2` : second string to compare
**
**	RETURN VALUE:	1 or 0, depending on lexicographical comparison
**
**	LIBC FUNCTIONS:	N/A
*/

int	ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
	{
		ft_error(ERROR_NULL_PTR);
		return (-1);
	}
	while (s1 && s2 && *s1 && *s2)
		if (*s1++ != *s2++)
			return (0);
	return (*s1 == *s2);
}
