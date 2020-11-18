/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:22:50 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 09:13:35 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	converts a lower-case letter to the corresponding upper-
**					case letter. The argument must be representable as an
**					unsigned char OR the value of `EOF`.
**
**	PARAMS:			1.	`c` : character to convert
**
**	RETURN VALUE:	if the argument is a lower-case letter, returns the corre-
**					sponding upper-case letter; otherwise, the argument is re-
**					turned unchanged.
**
**	LIBC FUNCTIONS:	N/A
*/

int	ft_toupper(int c)
{
	return ((ft_islower(c)) ? c - 'a' + 'A' : c);
}
