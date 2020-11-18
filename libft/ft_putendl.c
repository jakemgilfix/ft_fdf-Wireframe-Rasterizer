/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:15:01 by jgilfix           #+#    #+#             */
/*   Updated: 2019/06/19 21:18:56 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	writes the string `str` to the 'stdout' output stream,
**					followed by a newline.
**
**	PARAMS:			1.	`str` : string to write to standard output
**
**	RETURN VALUE:	N/A
**
**	LIBC FUNCTIONS:	write()
*/

void	ft_putendl(char const *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}
