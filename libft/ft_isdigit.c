/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:11:20 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 09:11:48 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	tests for any character which is a decimal digit. The value
**					of the argument must be representable as an unsigned char OR
**                  the value of `EOF`.
**
**	PARAMS:			1.	`c` : character to test
**
**	RETURN VALUE:	returns zero if the character tests false and non-zero
**					otherwise
**
**	LIBC FUNCTIONS:	N/A
*/

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
