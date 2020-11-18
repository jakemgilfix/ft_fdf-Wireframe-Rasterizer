/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 19:45:49 by jgilfix           #+#    #+#             */
/*   Updated: 2019/07/19 01:46:32 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	writes `n` zeroed bytes to the string `str`. If n is zero,
**					ft_bzero() does nothing.
**
**	PARAMS:			1.	`str` : string to zero out
**					2.	`n`   : how many bytes in `str` to zero out
**
**	RETURN VALUE:	N/A
**
**	LIBC FUNCTIONS:	N/A
*/

void	ft_bzero(void *str, size_t n)
{
	(void)ft_memset(str, 0, n);
}
