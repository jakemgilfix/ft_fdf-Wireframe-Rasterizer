/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 00:27:24 by jgilfix           #+#    #+#             */
/*   Updated: 2019/05/15 00:35:21 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	DESCRIPTION:	locates the last occurence of `c` (converted to a char) in
**					the string `s`. The terminating '\0' character is considered
**					part of the string; therefore, if `c` is '\0', this will
**					locate the terminating '\0'.
**
**	PARAMS:			1.	`s` : string to search
**					2.	`c` : character to search for in `s`
**
**	RETURN VALUE:	returns a pointer to the located character, or NULL if the
**					character does not appear in the string.
**
**	LIBC FUNCTIONS:	N/A
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = (char *)0;
	while (*s)
		if (*s++ == c)
			last = (char *)(s - 1);
	if (last)
		return (last);
	return ((!c) ? (char *)s : (char *)0);
}
