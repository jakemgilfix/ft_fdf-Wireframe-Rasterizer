/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:34:04 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 09:28:52 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	writes the number `nb` to the 'stdout' output stream.
**
**	PARAMS:			1.	`nb` : integer representation of the number to write
**						to specified file
**					2.  `fd` : file descriptor
**
**	RETURN VALUE:	N/A
**
**	LIBC FUNCTIONS:	write() [via putchar_fd() calls]
*/

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	num = (unsigned int)ft_abs(n);
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (num > 9)
		ft_putnbr_fd((int)(num / 10), fd);
	ft_putchar_fd((int)(num % 10) + '0', fd);
}
