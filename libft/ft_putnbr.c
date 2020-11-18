/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 21:55:58 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 09:28:41 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	writes the number `nb` to the 'stdout' output stream.
**
**	PARAMS:			1.	`nb` : integer representation of the number to write
**						to standard output
**
**	RETURN VALUE:	N/A
**
**	LIBC FUNCTIONS:	write() [via putchar() calls]
*/

void	ft_putnbr(int n)
{
	unsigned int	num;

	num = (unsigned int)ft_abs(n);
	if (n < 0)
		ft_putchar('-');
	if (num > 9)
		ft_putnbr((int)(num / 10));
	ft_putchar((int)(num % 10) + '0');
}
