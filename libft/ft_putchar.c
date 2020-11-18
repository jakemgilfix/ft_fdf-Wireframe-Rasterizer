/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 21:51:29 by jgilfix           #+#    #+#             */
/*   Updated: 2019/07/01 17:17:16 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
**	DESCRIPTION:	writes the character `c` to the 'stdout' output stream.
**
**	PARAMS:			1.	`c` : character to write
**
**	RETURN VALUE:	N/A
**
**	LIBC FUNCTIONS:	write()
*/

void	ft_putchar(char c)
{
	write(1, (unsigned char *)&c, 1);
}
