/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:24:04 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 09:13:27 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	converts an upper-case letter to the corresponding lower-
**					case letter. The argument must be representable as an
**					unsigned char OR the value of `EOF`.
**
**	PARAMS:			1.	`c` : character to convert
**
**	RETURN VALUE:	if the argument is an upper-case letter, returns the corre-
**					sponding lower-case letter; otherwise, the argument is re-
**					turned unchanged.
**
**	LIBC FUNCTIONS:	N/A
*/

int	ft_tolower(int c)
{
	return ((ft_isupper(c)) ? c - 'A' + 'a' : c);
}
