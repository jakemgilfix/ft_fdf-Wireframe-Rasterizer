/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:55:36 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 09:17:02 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	allocates and returns a copy of the string given as
**					argument without whitespaces (' ', '\n', '\t') at the
**					beginning or end of the string. If `s` has no whitespaces
**					at the beginning or end, function returns a copy of `s`. If
**					the allocation fails, the function returns NULL.
**
**	PARAMS:			1.	`s` : string to trim
**
**	RETURN VALUE:	returns a copy of the (trimmed) string
**
**	LIBC FUNCTIONS:	malloc() [via ft_strnew()]
*/

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	end;

	if (!s)
	{
		ft_error(ERROR_NULL_PTR);
		return (NULL);
	}
	start = 0;
	while ((s[start] == ' ') || (s[start] == '\n') || (s[start] == '\t'))
		start++;
	end = ft_strlen(s);
	if (end == start)
		return (ft_strnew(1));
	while (end &&
		((s[end - 1] == ' ') || (s[end - 1] == '\n') || (s[end - 1] == '\t')))
		end--;
	return (ft_strsub(s, start, end - start));
}
