/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:30:41 by jgilfix           #+#    #+#             */
/*   Updated: 2019/07/01 17:17:32 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
**	DESCRIPTION:	writes the character `c` to the specified file.
**
**	PARAMS:			1.	`c`  : character to write
**					2.  `fd` : file descriptor
**
**	RETURN VALUE:	N/A
**
**	LIBC FUNCTIONS:	write()
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, (unsigned char *)&c, 1);
}
