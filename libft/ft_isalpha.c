/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <jgilfix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:07:21 by jgilfix           #+#    #+#             */
/*   Updated: 2019/12/12 09:13:08 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	tests for any character which is alphabetical. The value of
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

int	ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}
