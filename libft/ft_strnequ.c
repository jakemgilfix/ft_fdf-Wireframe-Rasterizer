/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:31:44 by jgilfix           #+#    #+#             */
/*   Updated: 2019/06/21 22:19:05 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	lexicographical comparison between `s1` and `s2`, up to `n`
**					characters or until '\0' is reached. If the two strings are
**					identical, function returns 1; otherwise, 0.
**
**	PARAMS:			1.	`s1` : first string to compare
**					2.	`s2` : second string to compare
**
**	RETURN VALUE:	N/A
**
**	LIBC FUNCTIONS:	N/A
*/

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	return ((!s1 || !s2 || ft_strncmp(s1, s2, n)) ? 0 : 1);
}
