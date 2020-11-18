/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:02:50 by jgilfix           #+#    #+#             */
/*   Updated: 2019/06/25 20:57:07 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	DESCRIPTION:	lexicographically compares the null-terminated strings `s1`
**					and `s2`.
**
**	PARAMS:			1.	`s1` : string 1
**					2.	`s2` : string 2
**
**	RETURN VALUE:	returns an integer representing the difference (`s1` - `s2`)
**					between the first differing characters in `s1` and `s2`
**
**	LIBC FUNCTIONS:	N/A
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((int)((unsigned char)*s1 - (unsigned char)*s2));
}
