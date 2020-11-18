/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:21:12 by jgilfix           #+#    #+#             */
/*   Updated: 2019/04/30 20:21:57 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	DESCRIPTION:	tests for any character which is printable. The value of
**					the argument must be representable as an unsigned char OR
**                  the value of `EOF`
**
**	PARAMS:			1.	`c` : character to test
**
**	RETURN VALUE:	returns zero if the character tests false and non-zero
**					otherwise
**
**	LIBC FUNCTIONS:	N/A
*/

int	ft_isprint(int c)
{
	return ((c >= ' ') && (c <= '~'));
}
