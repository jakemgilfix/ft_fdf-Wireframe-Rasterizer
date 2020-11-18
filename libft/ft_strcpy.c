/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 23:55:17 by jgilfix           #+#    #+#             */
/*   Updated: 2019/07/22 21:21:59 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	DESCRIPTION:	copies the string `src` to `dest` (including the terminating
**					'\0' character).
**					The source and destination strings should not overlap; if
**					they do, the behavior is undefined.
**
**	PARAMS:			1.	`dest` : destination string
**					2.	`src`  : source string
**
**	RETURN VALUE:	returns `dest`
**
**	LIBC FUNCTIONS:	N/A
*/

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
