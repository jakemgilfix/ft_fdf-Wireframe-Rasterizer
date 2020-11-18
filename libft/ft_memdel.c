/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilfix <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 20:08:50 by jgilfix           #+#    #+#             */
/*   Updated: 2019/06/14 20:10:25 by jgilfix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	DESCRIPTION:	Takes as a parameter the address of a memory area that needs
**					to be freed, then sets the pointer to NULL.
**
**	PARAMS:			1.	`ap` : pointer to memory area
**
**	RETURN VALUE:	N/A
**
**	LIBC FUNCTIONS:	free()
*/

void	ft_memdel(void **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
