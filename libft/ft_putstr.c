/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 21:54:51 by jgilfix           #+#    #+#             */
/*   Updated: 2019/07/23 12:38:04 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
**	DESCRIPTION:	writes the string `str` to the 'stdout' output stream.
**
**	PARAMS:			1.	`str` : string to write to standard output
**
**	RETURN VALUE:	N/A
**
**	LIBC FUNCTIONS:	write()
*/

void	ft_putstr(char const *str)
{
	if (!str)
		return (ft_error(ERROR_NULL_PTR));
	write(1, (char *)str, ft_strlen(str));
}
