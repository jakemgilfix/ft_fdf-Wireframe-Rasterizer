/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:14:17 by jgilfix           #+#    #+#             */
/*   Updated: 2019/04/30 20:19:24 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	DESCRIPTION:	tests for any character which is an ASCII character. The
**					value of the argument must be representable as an unsigned
**					char OR the value of `EOF`.
**
**	PARAMS:			1.	`c` : character to test
**
**
**	RETURN VALUE:	returns zero if the character tests false and non-zero
**					otherwise
**
**	LIBC FUNCTIONS:	N/A
*/

int	ft_isascii(int c)
{
	return ((c >= 0) && (c < 128));
}
