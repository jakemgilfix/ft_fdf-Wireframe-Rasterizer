/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:30:31 by jgilfix           #+#    #+#             */
/*   Updated: 2019/07/23 12:38:16 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
**	DESCRIPTION:	writes the string `str` to the 'stdout' output stream.
**
**	PARAMS:			1.	`str` : string to write to specified file
**					2.  `fd`  : file descriptor
**
**	RETURN VALUE:	N/A
**
**	LIBC FUNCTIONS:	write()
*/

void	ft_putstr_fd(char const *str, int fd)
{
	if (!str)
		return (ft_error(ERROR_NULL_PTR));
	write(fd, (char *)str, ft_strlen(str));
}
